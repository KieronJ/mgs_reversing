#include "linker.h"
#include "libgcl/gcl.h"
#include "Game/game.h"

extern int GM_LoadRequest_800AB3D0;

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

int GCL_Command_strstatus_8002C6A4(int argc, char **argv)
{
    int val;

    if (GCL_GetParam_80020968('p'))
    {
        val = GCL_GetNextParamValue_80020AD4();
    }
    else
    {
        val = -1;
    }
    sub_8002B600(val);
    if (GCL_GetParam_80020968('s'))
    {
        GM_LoadRequest_800AB3D0 |= GAME_FLAG_BIT_05;
    }
    if (GCL_GetParam_80020968('a')) // area
    {
        GM_SetArea_8002A7D8(gGameState_800B4D98[GM_CurrentStage], GM_GetArea_8002A880(0));
    }
    return 0;
}
