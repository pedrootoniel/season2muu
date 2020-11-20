#pragma once

#include "stdafx.h"

class DataBase
{
private:
	SAConnection * sa;
	SACommand    * ex;

	char message[255];
public:
	DataBase();
	~DataBase();

	void Connect();
	int  AccountVIP(char * account);
	int  CharReset(char * name);
	void WareHouseChange(char * account, WORD ware);
	void CharResetUpdate(char * name);
};

extern DataBase database;