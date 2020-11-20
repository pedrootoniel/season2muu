#include "stdafx.h"

struct Npc
{
	WORD classe;
	char mapa;
	WORD x;
	WORD y;
	char pos;
	char tipo;
	//
	int  count;
	int  countdel;
	//
	void load();
};

extern Npc npcarray[255];
extern Npc npc;

int NpcTalkClick(LPOBJ lpNpc, LPOBJ lpObj);
void NpcTalkGuardMessage();