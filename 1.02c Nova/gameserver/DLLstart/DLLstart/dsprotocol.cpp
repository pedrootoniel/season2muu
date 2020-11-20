#include "stdafx.h"

void ProtocolDS(BYTE protoNum, unsigned char* aRecv, int aLen)
{
	switch(protoNum)
	{
	    case 0xE0:
			aRecvPlayerInfo((PLAYER_OBJECT*)aRecv);
		break;
	}

	ProtocolCoreDS(protoNum,aRecv,aLen);
}

void aRecvPlayerInfo(PLAYER_OBJECT * pDataServer)
{
	player_struct[pDataServer->index].vip    = pDataServer->vip;
	player_struct[pDataServer->index].resets = pDataServer->resets;
}

int DataServerSend(unsigned char* buf, int len)
{
	int result;

	_asm
	{
        #if DLLtype == 0
		mov eax, 0x00401870;
        #else
		mov eax, 0x004019F6;
        #endif
		push len;
		mov edx, dword ptr ds:[buf];
		push edx;
		#if DLLtype == 0
		mov ecx, 0x6FCB78;
        #else
		mov ecx, 0x754CB0
        #endif
		call eax;
		mov result, eax;
	}

	return result;
}