#include "linker.h"
#include "libgcl/gcl.h"
#include "libdg/libdg.h"
#include "psyq.h"
#include "Game/game.h"

extern int  GM_LoadRequest_800AB3D0;
extern char dword_800ABA58[8];

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

int GCL_Command_load_8002C308(int argc, char **argv)
{
    char *scriptStageName;
    SVECTOR vec;

    scriptStageName = GCL_Read_String_80020A70(GCL_Get_Param_Result_80020AA4());
    if (*scriptStageName == '\0')
    {
        GM_LoadRequest_800AB3D0 = 1;
        return 0;
    }

    if (GCL_GetParam_80020968('r'))
    {
        if (!GCL_GetNextParamValue_80020AD4())
        {
            // Hard restart?
            strcpy_8008E768(dword_800ABA58, GM_GetArea_8002A880((int)scriptStageName));
            GV_ResidentHeapReset_800163B0();
            GV_InitCacheSystem_80015458();
            DG_ClearResidentTexture_8001DB10();
            GM_SetArea_8002A7D8(GV_StrCode_80016CCC(scriptStageName), scriptStageName);
        }
        else
        {
            // Soft restart?
            scriptStageName = dword_800ABA58;
            GM_SetArea_8002A7D8(gGameState_800B4D98[GM_CurrentStage], scriptStageName);
        }

        GM_LoadRequest_800AB3D0 = 1;
        return 0;
    }

    gGameState_800B4D98[GM_PreviousStage] = gGameState_800B4D98[GM_CurrentStage];
    gGameState_800B4D98[GM_CurrentStage]  = GV_StrCode_80016CCC(scriptStageName);

    GM_SetArea_8002A7D8(gGameState_800B4D98[GM_CurrentStage], scriptStageName);

    if (GCL_GetParam_80020968('m')) // map
    {
        gGameState_800B4D98[GM_CurrentMap] = GCL_GetNextParamValue_80020AD4();
    }

    if (GCL_GetParam_80020968('p')) // pos
    {
        GCL_GetSV_80020A14(GCL_Get_Param_Result_80020AA4(), &vec);
        gGameState_800B4D98[GM_CurrentPosX] = vec.vx;
        gGameState_800B4D98[GM_CurrentPosY] = vec.vy;
        gGameState_800B4D98[GM_CurrentPosZ] = vec.vz;
    }

    if (GCL_GetParam_80020968('s'))
    {
        GM_LoadRequest_800AB3D0 = GCL_GetNextParamValue_80020AD4();
        if (GM_LoadRequest_800AB3D0)
        {
            GM_LoadRequest_800AB3D0 |= 0x80;
        }
    }
    else
    {
        GM_LoadRequest_800AB3D0 = 1;
    }

    if (!GCL_GetParam_80020968('n'))
    {
        GM_LoadRequest_800AB3D0 |= 0x10;
    }

    return 0;
}
