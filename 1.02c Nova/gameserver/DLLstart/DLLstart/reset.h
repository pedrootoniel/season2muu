#pragma once

#include "stdafx.h"

struct resetconfig
{
	int   active[4];
	int   type[4];
	int   move[4];
	int   leadership[4];
	//
	int   vip;
	int   resetmin;
	int   resetmax;
	short level;
	int   money;
	int   points;
	//
	int   count;
	//
	void load();
	void ResetStart(LPOBJ lpObj);
};

extern resetconfig rStart[255];
extern resetconfig rStarted;