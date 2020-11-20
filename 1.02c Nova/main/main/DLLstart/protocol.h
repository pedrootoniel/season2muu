#include "stdafx.h"
#include "packets.h"

void Protocol(DWORD protoNum, LPBYTE aRecv, int aLen, int aIndex);
void LoadProtocol();
void gObjName(PMSG_NAME * p);
void gObjPoints(PLAYER_POINTS * p);
void gObjStatus(PLAYER_STATUS * p);
void gObjReset(PLAYER_RESET * p);
void gObjMix(GLOBIN_MIX * p);
void gObjCalCharacter(CALCHARACTER * p);
void gObjMain(MAIN * p);
void gObjSendGSPacket();
void ApplyDexterityFix();