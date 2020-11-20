#include "stdafx.h"

void Protocol(BYTE protoNum, unsigned char * aRecv, int aLen, int index, BOOL Encrypt, int serial)
{

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	switch(protoNum)
	{
		//recebimento do IP
	    case 0xFE:
		return;

		case 0x10:
		    protoNum = 0xD7;
			aRecv[2] = 0xD7;
		break;
	    case 0x00:
			cmds.ChatProto(aRecv,index);
		break;
	    case 0xF3:
	    {
		    PMSG_DEFAULT2 * lpDef = (PMSG_DEFAULT2 *)aRecv;

			switch(lpDef->subcode)
			{
				case 0x03:
			        gObjPlayerDataLoad((PMSG_CHARMAPJOIN *)aRecv,index);
		        break;
			}
	    }
		break;
		case 0xDB:
		    protoNum = 0xD7;
			aRecv[2] = 0xD7;
		break;
		case 0x03:
			gObjPlayerLoad(index);
		break;
		case 0x1E:
		FixSkillsNoWeapor(aRecv,index);
		break;
		case 0xBC:
		   if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 1)
			{
			    return;
			}
		break;
	}

	ProtocolCore(protoNum, aRecv, aLen, index, Encrypt, serial);
}

void gObjPlayerDataLoad(PMSG_CHARMAPJOIN * lpRecv, int index)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	PLAYER_INFOR pDataServer;

	PHeadSetB((LPBYTE)&pDataServer, 0xE0, sizeof(pDataServer));

	memcpy(pDataServer.account, player->AccountID, 10);
	memcpy(pDataServer.name, lpRecv->name, 10);
	pDataServer.index = index;

	DataServerSend((BYTE*)&pDataServer, pDataServer.h.size);
}

void gObjPlayerLoad(int index)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	LogAddFuncColor(3,"packet recebido: conta : %s - nome : %s - vip : %d - resets : %d",player->AccountID,player->Name,player_struct[index].vip,player_struct[index].resets);

	char message[255];
	wsprintf(message,cfg.message[player_struct[index].vip],player->Name);
	GCServerMsgStringSend(message,index,cfg.color[player_struct[index].vip]);

	/* */
	gClient.GSMixLevel(player);

	/* */
	gClient.GSPointsUP(player);

	/* */
	gClient.GSCalChart(player);

	/* */
	gClient.GSMainOpts(player);

	/* */
	PMSG_NAME n;
	PHeadSetB((LPBYTE)&n, 0xFE, sizeof(n));
	memcpy(n.name, player->Name, sizeof(n.name));
	DataSend(index,(unsigned char *)&n,n.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s",n.name);

	/* */
	if((player->Authority & 2) == 2 || (player->Authority & 8) == 8 || (player->Authority & 32) == 32)
	{
		player->m_ViewSkillState |= 0x1000000;
		GCStateInfoSend(player, 1, player->m_ViewSkillState);
	}

	/* */
	if(player_struct[index].vip > 0)
	{
		if(cfg.hashseal == 0x47FFCB)
		{
			player->m_ViewSkillState |= 0x8000000;
			GCStateInfoSend(player, TRUE, 0x8000000);
		}
	}

}

void gObjGCUseItemRecv(PMSG_USEITEM* lpMsg,int index)
{	
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	CItem* item = &lpObj->pInventory[lpMsg->inventoryPos];
	CItem* add  = &lpObj->pInventory[lpMsg->invenrotyTarget];

	int  option[] = {1,2,4,8,16,32};
	int  luck;
	int  itemR;
	char level;
	char skill;
	char opluck;
	char addopt;
	char addoptex;

	if(cfg.potionactive == 1)
	{
	    if(item->m_Type >= ITEMGET(14,0) && item->m_Type <= ITEMGET(14,6) || item->m_Type >= ITEMGET(14,35) && item->m_Type <= ITEMGET(14,40))
	    {
	        if((GetTickCount() - player_struct[lpObj->m_Index].potiontemp) < cfg.potiontime)
	        {
	            GCInventoryItemDeleteSend(index, 255, 1);
			    return;
	        }
	    }

	    player_struct[lpObj->m_Index].potiontemp = GetTickCount();
	}

	if(item->m_Type == ITEMGET(14,63)) //Jewel Excellente
	{	
		if(add->m_NewOption >= 1)
		{
			message(lpObj->m_Index,45,0);
			return;
		}
		add->m_NewOption = option[Rand(0,5)];
		GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,64)) //Jewel Level + 13
	{	
		if(add->m_Level >= 13)
		{
			message(lpObj->m_Index,46,0);
			return;
		}
		add->m_Level = 13;
        GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,65)) //Jewel Anciet
	{	
		if(add->m_SetOption >= 3)
		{
			message(lpObj->m_Index,47,0);
			return;
		}
		for(int x = 1; x < 6; x++)
		{
		   add->m_SetOption = x;
		}
        GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,66)) //Jewel Luck
	{	
		if(add->m_Option2 == 1)
		{
			message(lpObj->m_Index,48,0);
			return;
		}
		add->m_Option2 = 1;
        GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,67)) //Jewel Skill
	{	
		if(add->m_Option1 == 1)
		{
			message(lpObj->m_Index,49,0);
			return;
		}
		add->m_Option1 = 1;
        GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,68)) //Jewel Level
	{	
		if(add->m_Level == 15)
		{
			message(lpObj->m_Index,50,0);
			return;
		}
		add->m_Level++;
        GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(item->m_Type == ITEMGET(14,69)) //Jewel Option life
	{	
		if(add->m_Option3 >= 4)
		{
			message(lpObj->m_Index,51,0);
			return;
		}
		add->m_Option3 = 4;
		GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}
	if(item->m_Type == ITEMGET(14,72)) //Jewel Reset
	{
		player_struct[lpObj->m_Index].resets++;
	    GCServerMsgStringSend("joia do reset: resetado",lpObj->m_Index,0);
		GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);

	    RESET_SEND pReset;
	    PHeadSetB((LPBYTE)&pReset, 0xE2, sizeof(pReset));
	    memcpy(pReset.name, lpObj->Name, sizeof(pReset.name));
	    DataServerSend((BYTE*)&pReset, pReset.h.size);
	    LogAddFuncColor(3,"packet enviado: nome : %s - reset update",lpObj->Name);
	}

	if(item->m_Type == ITEMGET(14,73)) //Jewel Remove Anciet
	{	
		if(add->m_SetOption < 1)
		{
		    GCServerMsgStringSend("seu item não é anciet",lpObj->m_Index,3);
			return;
		}
		add->m_SetOption = 0;
		GCDeleteItemConvert(index,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	CGUseItemRecv(lpMsg,index);
}

void GCDeleteItemConvert(int index, char slot, char target)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	gObjInventoryDeleteItem(index, slot);
	GCInventoryItemDeleteSend(index, slot, 1);
	GCInventoryItemOneSend(index, target);	
	lpObj->pInventory[target].Convert(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Option1, lpObj->pInventory[target].m_Option2, lpObj->pInventory[target].m_Option3, lpObj->pInventory[target].m_NewOption,lpObj->pInventory[target].m_SetOption, lpObj->pInventory[target].m_ItemOptionEx,3);
}