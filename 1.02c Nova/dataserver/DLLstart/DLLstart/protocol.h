#include "stdafx.h"
#include "packets.h"

void Protocol(BYTE protoNum, BYTE *aRecv, int aLen, short aIndex);
void gObjPlayerLoad(PLAYER_INFOR * lpRecv, short index);
void gObjWare(ACCOUNT_WARE * lpRecv, short index);
void gObjReset(RESET_SEND * lpRecv, short index);