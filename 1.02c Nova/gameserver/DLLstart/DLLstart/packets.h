#pragma once

#include "stdafx.h"

#define SET_NUMBERH(x)  ((BYTE)((DWORD)(x)>>(DWORD)8))
#define SET_NUMBERL(x)  ((BYTE)((DWORD)(x) & 0xFF))
#define SET_NUMBERHW(x) ((WORD)((DWORD)(x)>>(DWORD)16))
#define SET_NUMBERLW(x) ((WORD)((DWORD)(x) & 0xFFFF))

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

struct PWMSG_HEAD
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};

struct SAVE_PETITEM
{
	int  serial;	
	BYTE level;	
	int  exp;
};

struct SDHP_SAVE_PETITEM
{
	PWMSG_HEAD h;
	BYTE count;
};

struct PMSG_USEITEM
{
	PBMSG_HEAD h;
	BYTE inventoryPos;
	BYTE invenrotyTarget;
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PMSG_CHARMAPJOIN
{
	PBMSG_HEAD h;
	BYTE subcode;
	char name[10];	
};

struct PMSG_ANS_MAPSVRAUTH
{
	PBMSG_HEAD h;
	int  index;
	char account[11];
	char name[11];
	WORD prevmapcode;
	WORD mapnumber;
	BYTE x;
	BYTE y;
	int  result;
	int  usernumber;
	int  dbnumber;
	char jominnumber[13];
	unsigned char blockcode;
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

struct PLAYER_POINTS
{
	PBMSG_HEAD h;
	int points;
};

struct PLAYER_STATUS
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
	WORD  manamax;
};

struct PLAYER_RESET
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
	int   points;
	DWORD exp;
	DWORD nextexp;
	short level;
};

struct PMSG_NAME
{
	PBMSG_HEAD h;
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

struct GLOBIN_MIX
{
	PBMSG_HEAD h;
	int mix10;
	int mix11;
	int mix12;
	int mix13;
	int mix10luck;
	int mix11luck;
	int mix12luck;
	int mix13luck;
	int fenrir1;
	int fenrir2;
	int fenrir3;
};

struct CALCHARACTER
{
	PBMSG_HEAD h;
	int elf1;
	int elf2;
	int bkmg1;
	int bkmg2;
	int dl1;
	int dl2;
	int sm1;
	int sm2;
};

struct MAIN
{
	PBMSG_HEAD h;
	int skillsiege;
	int reflete;
};

struct PMSG_CHARINFOMAIN
{
	PBMSG_HEAD h;
	BYTE Code;
	BYTE Class;
	WORD Dexterity;
	WORD AttackSpeed;
	WORD MagicSpeed;
}; 
