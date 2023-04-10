#include "linker.h"
#include "game.h"
#include "control.h"
#include "libgv/libgv.h"
#include "unknown.h"

extern MATRIX dword_8009DE9C;
extern short  dword_8009D69C[15][64]; // TODO: reformat this array in data.c

void sub_80034EAC(SVECTOR *pVec)
{
    pVec->vx = FP_Extend(pVec->vx);
    pVec->vy = FP_Extend(pVec->vy);
    pVec->vz = FP_Extend(pVec->vz);
}

int GM_ConfigMotionControl_80034F08(OBJECT *pObj, MOTION_CONTROL *pMCtrl, int name, OAR_RECORD *a4, OAR_RECORD *a5,
                                    CONTROL *pCtrl, SVECTOR *rots)
{
    pMCtrl->field_00_oar = GV_GetCache_8001538C(GV_CacheID_800152DC(name, 'o'));
    pMCtrl->field_3C = &pObj->field_18;
    pMCtrl->field_04_info1.field_0 = 0;
    pMCtrl->field_04_info1.field_2_footstepsFrame = 0;
    pMCtrl->field_04_info1.field_4 = 0;
    pMCtrl->field_04_info1.field_8 = 0;
    pMCtrl->field_04_info1.field_C_oar_records = a4;
    pMCtrl->field_04_info1.field_10 = 0;
    pMCtrl->field_04_info1.field_12 = 0;
    pMCtrl->field_04_info1.field_14 = 0;
    pMCtrl->field_04_info1.field_16_time = 0;
    pMCtrl->field_1C_info2.field_0 = 0;
    pMCtrl->field_1C_info2.field_2_footstepsFrame = 0;
    pMCtrl->field_1C_info2.field_4 = 0;
    pMCtrl->field_1C_info2.field_8 = -1;
    pMCtrl->field_1C_info2.field_10 = 0;
    pMCtrl->field_1C_info2.field_12 = 0;
    pMCtrl->field_1C_info2.field_14 = 0;
    pMCtrl->field_1C_info2.field_16_time = 0;
    pMCtrl->interp = 0;
    pMCtrl->field_4C = rots;
    pMCtrl->field_34 = &pCtrl->field_8_rotator;
    pMCtrl->step = &pCtrl->field_44_movementVector;
    pMCtrl->field_1C_info2.field_C_oar_records = a5;
    pObj->objs->rots = rots;
    pObj->objs->waist_rot = &pMCtrl->field_44;
    pObj->m_ctrl = pMCtrl;
    return 0;
}

int GM_ConfigMotionAdjust_80035008(OBJECT *pObj, SVECTOR *adjust)
{
    pObj->objs->adjust = adjust;
    return 0;
}

void sub_8003501C(MOTION_CONTROL *pCtrl, int action_flag, int motion)
{
    MOTION_INFO *pInfo;
    MATRIX       mtx;

    ReadRotMatrix_80092DD8(&mtx);

    pInfo = &pCtrl->field_04_info1;
    if (pInfo->field_0)
    {
        sub_8003603C(pCtrl, pInfo);
    }

    if (!motion)
    {
        Process_Oar_8003518C(pCtrl, pInfo, action_flag);
    }
    else
    {
        sub_800360EC(pCtrl, pInfo, action_flag, motion);
    }

    if (pInfo->field_0 == 1)
    {
        pInfo->field_14 = 2;
        pInfo->field_10 = action_flag;
    }
    else
    {
        pInfo->field_14 = 1;
        pInfo->field_10 = action_flag;
    }

    SetRotMatrix_80093218(&mtx);
}

void sub_800350D4(MOTION_CONTROL *pCtrl, int a2, int a3)
{
    MOTION_INFO *pInfo;
    MATRIX       mtx;

    ReadRotMatrix_80092DD8(&mtx);

    pInfo = &pCtrl->field_1C_info2;
    if (pInfo->field_0)
    {
        sub_8003603C(pCtrl, pInfo);
    }

    if (!a3)
    {
        Process_Oar_8003518C(pCtrl, pInfo, a2);
    }
    else
    {
        sub_800360EC(pCtrl, pInfo, a2, a3);
    }

    if (pInfo->field_0 == 1)
    {
        pInfo->field_14 = 2;
        pInfo->field_10 = a2;
    }
    else
    {
        pInfo->field_14 = 1;
        pInfo->field_10 = a2;
    }

    SetRotMatrix_80093218(&mtx);
}

