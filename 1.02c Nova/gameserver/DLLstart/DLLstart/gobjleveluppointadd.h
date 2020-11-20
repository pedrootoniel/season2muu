#pragma once

#include "stdafx.h"

struct addPoints
{
	WORD forca;
	WORD agilidade;
	WORD vitalidade;
	WORD energia;
	WORD comando;
	// 
	static void load();
};

bool gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj);
void gObjStatus();

extern addPoints ap[65];