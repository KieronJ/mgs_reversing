#include "linker.h"
#include "libgcl/gcl.h"
#include "psyq.h"

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

int GCL_Command_rand_8002CD94(int argc, char **argv)
{
    int param;
    int rand;

    param = GCL_GetNextParamValue_80020AD4();
    rand = rand_8008E6B8();
    gGameState_800B4D98[GM_LastResult] = (short)(rand % param);
    return 0;
}
