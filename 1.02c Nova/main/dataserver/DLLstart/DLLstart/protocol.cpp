#include "stdafx.h"

void Protocol(BYTE protoNum, BYTE *aRecv, int aLen, short index)
{
	switch(protoNum)
	{
	    case 0xE0:
			gObjPlayerLoad((PLAYER_INFOR*)aRecv,index);
		break;
	    case 0xE1:
			gObjWare((ACCOUNT_WARE*)aRecv,index);
		break;
	    case 0xE2:
			gObjReset((RESET_SEND*)aRecv,index);
		break;
	}

	ProtocolCore(protoNum,aRecv,aLen,index);
}

void gObjPlayerLoad(PLAYER_INFOR * lpRecv, short index)
{
	lpRecv->name[10]    = '\0';
	lpRecv->account[10] = '\0';

	LogAddFuncColor(3,"packet recebido: conta : %s - nome : %s",lpRecv->account,lpRecv->name);

	PLAYER_OBJECT player;

	player.h.c        = 0xC1;
	player.h.headcode = 0xE0;
	player.h.size     = sizeof(PLAYER_OBJECT);
	player.index      = lpRecv->index;
	player.vip        = database.AccountVIP(lpRecv->account);
	player.resets     = database.CharReset(lpRecv->name);

	memcpy(player.account, lpRecv->account, 10);
	memcpy(player.name, lpRecv->name, 10);

	DataSend(index,(BYTE*)&player, player.h.size);

	LogAddFuncColor(3,"packet enviado: conta : %s - nome : %s - vip : %d - resets : %d",lpRecv->account,lpRecv->name,player.vip,player.resets);
}

void gObjWare(ACCOUNT_WARE * lpRecv, short index)
{
	LogAddFuncColor(3,"packet recebido: conta : %s - bau : %d",lpRecv->account,lpRecv->ware);
	database.WareHouseChange(lpRecv->account,lpRecv->ware);
}

void gObjReset(RESET_SEND * lpRecv, short index)
{
	LogAddFuncColor(3,"packet recebido: nome : %s - reset update",lpRecv->name);
	database.CharResetUpdate(lpRecv->name);
}