#pragma INCLUDE_ASM("asm/Game/Process_Oar_8003518C.s") // 600 bytes
#pragma INCLUDE_ASM("asm/Game/Kmd_Oar_Inflate_800353E4.s") // 392 bytes

int sub_8003556C(MOTION_CONTROL *m_ctrl)
{
    MATRIX       mtx;
    MOTION_INFO *m_info;
    int          time;

    ReadRotMatrix_80092DD8(&mtx);

    m_ctrl->step->vx = 0;
    m_ctrl->step->vz = 0;

    m_info = &m_ctrl->field_04_info1;
    if (m_info->field_14 != 0)
    {
        time = oar_related_800356FC(m_ctrl, m_info);

        if (time == -1)
        {
            if (m_info->field_14 & 1)
            {
                Process_Oar_8003518C(m_ctrl, m_info, m_info->field_10);
            }

            if (m_info->field_14 & 2)
            {
                if (m_ctrl->interp != 0)
                {
                    Process_Oar_8003518C(m_ctrl, m_info, m_info->field_10);
                }
                else
                {
                    m_info->field_14 = 0;
                }
            }

            time = 0;
        }

        m_info->field_16_time = time;
    }

    m_info = &m_ctrl->field_1C_info2;
    if (m_info->field_14 != 0)
    {
        time = oar_related_800356FC(m_ctrl, m_info);

        if (time == -1)
        {
            if (m_info->field_14 & 1)
            {
                Process_Oar_8003518C(m_ctrl, m_info, m_info->field_10);
            }

            if (m_info->field_14 & 2)
            {
                if (m_ctrl->interp != 0)
                {
                    Process_Oar_8003518C(m_ctrl, m_info, m_info->field_10);
                }
                else
                {
                    m_info->field_14 = 0;

                    if (m_ctrl->field_04_info1.field_14 == 0)
                    {
                        m_ctrl->field_04_info1.field_14 = 2;
                    }
                }
            }

            time = 0;
        }

        m_info->field_16_time = time;
    }

    SetRotMatrix_80093218(&mtx);
    return time;
}

#pragma INCLUDE_ASM("asm/Game/oar_related_800356FC.s") // 2104 bytes

void sub_80035F34(OAR_RECORD *pRecord, SVECTOR *pResult)
{
    int iVar1;

    iVar1 = pRecord->field_10 * (pRecord->field_1A - pRecord->field_18);
    iVar1 >>= 10;

    if (iVar1 != 64)
    {
        iVar1 = dword_8009D69C[pRecord->field_1C][iVar1];
    }
    else
    {
        iVar1 = 4096;
    }

    dword_8009DE9C.m[0][0] = iVar1;
    dword_8009DE9C.m[1][1] = iVar1;
    dword_8009DE9C.m[2][2] = iVar1;

    gte_SetRotMatrix(&dword_8009DE9C);
    gte_ldv0(&pRecord->field_8);
    gte_rtv0();
    gte_stsv(pResult);
}

void sub_80035FFC(MOTION_CONTROL *pCtrl)
{
    sub_8003603C(pCtrl, &pCtrl->field_04_info1);
}

void sub_8003601C(MOTION_CONTROL *pCtrl)
{
    sub_8003603C(pCtrl, &pCtrl->field_1C_info2);
}

void sub_8003603C(MOTION_CONTROL *pCtrl, MOTION_INFO *pInfo)
{
    SVECTOR     vec;
    OAR_RECORD *pRecord;
    int         numRecords;
    int         i;

    pRecord = pInfo->field_C_oar_records;
    pRecord++;

    numRecords = pCtrl->field_00_oar->recordSize;

    pInfo->field_0 = 0;
    pInfo->field_4 = 1;

    for (i = 0; i < numRecords; i++, pRecord++)
    {
        sub_80035F34(pRecord, &vec);
        pRecord->field_0.vx += vec.vx;
        pRecord->field_0.vy += vec.vy;
        pRecord->field_0.vz += vec.vz;
    }
}

#pragma INCLUDE_ASM("asm/Game/sub_800360EC.s") // 668 bytes
#pragma INCLUDE_ASM("asm/Game/sub_80036388.s") // 816 bytes
#pragma INCLUDE_ASM("asm/Game/negate_rots_800366B8.s") // 856 bytes
