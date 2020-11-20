#pragma once

#include "stdafx.h"

class configs
{
public:
	configs();
	~configs();

	//variaveis
	char vip[2][255];
	char resets[255][255];

	//funções
	void load();
};

extern configs cfg;