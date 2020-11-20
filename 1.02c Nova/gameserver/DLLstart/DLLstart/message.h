#pragma once

#include "stdafx.h"

struct Message
{
	char  mensagem[255];
	short tipo;
	// 
	static void load();
};

void message(int index, int numero, int x);

extern Message ms[255];