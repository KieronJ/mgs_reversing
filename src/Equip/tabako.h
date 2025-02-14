#ifndef _TABAKO_H_
#define _TABAKO_H_

#include "libgv/libgv.h"
#include "libdg/libdg.h"
#include "Game/GM_Control.h"
#include "Game/game.h"

// cigarettes

typedef struct _Actor_tabako
{
    Actor       field_0_actor;
    OBJECT      field_20_obj;
    GM_Control *field_44_pCtrl;
    OBJECT     *field_48_pParent;
    int         field_4C_numParent;
    DG_PRIM    *field_50_pPrims;
    SVECTOR     field_54_vec;
    RECT        field_5C_rect;
} Actor_tabako;

void tabako_act_80061EAC(Actor_tabako *pActor);
void tabako_kill_8006206C(Actor_tabako *pActor);
int  tabako_loader_800620B4(Actor_tabako *pActor, OBJECT *pParent, int numParent);

#endif // _TABAKO_H_
