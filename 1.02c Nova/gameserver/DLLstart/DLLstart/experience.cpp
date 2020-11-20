#include "stdafx.h"

int Experience(LPOBJ player,int exp)
{
	return exp * cfg.experience[player_struct[player->m_Index].vip]; 
}

__declspec(naked) void gObjMonsterExp()
{
    _asm
	{
		mov eax,dword ptr ss:[ebp-0x04]
		push eax
		mov edx,dword ptr ss:[ebp+0x08]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x04],eax
		#if DLLtype == 0
		mov ecx, 0x004E2C66
        #else
		mov ecx, 0x004F4E76
        #endif
		jmp ecx
	}
}

__declspec(naked) void gObjMonsterExpParty()
{
    _asm
	{
        mov eax,dword ptr ss:[ebp-0x08]
		push eax
		mov edx,dword ptr ss:[ebp-0x54]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x08],eax
		#if DLLtype == 0
		mov ecx, 0x004E335B
        #else
		mov ecx, 0x004F556B
        #endif
		jmp ecx
	}
}

__declspec(naked) void gObjMonsterExpPartyZen()
{
    _asm
	{
        mov eax,dword ptr ss:[ebp-0x08]
		push eax
		mov edx,dword ptr ss:[ebp-0x54]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x08],eax
		#if DLLtype == 0
		mov ecx, 0x004E3460
        #else
		mov ecx, 0x004F5670
        #endif 
		jmp ecx
	}
}

__declspec(naked) void gObjMonsterExpDevil()
{
    _asm
	{
		mov eax,dword ptr ss:[ebp-0x08]
		push eax
		mov edx,dword ptr ss:[ebp+0x08]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x8],eax
        mov ecx, 0x00465908
        jmp ecx
	}
}

__declspec(naked) void gObjMonsterExpPartyDevil()
{
    _asm
	{
        mov eax,dword ptr ss:[ebp-0x0C]
		push eax
		mov edx,dword ptr ss:[ebp-0x58]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x0C],eax
		mov ecx, 0x00465F5D
		jmp ecx
	}
}

__declspec(naked) void gObjMonsterExpPartyDevilZen()
{
    _asm
	{
        mov eax,dword ptr ss:[ebp-0x0C]
		push eax
		mov edx,dword ptr ss:[ebp-0x58]
		push edx
		call Experience
		mov dword ptr ss:[ebp-0x0C],eax
		mov ecx, 0x00466077
		jmp ecx
	}
}