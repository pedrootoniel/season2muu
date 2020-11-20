#include "stdafx.h"

pProtocoloCore                         ProtocoloCore                      =     (pProtocoloCore)0x004FF790;
pTextureLoad                           TextureLoad                        =     (pTextureLoad)0x0067FFA3;
pTextureCall                           TextureCall                        =     (pTextureCall)0x0067FB27;

void datasend(LPBYTE buf, int len)
{
	_asm
	{
		mov eax, len;
		push eax;
		mov ecx, buf;
		push ecx;
		mov ecx, dword ptr ds:[0x7A2854];
		mov edi,0x00403D10;
		call edi;
	}
}