#pragma once

#include "stdafx.h"

struct itemexdropselect
{
	//
	int  index;
	int  id;
	int  count;
	//
	void load();
};

extern itemexdropselect itemarray[255];
extern itemexdropselect item;

struct dropadd
{
	//
	BYTE index;
	BYTE id;
	BYTE level;
	BYTE skill;
	BYTE luck;
	BYTE addopt;
	BYTE addoptex;
	short mapa;
	short monstro;
	short porcentagem;
	short minlevel;
	short maxlevel;
	//
	int   count;
	//
	void  load();
};

extern dropadd droparray[255];
extern dropadd dropd;

struct configs
{
	//variaveis
	int  gameserver;
	int  joinserver;
	int  dataserver;
	int  exdbserver;
	int  portserver;
	char checksum;
	char charid;
	char guildid;
	int  tempitems;
	char ccplayer;
	char allplayer;
	int  manaagi;
	int  manaene;
	int  manadiv;
	int  greatvit;
	int  greatene;
	int  party2;
	int  party3;
	int  party4;
	int  party5;
	int  setparty3;
	int  setparty4;
	int  setparty5;
	int  twistslash;
	int  ragefulblow;
	int  deathstab;
	int  greatfort;
	int  penetration;
	int  dropex;
	int  dropexskill;
	int  dropexluck;
	int  dropskill;
	int  dropluck;
	int  pointsdl;
	int  pointsmg;
	int  pointsothers;
	int  healing[5];
	int  mana[6];
	int  AG[6];
    int  SD[6];
	char message[4][255];
	BYTE color[4];
	int  experience[4];
	int  drops[4];
	char soulnoluck[4];
	char soulluck[4];
	char life[4];
	int  levelsoldier[4];
	int  mix10[4];
	int  mix11[4];
	int  mix12[4];
	int  mix13[4];
	int  mix10luck[4];
	int  mix11luck[4];
	int  mix12luck[4];
	int  mix13luck[4];
	int  potionactive;
	int  potiontime;
	int  zentype;
	int  zenmix;
	int  skillsiege;
	int  reflete;
	int  kundumitem;
	int  kundumrate;
	int  DarkHorseMix;
	int  DarkHorsePrice;
	int  DarkRavenMix;
	int  DarkRavenPrice;
	DWORD DarkRavenDurability;


	//funções
	void load();
	void hashload();

	//hash
	DWORD hashratejewel;
	DWORD hashlevelsoldier;
	DWORD hashitemlevelmix;
	DWORD hashmovesystem;
	DWORD hashseal;
};

extern configs cfg;