#include "stdafx.h"

struct bloodCastle
{
	//
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

extern bloodCastle bcastle;
extern bloodCastle bcastlearray[255];

void BloodCastleDROP(int index);