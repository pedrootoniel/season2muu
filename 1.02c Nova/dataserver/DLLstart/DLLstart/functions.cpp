#include "stdafx.h"

void HookFunc(DWORD offset, DWORD funcao)
{
	*(BYTE*)  (offset)  = 0xE8;
	*(DWORD*)(offset+1) = (DWORD)(funcao)-(offset+5);
}