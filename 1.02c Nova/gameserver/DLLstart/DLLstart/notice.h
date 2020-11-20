#include "stdafx.h"

struct notice
{
	char message[255];
	BYTE type;
	//
	int  count;
	//
	int  active;
	int  time;
	//
	void load();
};

extern notice noticearray[255];
extern notice noticestart;

void __stdcall StartNotice();