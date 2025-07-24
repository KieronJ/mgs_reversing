// This module isn't linked into CD-ROM builds, as it's an alternate
// implementation of fscd.c for hard disk builds (only used in development
// and the Win32 port by Digital Dialect).
//
// I'm assuming conditional compilation in select.c determines whether
// FS_CDInit or FS_HDInit is called by FS_StartDaemon and thus the linker
// discards either fshd.obj or fscd.obj, respectively.
//
// It's known to contain the following public functions:
// -------------------------------------------------------------
// FS_LoadFileRequest
// FS_LoadFileSync
// FS_HDInit
//
// NOTE: These labels were recovered from a memleak'd linker map fragment.
//       Symbols were listed by address order, which is reflected above.
//

#include "libfs.h"

#include <stdio.h>
#include <stdlib.h>
#include <libsn.h>

#include "file.cnf"     // defines fs_file_info

void FS_LoadFileRequest( int fileno, int offset, int size, void *buffer )
{
    printf("FS_LoadFileRequest unimplemented!\n");
}

int FS_LoadFileSync( void )
{
    /* loading is instant in hd mode  */
    return 0;
}

void FS_HDInit( void )
{
    PCinit();
    printf("Metal Gear Solid FileSystem ( HD ) Init.\n");
}

void MakeFullPath(int name, char *buffer)
{
    /* do nothing */
}
