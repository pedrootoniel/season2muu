#include "stdafx.h"

typedef void(*pProtocolCore)(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
extern pProtocolCore ProtocolCore;

typedef void(*pProtocolCoreDS)(BYTE protoNum, unsigned char* aRecv, int aLen);
extern pProtocolCoreDS ProtocolCoreDS;

typedef void(*pLogAddFuncColor)(BYTE Color, char* szLog, ...);
extern pLogAddFuncColor LogAddFuncColor;

typedef void(*pGCServerMsgStringSend)(LPCTSTR text, int index, BYTE type);
extern pGCServerMsgStringSend GCServerMsgStringSend;

typedef int(*pDataSend)(int aIndex, unsigned char* pData, int Size);
extern pDataSend DataSend;

typedef void(*pgObjCalCharacter)(int aIndex);
extern pgObjCalCharacter gObjCalCharacter;

typedef bool(*pgObjSetCharacter)(LPBYTE lpdata, int aIndex);
extern pgObjSetCharacter gObjSetCharacter;

typedef void(*pgObjCalcMaxLifePower)(int aIndex);
extern pgObjCalcMaxLifePower gObjCalcMaxLifePower;

typedef void(*pGCStateInfoSend)(LPOBJ lpObj, BYTE state, int  ViewSkillState);
extern pGCStateInfoSend GCStateInfoSend;

typedef void(*pLotteryItemMix)(LPOBJ lpObj);
extern pLotteryItemMix LotteryItemMix;

typedef void(*pGCLevelUpMsgSend)(int aIndex, int iSendEffect);
extern pGCLevelUpMsgSend GCLevelUpMsgSend;

typedef BOOL(*pgObjAttack)(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo);
extern pgObjAttack gObjAttack;

typedef void(*pGCDamageSend)(int aIndex, int TargetIndex, int AttackDamage, int MSBFlag, int MSBDamage, int iShieldDamage);
extern pGCDamageSend GCDamageSend;

typedef int(*pgObjIsConnected)(int);
extern pgObjIsConnected gObjIsConnected;

typedef void(*pGCMoneySend)(int aIndex, DWORD money);
extern pGCMoneySend GCMoneySend;

typedef void(*pGCReFillSend)(int aIndex, WORD Life, BYTE Ipos, unsigned char flag,  WORD wShield);
extern pGCReFillSend GCReFillSend;

typedef void(*pgObjSetBP)(int aIndex);
extern pgObjSetBP gObjSetBP;

typedef void(*pGCManaSend)(int aIndex, short Mana, BYTE Ipos, unsigned char flag,  WORD BP);
extern pGCManaSend GCManaSend;

typedef void(*pGCPkLevelSend)(int, unsigned char);
extern pGCPkLevelSend GCPkLevelSend;

typedef void(*pCGWarehouseUseEnd)(int aIndex);
extern pCGWarehouseUseEnd CGWarehouseUseEnd;

typedef int(*pNpcTalk)(OBJECTSTRUCT * lpNpc, OBJECTSTRUCT * lpObj);
extern pNpcTalk NpcTalk;

typedef void(*pgObjTeleport)(int uIndex, int Map, int X, int Y);
extern pgObjTeleport gObjTeleport;

typedef void(*pItemSerialCreateSend)(int aIndex, BYTE MapNumber, BYTE x, BYTE y, int type, BYTE level, BYTE dur, BYTE Op1, BYTE Op2, BYTE Op3, int LootIndex, BYTE NewOption, BYTE SetOption);
extern pItemSerialCreateSend ItemSerialCreateSend;

typedef DWORD(*pItemGetNumberMake)(DWORD,DWORD);
extern pItemGetNumberMake ItemGetNumberMake;

typedef void(*pGameMonsterAllAdd)();
extern pGameMonsterAllAdd GameMonsterAllAdd;

typedef int(*pgObjAddMonster)(unsigned char);
extern pgObjAddMonster gObjAddMonster;

typedef void(*pgObjSetMonster)(int, WORD);
extern pgObjSetMonster gObjSetMonster;

typedef void(*pGameMonsterAllCloseAnd)();
extern pGameMonsterAllCloseAnd GameMonsterAllCloseAnd;

typedef short(*pgObjDel)(int aIndex);
extern pgObjDel gObjDel;

typedef void(*pAllSendServerMsg)(char * msg);
extern pAllSendServerMsg AllSendServerMsg;

typedef void(*pgObjViewportList)(LPOBJ lpObj);
extern pgObjViewportList gObjViewportList;

typedef int(*pgObjGetIndex)(char * name);
extern pgObjGetIndex gObjGetIndex;

typedef bool(*pShopDataLoad)();
extern pShopDataLoad ShopDataLoad;

typedef BYTE(*pgObjInventoryDeleteItem)(int aIndex ,int itempos);
extern pgObjInventoryDeleteItem gObjInventoryDeleteItem;

typedef void(*pGCInventoryItemDeleteSend)(int aIndex, BYTE pos, unsigned char flag);
extern pGCInventoryItemDeleteSend GCInventoryItemDeleteSend;

typedef void(*pGCInventoryItemOneSend)(int aIndex, int pos);
extern pGCInventoryItemOneSend GCInventoryItemOneSend;

typedef int(*pgObjMonsterTopHitDamageUser)(LPOBJ lp);
extern pgObjMonsterTopHitDamageUser gObjMonsterTopHitDamageUser;

typedef BOOL(*pgObjMonsterDrop)(LPOBJ lpObj, LPOBJ lpTargetObj);
extern pgObjMonsterDrop gObjMonsterDrop;

typedef void(*pCGUseItemRecv)(PMSG_USEITEM* lpMsg,int index);
extern pCGUseItemRecv CGUseItemRecv;

typedef void(*pJGAnsMapSvrAuth)(PMSG_ANS_MAPSVRAUTH * lpMsg);
extern pJGAnsMapSvrAuth JGAnsMapSvrAuth;

typedef BOOL(__cdecl*pRecvDataParse)(_PER_IO_CONTEXT * context, int index);
extern pRecvDataParse RecvDataParse;

typedef void (*pCGDurationMagicRecv) (PBYTE,int);
extern pCGDurationMagicRecv CGDurationMagicRecv;

typedef void(*pWarRequestResult)(LPSTR GuildName, int aIndex, int type);
extern pWarRequestResult WarRequestResult;