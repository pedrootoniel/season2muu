#include "stdafx.h"

commandS cmds;

void moveS::load()
{
    this->count = 0;
    memset(cmds.movesarray, 0, sizeof(cmds.movesarray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\structmoves.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(cmds.movesarray[this->count].string, sizeof(cmds.movesarray[this->count].string), (section.Rows[i].GetStringPtr(0)) );
			cmds.movesarray[this->count].vip       = section.Rows[i].GetInt(1);
			cmds.movesarray[this->count].map       = section.Rows[i].GetInt(2);
			cmds.movesarray[this->count].cordx     = section.Rows[i].GetInt(3);
			cmds.movesarray[this->count].cordy     = section.Rows[i].GetInt(4);
			cmds.movesarray[this->count].level     = section.Rows[i].GetInt(5);
			cmds.movesarray[this->count].pk        = section.Rows[i].GetInt(6);
			this->count++;
		}
	}
}

void commandS::load()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	this->moves.load();

	token.ParseFile(std::string(".\\configurações\\customizações\\comandos.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < 40; i++)
		{
		    strcpy_s(this->string[i],   sizeof(this->string[i]),     (section.Rows[i].GetStringPtr(0)));
		    this->active[i]           = section.Rows[i].GetInt(1);
		    this->level[i]            = section.Rows[i].GetInt(2);
		    this->zen[i]              = section.Rows[i].GetInt(3);
		    this->vip[i]              = section.Rows[i].GetInt(4);
		    this->resets[i]           = section.Rows[i].GetInt(5);
			this->temp[i]             = section.Rows[i].GetInt(6);
		}
	}

	if(group.GetSection(1, section))
	{
		this->maxbau[0]           = section.Rows[0].GetInt(0);
		this->maxbau[1]           = section.Rows[0].GetInt(1);
		this->maxbau[2]           = section.Rows[0].GetInt(2);
		this->maxbau[3]           = section.Rows[0].GetInt(3);
	}
}

