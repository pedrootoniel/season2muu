#include "stdafx.h"

struct chaosCastle
{
	BYTE index;
	BYTE id;
	BYTE level;
	BYTE skill;
	BYTE luck;
	BYTE addopt;
	BYTE addoptex;
	BYTE addoptanc;
	//
	int  count;
	//
	int  active;
	//
	void load();
};

extern chaosCastle ccastle;
extern chaosCastle ccastlearray[255];

void ChaosCastleDROP(int cc, int index);