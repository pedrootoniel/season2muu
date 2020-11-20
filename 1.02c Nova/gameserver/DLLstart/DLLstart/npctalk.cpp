#include "stdafx.h"

Npc npcarray[255];
Npc npc;

void Npc::load()
{
	for(int i = 0; i < this->count; i++)
	{
		gObjDel(npcarray[i].countdel);
	}

	this->count = 0;
	memset(npcarray,0,sizeof(npcarray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\npcstruct.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			npcarray[this->count].classe   = section.Rows[i].GetInt(0);
			npcarray[this->count].mapa     = section.Rows[i].GetInt(1);
			npcarray[this->count].x        = section.Rows[i].GetInt(2);
			npcarray[this->count].y        = section.Rows[i].GetInt(3);
			npcarray[this->count].pos      = section.Rows[i].GetInt(4);
			npcarray[this->count].tipo     = section.Rows[i].GetInt(5);
	        npcarray[this->count].countdel = gObjInsertMonster(npcarray[this->count].mapa,npcarray[this->count].x,npcarray[this->count].y,npcarray[this->count].classe,npcarray[this->count].pos,3);
			this->count++;

		}
	}
}

int NpcTalkClick(LPOBJ lpNpc, LPOBJ lpObj)
{
	for(int i = 0; i < npc.count; i++)
	{
		if(lpNpc->Class == npcarray[i].classe && lpNpc->MapNumber == npcarray[i].mapa && lpNpc->X == npcarray[i].x && lpNpc->Y == npcarray[i].y)
		{
			if(npcarray[i].tipo == 0) // pkclear
			{
				cmds.ChatPKClear(lpObj);
			}
			if(npcarray[i].tipo == 1) // reset
			{
				rStarted.ResetStart(lpObj);
			}
		}
	}

	if(lpNpc->Class == 240)
	{
		if(lpObj->m_ReqWarehouseOpen == 1)
		{
	        if((GetTickCount() - player_struct[lpObj->m_Index].bautemp) < 7000)
	        {
		        message(lpObj->m_Index,28,7 - (GetTickCount() -  player_struct[lpObj->m_Index].bautemp) / 1000);
	            return true;
            }

			lpObj->m_ReqWarehouseOpen = 0;
	        player_struct[lpObj->m_Index].bautemp     = GetTickCount();
		}
	}

	return NpcTalk(lpNpc,lpObj);
}

void NpcTalkGuardMessage()
{
	char Message[500];
	DWORD *GuardMessage = (DWORD*)(0x006B3D10);
	GetPrivateProfileString("settings","GuardMessage","Seja Bem Vindo",Message,50,".\\configurações\\servidor.season");
	memset(&GuardMessage[0],0,50);
	memcpy(&GuardMessage[0],Message,strlen(Message));
}
