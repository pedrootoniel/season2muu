#include "stdafx.h"
#include "objectstruct.h"
#include "packets.h"

void  gObjLotteryItemMix(OBJECTSTRUCT* lpObj);
void  gObjGCLevelUpMsgSend(int aIndex, int iSendEffect);
BOOL  gObjgObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo);
void  gObjGameMonsterAllAdd();
short gObjInsertMonster(int Map, int X, int Y, int Class, int Dir, int Type);
void  gObjSavePetItemInfo(int aIndex, int inventype);
int   gObjDrop(LPOBJ lpObj, LPOBJ lpTargetObj);
void  gObjJGAnsMapSvrAuth(PMSG_ANS_MAPSVRAUTH * lpRecv);

__declspec() void gObjItemDrop();
__declspec() void gObjSoulRateLuck();
__declspec() void gObjSoulRateNoLuck();
__declspec() void gObjLifeRate();
__declspec() void gObjElfSoldier();
__declspec() void gObjRateMixLevel();
__declspec() void gObjGMGlobalMsg();
__declspec() void gObjZen();