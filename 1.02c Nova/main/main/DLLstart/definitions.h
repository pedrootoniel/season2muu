#include "stdafx.h"

#define       ITEMGET(x,y)                   ((x)*512 + (y))
#define       ITEM_GET(x, y)                 ( x * 512 + y) + 0x246

typedef void(*pProtocoloCore)(DWORD protoNum, LPBYTE aRecv, int len, int index);
extern pProtocoloCore ProtocoloCore;

typedef void(*pTextureLoad)(int,char*,char*,int);
extern pTextureLoad TextureLoad;

typedef void(*pTextureCall)(int,char*,int,int,int);
extern pTextureCall TextureCall;

void datasend(LPBYTE buf, int len);

#define HDK_SET_ITEM_EFFECT			0x0052F106
#define HDK_SET_COLOR_EFFECT		0x0052F162
#define HDK_ITEM_EFFECT_ALLOW		0x0052F127
#define HDK_ITEM_EFFECT_NOT_ALLOW	0x0052F76D
#define HDK_NEXT_ITEM_COLOR			0x0052F191

#define Offset_CreateFontA1 0x006BCD36
#define Offset_CreateFontA2 0x004D58CC
#define Offset_CreateFontA3	0x004D590C
#define Offset_CreateFontA4 0x004D594E
#define Offset_CreateFontA5 0x004D59A8

#define ErrorDir			"DTserver/Log"
#define DumpLog				"DTserver/Log/Error.dmp"
#define ErrorLog			"DTserver/Log/Error.log"

#define CONFIG_FONT_FILE			".\\DTserver\\script\\Font.txt"
#define CONFIG_SMOKE_FILE	".\\DTserver\\script\\SmokeEffect.txt"
#define CONFIG_EFFECT_FILE	".\\DTserver\\script\\ItemEffect.txt"

#define MainSpeedFrame1				(float*)(0x783A44)
#define MainSpeedFrame2				(float*)(0x783A18)

namespace ASM
{
	enum T
	{
		EAX		= 0x50,
		JMP		= 0xE9,
		JMPS	= 0xEB,
		JE		= 0x74,
		JNE		= 0x75,
		JGE		= 0x7D,
		NOP		= 0x90,
		CALL	= 0xE8,
		PUSH	= 0x68,
		RETN	= 0xC3,
	};
};
