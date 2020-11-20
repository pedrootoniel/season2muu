#include "stdafx.h"


DWORD OptimizeBack = 0x6B4A4A;
__declspec(naked) void Optimize()
{
	__asm
	{
		PUSH 1;
		CALL DWORD PTR DS : [0x783164];
		CALL DWORD PTR DS : [0x783160];

		JMP OptimizeBack;
	}
}

void fix()
{
	//===================================================================================
	// Fix Consumo CPU
	//===================================================================================
	hook_extended(0x6B4A44,   (DWORD)(&Optimize));


	//==================================================================================
	// Change Folder
	//==================================================================================
	_mkdir(ErrorDir);
	char cTempLog[40] = ErrorLog;
	DWORD *offsetLog = (DWORD*)(0x0079F4D4);
	memset(&offsetLog[0],0,40);
	memcpy(&offsetLog[0],cTempLog,strlen(cTempLog));

	char cTempDump[40] = DumpLog;
	DWORD *offsetDump = (DWORD*)(0x007A25F4);
	memset(&offsetDump[0],0,40);
	memcpy(&offsetDump[0],cTempDump,strlen(cTempDump));

	//==================================================================================
	// Decrypt Logs
	//==================================================================================
	BYTE DecriptLog[5] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
	memcpy((int*)0x00420F8D, DecriptLog, sizeof(DecriptLog));
	memcpy((int*)0x004211A0, DecriptLog, sizeof(DecriptLog));

	//==================================================================================
	// Dont Show IP IN LOG FILE
	//==================================================================================
	SetByte((PVOID)0x004DA2F9, 0x80);
	SetByte((PVOID)0x004DA2FA, 0x7B);
	SetByte((PVOID)0x004DA2FB, 0x87); 
	SetByte((PVOID)0x004DA2FC, 0x05); 

	//==================================================================================
	// Fenrir Style Season 4
	//==================================================================================
	SetByte((PVOID)(0x0045BEE3+3),0x66);
	SetByte((PVOID)(0x0045BEE3+4),0x66);
	SetByte((PVOID)(0x0045BEE3+5),0x66);
	SetByte((PVOID)(0x0045BEE3+6),0x3F);

	//=================================================
	// - [Fix] FPS De 40 para 34 
	//=================================================
	*(BYTE*)(0x006B4A3B+6) = 0x22; 

	//==================================================================================
	// [#] Lag usando CTRL
	//==================================================================================
	SetByte((LPVOID)0x0046F249,0x02);

	//=================================================
	//--  ANTIALIASED  
	//=================================================
	*(BYTE*)(0x4D58AB + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D58EB + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D592B + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D5983 + 1) = ANTIALIASED_QUALITY;
}