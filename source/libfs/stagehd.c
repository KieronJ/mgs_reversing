#include "libfs.h"
#include "datacnf.h"

#include <stdio.h>
#include <string.h>
#include <libsn.h>

#include "common.h"
#include "libgv/libgv.h"
#include "libdg/libdg.h"    // for DG_FrameRate
#include "sound/sd_cli.h"

#define P2ALIGN( x, a ) ( ( ( x ) + ( ( a ) - 1 ) ) & ~( ( a ) - 1) )

enum FS_ConfigSection
{
    CONFIG_SECTION_NONE,
    CONFIG_SECTION_CACHE,
    CONFIG_SECTION_NOCACHE,
    CONFIG_SECTION_RESIDENT,
    CONFIG_SECTION_SOUND,
};

extern int   FS_StageLoadStart;
extern int   FS_ReloadResident;
extern void *StageCharacterEntries;

STATIC int FS_ConfigSection = CONFIG_SECTION_NONE;

/*---------------------------------------------------------------------------*/

STATIC int FS_LoadStageFile( char *filename, void *buffer, int *sizep )
{
    int fd;
    int size;

    printf( "loading pcdrv:/%s...\n", filename );

    fd = PCopen( filename, 0, 0 );
    if ( fd < 0 )
    {
        printf( "FS_LoadStageFile: unable to open %s!\n", filename );
        return 1;
    }

    size = PClseek( fd, 0, SEEK_END );
    PClseek( fd, 0, SEEK_SET );

    if ( PCread( fd, buffer, size ) < 0 )
    {
        printf( "FS_LoadStageFile: unable to read file!\n" );
        PCclose( fd );
        return 1;
    }

    *sizep = size;

    PCclose( fd );
    return 0;
}

// TODO: don't keep opening and closing the same file
STATIC int FS_LoadStageFileChunked( char *filename, void *buffer, int offset, int chunk, int *sizep )
{
    int fd;
    int size;

    printf( "loading pcdrv:/%s...\n", filename );

    fd = PCopen( filename, 0, 0 );
    if ( fd < 0 )
    {
        printf( "FS_LoadStageFileChunked: unable to open %s!\n", filename );
        return 1;
    }

    size = PClseek( fd, 0, SEEK_END );
    PClseek( fd, offset, SEEK_SET );

    if ( chunk < size - offset )
    {
        chunk = size - offset;
    }

    if ( chunk > 0 && PCread( fd, buffer, chunk ) < 0 )
    {
        printf( "FS_LoadStageFileChunked: unable to read file!\n" );
        PCclose( fd );
        return 1;
    }

    *sizep = chunk;

    PCclose( fd );
    return 0;
}

STATIC int FS_SplitFileExt( const char *filename, int *hash, int *ext )
{
    char        stem[32];
    int         i;
    const char *c;

    for ( i = 0, c = filename; *c != '\0'; i++, c++ )
    {
        if ( c[0] == '.' && c[1] != '\0' )
        {
            memcpy( stem, filename, i );
            stem[i] = '\0';

            *hash = GV_StrCode( stem );
            *ext = c[1];
            return 0;
        }
    }

    return 1;
}

STATIC int FS_LoadStageCacheFile( char *filename, void *buffer, int hash, int type )
{
    int id;
    int size;

    if ( FS_LoadStageFile( filename, buffer, &size ) )
    {
        printf( "Unable to load %s!\n", filename );
    }

    id = GV_CacheID( hash, type );
    GV_LoadInit( buffer, id, GV_INIT_CACHE );

    return size;
}

STATIC void FS_LoadStageSoundFile( char *filename, int hash, int type )
{
    void *buffer;
    int   size;
    int   offset;

    switch (type)
    {
    case 'e': // efx
        buffer = SD_SeDataLoadInit( hash );
        FS_LoadStageFile( filename, buffer, &size );
        SD_80083ED4();
        break;

    case 'm': // mdx
        buffer = SD_SngDataLoadInit( hash );
        FS_LoadStageFile( filename, buffer, &size );
        SD_80083ED4();
        break;

    case 'w':
        buffer = SD_WavDataLoadInit( hash );
        offset = 0;

        while ( size > 0 )
        {
            FS_LoadStageFileChunked( filename, buffer, offset, 0x18000, &size );
            buffer = SD_WavLoadBuf( buffer + size );
            offset += size;
        }

        SD_WavUnload();
        break;
    }
}

