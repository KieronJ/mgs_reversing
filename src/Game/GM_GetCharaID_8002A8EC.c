#include "linker.h"
#include "libgcl/gcl.h"
#include "game.h"

extern GCL_Vars           gGcl_vars_800B3CC8;

extern GCL_ActorTableEntry MainCharacterEntries_8009D2DC[];

extern short gGameState_800B4D98[0x60];
extern short gGcl_gameStateVars_800B44C8[0x60];

unsigned char *SECTION(".sbss") gOverlayBase_800AB9C8; // resident memory base ?

TGCL_ActorCreateFn GM_GetChara_8002A8C4(unsigned char *pScript)
{
    return GM_GetCharaID_8002A8EC(GCL_GetNextInt_800209E8(pScript));
}

TGCL_ActorCreateFn GM_GetCharaID_8002A8EC(int chara_id)
{
    GCL_ActorTableEntry *pSrcTable;
    int                  i = 0;
    do
    {
        // First search the fixed set of commands
        pSrcTable = &MainCharacterEntries_8009D2DC[0];
        if (i != 0)
        {
            // Then look at the dynamically loaded commands
            pSrcTable = (GCL_ActorTableEntry *)gOverlayBase_800AB9C8; // TODO: Fix type
        }

        if (pSrcTable->function)
        {
            do
            {
                if (pSrcTable->hashCode == chara_id)
                {
                    return pSrcTable->function;
                }
                pSrcTable++;
            } while (pSrcTable->function);
        }
        i++;
    } while (i < 2);

    return 0;
}

void GM_ClearWeaponAndItem_8002A960()
{
    gGameState_800B4D98[GM_CurrentWeapon] = WEAPON_NONE;
    gGameState_800B4D98[GM_CurrentItem] = WEAPON_NONE;
}
