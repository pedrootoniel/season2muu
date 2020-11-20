#include "stdafx.h"

void SetNop(DWORD dwOffset, int Size)
{
	for(int n=0; n < Size; n++){
	*(BYTE*)(dwOffset+n) = 0x90;
	}
}

void HookFunc(DWORD offset, DWORD funcao)
{
	*(BYTE*)  (offset)  = 0xE9;
	*(DWORD*)(offset+1) = (DWORD)(funcao)-(offset+5);
}

void HookNop(DWORD offset, int x)
{
	for(int i = 0; i < x; i++)
	{
		*(BYTE*)(offset+i) = 0x90;
	}
}

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC1;		
	lpBuf[1] =size;
	lpBuf[2] =head;
}

void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}

static unsigned char code[3]={0xFC, 0xCF, 0xAB};
void buxconvert(char* buf, int size)
{
	for(int n = 0; n < size; n++)
	{
		buf[n] ^= code[n%3];
	}
}

void GCAllianceMessage(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+16;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x40;
	Buffer[14]=0x40;
	strncpy((char*)&Buffer[15],Mensagem,Len);
	DataSend(PlayerID,(BYTE*)Buffer,Buffer[1]);
}

int	Rand(int min, int max)
{
	if(min == max) 
	{
	    return min;
	}

	int rnd = rand();
	int r = min + rnd / (RAND_MAX / (max - min) + 1);

	return r;
}

void GCGuildWarRequestResult(LPSTR GuildName, int aIndex, int type)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

    if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 1)
	{
		GCServerMsgStringSend("necessário fechar o trade antes de pedir war",aIndex,0);
		return;
	}

	WarRequestResult(GuildName,aIndex,type);
}