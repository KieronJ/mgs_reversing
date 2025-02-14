#ifndef _STGFD_IO_
#define _STGFD_IO_

#include <SYS/TYPES.H>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include "libgv/libgv.h"

typedef struct Actor_stgfd_io_0x30
{
    DR_TPAGE field_0_dr_tpage[2];
    TILE     field_10_tile[2];
} Actor_stgfd_io_0x30;

typedef struct Actor_stgfd_io
{
    Actor                field_0_actor;
    Actor_stgfd_io_0x30 *field_20_pAlloc0x30;
    int                  field_24;
    int                  field_28;
    SVECTOR              field_2C;
    SVECTOR              field_34;
    int                  field_3C_state;
} Actor_stgfd_io;

void stgfd_io_act_80074F5C(Actor_stgfd_io *pActor);
void stgfd_io_kill_80075164(Actor_stgfd_io *pActor);
int  stgfd_io_loader_80075194(Actor_stgfd_io *pActor);

#endif // _STGFD_IO_
