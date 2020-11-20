#include "stdafx.h"

struct GMsystem
{
	char  name[11];
	int   type[50];

	//
	int   count;

	//
	void load();

	bool CheckGM(LPOBJ lpObj, unsigned com);
};

extern GMsystem gSystem;
extern GMsystem gSystemarray[255];