void commandS::ChatPost(char * string, LPOBJ lpObj)
{
	if(this->active[0] == 0)
	{
		message(lpObj->m_Index,5,0);
		return;
	}
	if(lpObj->Level < this->level[0])
	{
		message(lpObj->m_Index,6,this->level[0]);
		return;
	}
	if(player_struct[lpObj->m_Index].vip < this->vip[0])
	{
		message(lpObj->m_Index,7,0);
		return;
	}
	if(player_struct[lpObj->m_Index].resets < this->resets[0])
	{
		message(lpObj->m_Index,8,this->resets[0]);
		return;
	}
	if(lpObj->Money < this->zen[0])
	{
		message(lpObj->m_Index,9,this->zen[0]);
		return;
	}
	if((GetTickCount() - player_struct[lpObj->m_Index].posttemp) < this->temp[0]*1000)
	{
		message(lpObj->m_Index,21,this->temp[0] - (GetTickCount() - player_struct[lpObj->m_Index].posttemp) / 1000);
	    return;
    }

	player_struct[lpObj->m_Index].posttemp = GetTickCount();

    for(int i = MIN_PLAYERID; i < MAX_PLAYERID; i++)
	{
		if(gObjIsConnected(i) == 1)
		{
			char msg[255];
	   	    wsprintf(msg,"[post]: %s",string);
			GCAllianceMessage(lpObj->Name,msg,i);
		}
	}

	lpObj->Money -= this->zen[0];

	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

void commandS::ChatAdd(char * string, LPOBJ lpObj, BYTE select)
{
	if(this->active[select] == 0)
	{
		message(lpObj->m_Index,10,0);
		return;
	}
	if(lpObj->Level < this->level[select])
	{
		message(lpObj->m_Index,11,this->level[select]);
		return;
	}
	if(player_struct[lpObj->m_Index].vip < this->vip[select])
	{
		message(lpObj->m_Index,12,0);
		return;
	}
	if(player_struct[lpObj->m_Index].resets < this->resets[select])
	{
		message(lpObj->m_Index,13,this->resets[select]);
		return;
	}
	if(lpObj->Money < this->zen[select])
	{
		message(lpObj->m_Index,14,this->zen[select]);
		return;
	}

	int pontos = 0;

	sscanf_s(string,"%d",&pontos);

	if(pontos < 1 || pontos > 65000)
	{
		return;
	}

	if(lpObj->LevelUpPoint < pontos)
	{
		return;
	}

	switch(select)
	{
	    case 1: //força
		    if(lpObj->Strength + pontos > ap[lpObj->DbClass].forca)
		    {
			    message(lpObj->m_Index,0,ap[lpObj->DbClass].forca);
			    return;
		    }
		    else
		    {
	           lpObj->Strength += pontos;
		    }
		break;
	    case 2: //agilidade
		    if(lpObj->Dexterity + pontos > ap[lpObj->DbClass].agilidade)
		    {
			    message(lpObj->m_Index,1,ap[lpObj->DbClass].agilidade);
			    return;
		    }
		    else
		    {
	           lpObj->Dexterity += pontos;
		    }
		break;
	    case 3: //vitalidade
		    if(lpObj->Vitality + pontos > ap[lpObj->DbClass].vitalidade)
		    {
			    message(lpObj->m_Index,2,ap[lpObj->DbClass].vitalidade);
			    return;
		    }
		    else
		    {
	            lpObj->Vitality += pontos;
	            lpObj->MaxLife  += lpObj->VitalityToLife * pontos;
				GCReFillSend(lpObj->m_Index,lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
	            gObjCalcMaxLifePower(lpObj->m_Index);
		    }
		break;
	    case 4: //energia
		    if(lpObj->Energy + pontos > ap[lpObj->DbClass].energia)
		    {
			    message(lpObj->m_Index,3,ap[lpObj->DbClass].energia);
			    return;
		    }
		    else
		    {
		        lpObj->Energy  += pontos;
	            lpObj->MaxMana += lpObj->EnergyToMana * pontos;
                gObjSetBP(lpObj->m_Index);
	            GCManaSend(lpObj->m_Index,lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
		    }
		break;
	    case 5: //comando
			if(lpObj->DbClass != 64)
			{
				return;
			}
	        if(lpObj->Leadership + pontos > ap[lpObj->DbClass].comando)
		    {
			    message(lpObj->m_Index,4,ap[lpObj->DbClass].comando);
			    return;
		    }
		    else
		    {
		        lpObj->Leadership += pontos;
		    }
		break;
	}

	lpObj->Money        -= this->zen[select];
	lpObj->LevelUpPoint -= pontos;

	gClient.GSStatsUP(lpObj);
	gClient.GSPointsUP(lpObj);

	GCMoneySend(lpObj->m_Index,lpObj->Money);
	gObjCalCharacter(lpObj->m_Index);
}

void commandS::ChatPKClear(LPOBJ lpObj)
{
	if(this->active[6] == 0)
	{
		message(lpObj->m_Index,15,0);
		return;
	}
	if(lpObj->Level < this->level[6])
	{
		message(lpObj->m_Index,16,this->level[6]);
		return;
	}
	if(player_struct[lpObj->m_Index].vip < this->vip[6])
	{
		message(lpObj->m_Index,17,0);
		return;
	}
	if(player_struct[lpObj->m_Index].resets < this->resets[6])
	{
		message(lpObj->m_Index,18,this->resets[6]);
		return;
	}
	if(lpObj->Money < this->zen[6])
	{
		message(lpObj->m_Index,19,this->zen[6]);
		return;
	}
	if(lpObj->m_PK_Level < 4)
	{
		message(lpObj->m_Index,20,0);
		return;
	}

	lpObj->Money     -= this->zen[6];
	lpObj->m_PK_Level = 3;

	GCMoneySend(lpObj->m_Index,lpObj->Money);
	GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
}

void commandS::ChatWare(char * string, LPOBJ lpObj)
{
	if(this->active[7] == 0)
	{
		message(lpObj->m_Index,22,0);
		return;
	}
	if(lpObj->Level < this->level[7])
	{
		message(lpObj->m_Index,23,this->level[7]);
		return;
	}
	if(player_struct[lpObj->m_Index].vip < this->vip[7])
	{
		message(lpObj->m_Index,24,0);
		return;
	}
	if(player_struct[lpObj->m_Index].resets < this->resets[7])
	{
		message(lpObj->m_Index,25,this->resets[7]);
		return;
	}
	if(lpObj->Money < this->zen[7])
	{
		message(lpObj->m_Index,26,this->zen[7]);
		return;
	}
	if(lpObj->m_ReqWarehouseOpen == 1)
	{
	    message(lpObj->m_Index,27,7 - (GetTickCount() - player_struct[lpObj->m_Index].bautemp) / 1000);
		return;
	}

	int bau = 0;

	sscanf_s(string,"%d",&bau);

	if(bau < 0 || bau > 65000)
	{
		return;
	}

	if(bau > this->maxbau[player_struct[lpObj->m_Index].vip])
	{
		message(lpObj->m_Index,29,this->maxbau[player_struct[lpObj->m_Index].vip]);
		return;
	}

	CGWarehouseUseEnd(lpObj->m_Index);

	ACCOUNT_WARE pWare;

	PHeadSetB((LPBYTE)&pWare, 0xE1, sizeof(pWare));
	memcpy(pWare.account, lpObj->AccountID, sizeof(pWare.account));
	pWare.ware = bau;
	DataServerSend((BYTE*)&pWare, pWare.h.size);
	LogAddFuncColor(3,"packet enviado: conta : %s - bau : %d",lpObj->AccountID,bau);

	message(lpObj->m_Index,28,7);

	lpObj->m_IfState.state    = 0;
	lpObj->m_IfState.type     = 0;
	lpObj->m_IfState.use      = 0;
	lpObj->m_ReqWarehouseOpen = 1;
	lpObj->LoadWareHouseInfo  = 0;
	lpObj->WarehouseSave      = 0;
	lpObj->Money             -= this->zen[7];
	player_struct[lpObj->m_Index].bautemp     = GetTickCount();

	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

void commandS::ChatClass(LPOBJ lpObj, char index, char type)
{
	if(this->active[index] == 0)
	{
		message(lpObj->m_Index,30,0);
		return;
	}
	if(lpObj->Level < this->level[index])
	{
		message(lpObj->m_Index,31,this->level[index]);
		return;
	}
	if(player_struct[lpObj->m_Index].vip < this->vip[index])
	{
		message(lpObj->m_Index,32,0);
		return;
	}
	if(player_struct[lpObj->m_Index].resets < this->resets[index])
	{
		message(lpObj->m_Index,33,this->resets[index]);
		return;
	}
	if(lpObj->Money < this->zen[index])
	{
		message(lpObj->m_Index,34,this->zen[index]);
		return;
	}

	for(int i = 0; i < 11; i++)
	{
		if(lpObj->pInventory[i].m_Type > 0)
		{
			message(lpObj->m_Index,35,0);
			return;
		}
	}

	if(lpObj->m_IfState.use == 1)
	{
		message(lpObj->m_Index,36,0);
		return;
	}

	lpObj->DbClass      = type;
	lpObj->CloseCount   = 1;
	lpObj->CloseType    = 1;
	lpObj->Money       -= this->zen[index];

	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

void commandS::ChatDrop(char * string, LPOBJ lpObj)
{
	if(gSystem.CheckGM(lpObj,0) == true)
	{
		int scanf[7];

		sscanf(string,"%d %d %d %d %d %d %d",&scanf[0],&scanf[1],&scanf[2],&scanf[3],&scanf[4],&scanf[5],&scanf[6]);

		for(int i = 0; i < 7; i++)
		{
			if(scanf[i] < 0)
			{
				return;
			}
		}

		ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,ITEMGET(scanf[0],scanf[1]),scanf[2],0,scanf[3],scanf[4],scanf[5],lpObj->m_Index,scanf[6],0);
	}
}

void commandS::ChatSkin(char * string, LPOBJ lpObj)
{
	if(gSystem.CheckGM(lpObj,1) == true)
	{
		int scanf;

		sscanf(string,"%d",&scanf);

	    if(scanf < -1 || scanf > 999)
		{
			return;
		}

	    lpObj->m_Change = scanf;
	    gObjViewportList(lpObj);		
	}
}

void commandS::ChatMove(char * string, LPOBJ lpObj)
{
	if(gSystem.CheckGM(lpObj,2) == true)
	{
		char name[11];
		int  scanf[3];

		sscanf(string,"%s %d %d %d",&name,&scanf[0],&scanf[1],&scanf[2]);

		for(BYTE i = 0; i <= 2; i++)
		{
			if(scanf[i] < 0 || scanf[i] > 255)
			{
				return;
			}
		}

	    gObjTeleport(gObjGetIndex(name),scanf[0],scanf[1],scanf[2]);	
	}
}

void commandS::ChatRelo(char * string, LPOBJ lpObj)
{
	if(gSystem.CheckGM(lpObj,3) == true)
	{
		int scanf;

		sscanf(string,"%d",&scanf);

		if(scanf < 0 || scanf > 2)
		{
			return;
		}

		switch(scanf)
		{
		    case 0:
				cfg.load();
				GCServerMsgStringSend("configurações recarregadas",lpObj->m_Index,3);
			break;
		    case 1:
				GameMonsterAllCloseAnd();
				GCServerMsgStringSend("monstros recarregados",lpObj->m_Index,3);
			break;
		    case 2:
				ShopDataLoad();
				GCServerMsgStringSend("shops recarregados",lpObj->m_Index,3);
			break;
		}	
	}
}

void commandS::movestart(LPOBJ lpObj, char vip, char pk, short level, short map, short x, short y)
{
	if(lpObj->Level < level)
	{
		message(lpObj->m_Index,42,level);
		return;
	}
	
	if(player_struct[lpObj->m_Index].vip < vip)
	{
		message(lpObj->m_Index,43,0);
		return;
	}
	
	if(pk == 1)
	{
	    if(lpObj->m_PK_Level > 3)
	    {
			message(lpObj->m_Index,44,0);
			return;
	    }
	}
	
	if(lpObj->m_IfState.use == 1)
	{
		return;
	}

	if(lpObj->m_bPShopOpen == true)
	{
		return;
	}

	gObjTeleport(lpObj->m_Index,map,x,y);
}

void commandS::ChatProto(LPBYTE aRecv, short index)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	if(!_memicmp(&aRecv[13],this->string[0],strlen(this->string[0])))
	{
	  this->ChatPost((char*)aRecv+13+strlen(this->string[0]),player);
	}
	if(!_memicmp(&aRecv[13],this->string[1],strlen(this->string[1])))
	{
	  this->ChatAdd((char*)aRecv+13+strlen(this->string[1]),player,1);
	}
	if(!_memicmp(&aRecv[13],this->string[2],strlen(this->string[2])))
	{
	  this->ChatAdd((char*)aRecv+13+strlen(this->string[2]),player,2);
	}
	if(!_memicmp(&aRecv[13],this->string[3],strlen(this->string[3])))
	{
	  this->ChatAdd((char*)aRecv+13+strlen(this->string[3]),player,3);
	}
	if(!_memicmp(&aRecv[13],this->string[4],strlen(this->string[4])))
	{
	  this->ChatAdd((char*)aRecv+13+strlen(this->string[4]),player,4);
	}
	if(!_memicmp(&aRecv[13],this->string[5],strlen(this->string[5])))
	{
	  this->ChatAdd((char*)aRecv+13+strlen(this->string[5]),player,5);
	}
	if(!_memicmp(&aRecv[13],this->string[6],strlen(this->string[6])))
	{
	  this->ChatPKClear(player);
	}
	if(!_memicmp(&aRecv[13],this->string[7],strlen(this->string[7])))
	{
	  this->ChatWare((char*)aRecv+13+strlen(this->string[7]),player);
	}
	if(!_memicmp(&aRecv[13],this->string[8],strlen(this->string[8])))
	{
	  this->ChatClass(player,8,1);
	}
	if(!_memicmp(&aRecv[13],this->string[9],strlen(this->string[9])))
	{
	  this->ChatClass(player,9,17);
	}
	if(!_memicmp(&aRecv[13],this->string[10],strlen(this->string[10])))
	{
	  this->ChatClass(player,10,33);
	}
	if(!_memicmp(&aRecv[13],this->string[11],strlen(this->string[11])))
	{
	  this->ChatClass(player,11,48);
	}
	if(!_memicmp(&aRecv[13],this->string[12],strlen(this->string[12])))
	{
	  this->ChatClass(player,12,64);
	}
	if(!_memicmp(&aRecv[13],this->string[13],strlen(this->string[13])))
	{
	  rStarted.ResetStart(player);
	}
	if(!_memicmp(&aRecv[13],this->string[14],strlen(this->string[14])))
	{
	  this->ChatDrop((char*)aRecv+13+strlen(this->string[14]),player);
	}
	if(!_memicmp(&aRecv[13],this->string[15],strlen(this->string[15])))
	{
	  this->ChatSkin((char*)aRecv+13+strlen(this->string[15]),player);
	}
	if(!_memicmp(&aRecv[13],this->string[16],strlen(this->string[16])))
	{
	  this->ChatMove((char*)aRecv+13+strlen(this->string[16]),player);
	}
	if(!_memicmp(&aRecv[13],this->string[17],strlen(this->string[17])))
	{
	  this->ChatRelo((char*)aRecv+13+strlen(this->string[17]),player);
	}
	if(cfg.hashmovesystem == 0x17FF07)
	{
	    for(int i = 0; i <  this->moves.count; i++)
	    {
	        if(!memicmp(&aRecv[13],this->movesarray[i].string,strlen(this->movesarray[i].string)))
		    {
			    this->movestart(player,this->movesarray[i].vip,this->movesarray[i].pk,this->movesarray[i].level,this->movesarray[i].map,this->movesarray[i].cordx,this->movesarray[i].cordy);
			}
		}
	}
}