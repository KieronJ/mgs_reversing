#include "psyq.h"
#include "gcl.h"

extern GCL_Vars gGcl_vars_800B3CC8;

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

void GCL_InitClearVar_800212CC()
{
    gGcl_vars_800B3CC8 = ( GCL_Vars ){{ 0 }};
    memset(&gGameState_800B4D98[GM_CurrentStage], 0, 0xb4);
    GCL_SaveVar_80021314();
}
