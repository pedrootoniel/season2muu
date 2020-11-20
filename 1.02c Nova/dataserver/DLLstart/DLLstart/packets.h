#pragma once

#include "stdafx.h"

struct PBMSG_HEAD
{
public:
	void set (LPBYTE lpBuf, BYTE head, BYTE size)	
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	

	void setE ( LPBYTE lpBuf, BYTE head, BYTE size)
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	

	BYTE c; 
	BYTE size; 
	BYTE headcode;
};

struct PLAYER_INFOR
{
	PBMSG_HEAD h;
	char account[11];
	char name[11];
	int  index;
};

struct PLAYER_OBJECT
{
	PBMSG_HEAD h;
	int  index;
	int  vip;
	int  resets;
	char account[11];
	char name[11];
};

struct ACCOUNT_WARE
{
	PBMSG_HEAD h;
	char account[11];
	int  ware;
};

struct RESET_SEND
{
	PBMSG_HEAD h;
	char name[11];
};