STATIC void FS_LoadStageArchiveFile( char *filename, void *buffer, int type )
{
    int          size;
    DARFILE_TAG *tag;
    DARFILE_TAG *end;
    int          id;
    void        *resident;

    // overlay files are handled specially
    if ( type == 'b' ) // bin
    {
#ifndef DEV_EXE
        // the overlay is embedded in the executable in dev variant
        FS_LoadStageFile( filename, StageCharacterEntries, &size );
#endif
        return;
    }

    if ( FS_LoadStageFile( filename, buffer, &size ) )
    {
        printf( "Unable to load %s!\n", filename );
    }

    tag = buffer;
    end = buffer + size;

    while ( tag < end )
    {
        id = GV_CacheID( tag->id, tag->ext );

        if ( FS_ConfigSection == CONFIG_SECTION_RESIDENT )
        {
            resident = GV_AllocResidentMemory( tag->size );
            GV_CopyMemory( tag + 1, resident, tag->size );
            GV_LoadInit( resident, id, GV_INIT_RESIDENT );
        }
        else
        {
            GV_LoadInit( tag + 1, id, GV_INIT_NOCACHE );
        }

        // flush any voided memory to avoid running out of space
        GV_ClearMemorySystem( GV_Clock );

        tag = ( DARFILE_TAG * )( ( char * )tag + sizeof( *tag ) + tag->size );
    }
}

STATIC int FS_ParseConfigLine( const char *dirname, const char *line, void *buffer )
{
    char filename[32];
    int  size;
    int  hash;
    int  type;

    // only cache files are kept in the buffer
    size = 0;

    if ( line[0] == '.' )
    {
        line++;
        switch ( *line )
        {
        case 'c':
            FS_ConfigSection = CONFIG_SECTION_CACHE;
            break;
        case 'n':
            FS_ConfigSection = CONFIG_SECTION_NOCACHE;
            break;
        case 'r':
            FS_ConfigSection = CONFIG_SECTION_RESIDENT;
            FS_ReloadResident = 1;
            break;
        case 's':
            FS_ConfigSection = CONFIG_SECTION_SOUND;
            break;
        default:
            printf( "unknown config section %s\n", line );
            break;
        }

        return size;
    }

    if ( FS_SplitFileExt( line, &hash, &type ) )
    {
        printf( "Unable to determine file type!\n" );
    }

    sprintf( filename, "stage/%s/%s", dirname, line );

    switch ( FS_ConfigSection )
    {
    case CONFIG_SECTION_CACHE:
        size = FS_LoadStageCacheFile( filename, buffer, hash, type );
        break;
    case CONFIG_SECTION_NOCACHE:
    case CONFIG_SECTION_RESIDENT:
        FS_LoadStageArchiveFile( filename, buffer, type );
        break;
    case CONFIG_SECTION_SOUND:
        FS_LoadStageSoundFile( filename, hash, type );
        break;
    }

    return size;
}

/*---------------------------------------------------------------------------*/

void *FS_LoadStageRequest( const char *dirname )
{
    char  config[32];
    char *buffer;
    char *base;
    int   size;
    char *line;

    DG_FrameRate = 1;

    printf( "load %s\n", dirname );

    FS_StageLoadStart = VSync( -1 );
    FS_ReloadResident = 0;
    FS_ConfigSection = CONFIG_SECTION_NONE;

    base = buffer = GV_GetMaxFreeMemory( GV_NORMAL_MEMORY );

    sprintf( config, "stage/%s/data.cnf", dirname );
    if ( FS_LoadStageFile( config, buffer, &size ) )
    {
        printf( "Unable to load data.cnf!\n" );
    }

    // null terminate the file contents
    buffer[size] = '\0';
    size++;

    line = strtok( buffer, "\r\n" );
    buffer += P2ALIGN(size, 4);

    while (line)
    {
        size = FS_ParseConfigLine( dirname, line, buffer );
        buffer += P2ALIGN(size, 4);
        line = strtok( NULL, "\r\n" );
    }

    // return all unused memory
    printf( ".cache used memory: %u bytes\n", buffer - base );
    GV_SplitMemory( GV_NORMAL_MEMORY, base, buffer - base );

    return (void *)1;
}

int FS_LoadStageSync( void *unused )
{
    /* loading is instant in hd mode  */
    return 0;
}

void FS_LoadStageComplete( void *unused )
{
    printf( "load complete time %d\n", VSync( -1 ) - FS_StageLoadStart );
    DG_FrameRate = 2;
}
