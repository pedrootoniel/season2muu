#include "stdafx.h"

struct devilSquare
{
	BYTE index;
	BYTE id;
	BYTE level;
	BYTE skill;
	BYTE luck;
	BYTE addopt;
	BYTE addoptex;
	//
	int  count;
	//
	void load();
};

extern devilSquare dsquare;
extern devilSquare dsquarearray[255];

void DevilSquare(LPOBJ lpObj);

__declspec() void DevilSquareDROP();