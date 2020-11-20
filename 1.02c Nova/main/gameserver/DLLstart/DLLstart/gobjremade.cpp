#include "stdafx.h"

void gObjLotteryItemMix(OBJECTSTRUCT* lpObj) 
{ 
	for(int i = 0; i < 32; i++) 
	{ 
		if(lpObj->pChaosBox[i].m_Type == ITEMGET(14, 54)) 
		{ 
			LotteryItemMix(lpObj); 
			return;
		}
	} 
}

void gObjGCLevelUpMsgSend(int aIndex, int iSendEffect)
{
	GCLevelUpMsgSend(aIndex,iSendEffect);

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	gClient.GSPointsUP(lpObj);
}

BOOL gObjgObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo)
{
	if(lpObj->Type == 1)	
	{
	    if(!(lpObj->pInventory[8].m_Type >= ITEMGET(13,0) && lpObj->pInventory[8].m_Type <= ITEMGET(13, 5) || lpObj->pInventory[8].m_Type == ITEMGET(13, 37)))
	    {
		    GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
	    }
	}

	if(lpTargetObj->Type == 1)	
	{
	    if(!(lpTargetObj->pInventory[8].m_Type >= ITEMGET(13,0) && lpTargetObj->pInventory[8].m_Type <= ITEMGET(13, 5) || lpTargetObj->pInventory[8].m_Type == ITEMGET(13, 37)))
	    {
		    GCInventoryItemDeleteSend(lpTargetObj->m_Index, 8, 0);
	    }
	}

	if(lpTargetObj->Type == 1)
	{
	    if((lpTargetObj->Authority & 2) == 2 || (lpTargetObj->Authority & 8) == 8 || (lpTargetObj->Authority & 32) == 32)
	    {
			GCDamageSend(lpObj->m_Index, lpTargetObj->m_Index, 0, 0, 0, 0);
			return TRUE;
		}
	}

	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}

int ratedrops(LPOBJ lpObj)
{
	return cfg.drops[player_struct[lpObj->m_Index].vip];
}

void __declspec(naked) gObjItemDrop()
{
	_asm
	{
	mov eax, dword ptr ds:[ebp+0xC]
	push eax
	call ratedrops
	#if DLLtype == 0
    mov dword ptr ss:[ebp-0xD0],eax
	#else
	mov dword ptr ss:[ebp-0xC4],eax
    #endif
    mov eax, dword ptr ss:[ebp+0xC]
    xor ecx, ecx
    mov cl,byte ptr ds:[eax+0xFD5]
	#if DLLtype == 0
    mov eax, dword ptr ss:[ebp-0xD0]
	#else
	mov eax, dword ptr ss:[ebp-0xC4]
    #endif
	#if DLLtype == 0
	mov edi, 0x0041B11E
    #else
	mov edi, 0x0041CB8E
    #endif
	jmp edi
	}
}

int rateluck(int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	return cfg.soulluck[player_struct[player->m_Index].vip];
}

__declspec(naked) void gObjSoulRateLuck()
{
	_asm
	{
    mov edx, dword ptr ss:[ebp+8]
    mov eax, dword ptr ds:[edx]
    push eax
	call rateluck
    cmp dword ptr ss:[ebp-4],eax
    jge pule
	#if DLLtype == 0
	mov edi, 0x004FE982
    #else
	mov edi, 0x00511CD2
    #endif
	jmp edi
pule:
	#if DLLtype == 0
	mov edi, 0x004FE9B9
    #else
	mov edi, 0x00511D09
    #endif
	jmp edi
	}
}

int ratenoluck(int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	return cfg.soulnoluck[player_struct[player->m_Index].vip];
}

__declspec(naked) void gObjSoulRateNoLuck()
{
	_asm
	{
    mov edx, dword ptr ss:[ebp+8]
    mov eax, dword ptr ds:[edx]
    push eax
	call ratenoluck
    cmp dword ptr ss:[ebp-4],eax
    jge pule
	#if DLLtype == 0
	mov edi, 0x004FEA65
    #else
	mov edi, 0x00511DB5
    #endif
	jmp edi
pule:
	#if DLLtype == 0
	mov edi, 0x004FEB04
    #else
	mov edi, 0x00511E54
    #endif
	jmp edi
	}
}

int ratelife(int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	return cfg.life[player_struct[player->m_Index].vip];
}

__declspec(naked) void gObjLifeRate()
{
	_asm
	{
    mov edx, dword ptr ss:[ebp+8]
    mov eax, dword ptr ds:[edx]
    push eax
	call ratelife
    cmp dword ptr ss:[ebp-4],eax
    jge pule
	#if DLLtype == 0
	mov edi, 0x004FF1F0
    #else
	mov edi, 0x00512540
    #endif
	jmp edi
pule:
	#if DLLtype == 0
	mov edi, 0x004FF209
    #else
	mov edi, 0x00512559
    #endif
	jmp edi
	}
}

int elfsoldier(LPOBJ lpObj)
{
	return cfg.levelsoldier[player_struct[lpObj->m_Index].vip];
}

__declspec(naked) void gObjElfSoldier()
{
	int result;

	_asm
	{
    mov eax, dword ptr ss:[ebp+0xC]
    push eax
	call elfsoldier
	mov result, eax
    mov edx, dword ptr ss:[ebp+0xC]
    movsx eax, word ptr ds:[edx+0xA0]
    cmp eax,result
	jle jump
	#if DLLtype == 0
	mov edi, 0x00554DF6
    #else
	mov edi, 0x0058B106
    #endif
	jmp edi
jump:
	#if DLLtype == 0
	mov edi, 0x00554E11
    #else
	mov edi, 0x0058B121
    #endif
	jmp edi
	}
}

void ratemixlevel(int pos, LPOBJ lpObj)
{
	if(lpObj->pChaosBox[pos].m_Level == 9)
	{
		lpObj->ChaosSuccessRate = cfg.mix10[player_struct[lpObj->m_Index].vip];

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += cfg.mix10luck[player_struct[lpObj->m_Index].vip];
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 10)
	{
		lpObj->ChaosSuccessRate = cfg.mix11[player_struct[lpObj->m_Index].vip];

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += cfg.mix11luck[player_struct[lpObj->m_Index].vip];
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 11)
	{
		lpObj->ChaosSuccessRate = cfg.mix12[player_struct[lpObj->m_Index].vip];

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += cfg.mix12luck[player_struct[lpObj->m_Index].vip];
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 12)
	{
		lpObj->ChaosSuccessRate = cfg.mix13[player_struct[lpObj->m_Index].vip];

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += cfg.mix13luck[player_struct[lpObj->m_Index].vip];
	    }
	}
}

__declspec(naked) void gObjRateMixLevel()
{
	_asm
	{
	mov edx, dword ptr ss:[ebp+8]
	push edx
    mov ecx, dword ptr ss:[ebp-0x18]
	push ecx
	call ratemixlevel
	#if DLLtype == 0
	mov edi, 0x004966FB
    #else
	mov edi, 0x004A74CB
    #endif
	jmp edi
	}
}

void GMMessageSend(LPOBJ lpObj, char * msg)
{
	char mensagem[255];
	wsprintf(mensagem,"%s: %s",lpObj->Name,msg);
	AllSendServerMsg(mensagem);
}

__declspec(naked) void gObjGMGlobalMsg()
{
	_asm
	{
    mov ecx,dword ptr ss:[ebp+8]
    add ecx,0x0E
    push ecx
    mov edx,dword ptr ss:[ebp-8]
    push edx
    call GMMessageSend
	#if DLLtype == 0
	mov edi, 0x00432384
    #else
	mov edi, 0x00435344
    #endif
	jmp edi
	}
}

int zendrop(int money)
{
	if(cfg.zentype == 1)
	{
		money = money * cfg.zenmix;
	}
	if(cfg.zentype == 2)
	{
		money = money / cfg.zenmix;
	}

	if(money < 1)
	{
		money = 1;
		LogAddFuncColor(2,"sistema de zen com configuração ultrapassada");
	}

	return money;
}

void __declspec(naked) gObjZen()
{
	_asm
	{
        mov dword ptr ss:[ebp-4],ecx
        mov dword ptr ss:[ebp-0xC],0
		mov eax,dword ptr ss:[ebp+8]
		push eax
		call zendrop
		mov dword ptr ss:[ebp+8],eax
		#if DLLtype == 0
		mov edi, 0x00490573
        #else
		mov edi, 0x004A1343
        #endif
		jmp edi
	}
}

void gObjGameMonsterAllAdd()
{
	GameMonsterAllAdd();
	npc.load();
}

short gObjInsertMonster(int Map, int X, int Y, int Class, int Dir, int Type)
{
	short npc = gObjAddMonster(Map);

	if(npc == -1)
	{
		return -1;
	}

	gObjSetMonster(npc, Class);

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(npc);

	lpObj->Type		 = Type;
	lpObj->X		     = X;
	lpObj->Y		     = Y;
	lpObj->MapNumber = Map;
	lpObj->TX		 = lpObj->X;
	lpObj->TY		 = lpObj->Y;
	lpObj->m_OldX	 = lpObj->X;
	lpObj->m_OldY	 = lpObj->Y;
	lpObj->Dir		 = Dir;
	lpObj->StartX	 = (unsigned char)lpObj->X;
	lpObj->StartY	 = (unsigned char)lpObj->Y;

	if(Type == 3)
	{
		lpObj->m_MoveRange   = 0;
		lpObj->m_AttackRange = 0;
	}

	return npc;
}

void gObjSavePetItemInfo(int aIndex, int inventype)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	char pbuffer[2048];

	int lofs           = sizeof(SDHP_SAVE_PETITEM);
	int founditemcount = 0;

	SAVE_PETITEM petinfo;

	if(inventype == 0)
	{
		for(int n = 0; n < 108; n++)
		{
			if(lpObj->pInventory[n].IsItem())
			{
				if(lpObj->pInventory[n].m_Type == ITEMGET(13,4) || lpObj->pInventory[n].m_Type == ITEMGET(13,5))
				{
					if(lpObj->pInventory[n].m_IsLoadPetItemInfo != FALSE)
					{
						founditemcount++;
						petinfo.serial = lpObj->pInventory[n].m_Number;
						petinfo.level  = lpObj->pInventory[n].m_PetItem_Level;
						petinfo.exp    = lpObj->pInventory[n].m_PetItem_Exp;
						memcpy(&pbuffer[lofs], &petinfo, sizeof(petinfo));
						lofs          += sizeof(petinfo);
					}
				}
			}
		}
	}
	else if(inventype == 1)
	{
		for(int n = 0; n < 120; n++)
		{
			if(lpObj->pWarehouse[n].IsItem())
			{
				if(lpObj->pWarehouse[n].m_Type == ITEMGET(13,4) || lpObj->pWarehouse[n].m_Type == ITEMGET(13,5))
				{
					if(lpObj->pWarehouse[n].m_IsLoadPetItemInfo != FALSE)
					{
						founditemcount++;
						petinfo.serial = lpObj->pWarehouse[n].m_Number;
						petinfo.level  = lpObj->pWarehouse[n].m_PetItem_Level;
						petinfo.exp    = lpObj->pWarehouse[n].m_PetItem_Exp;
						memcpy(&pbuffer[lofs], &petinfo, sizeof(petinfo));
						lofs          += sizeof(petinfo);
					}
				}
			}
		}
	}

	if(founditemcount)
	{
		SDHP_SAVE_PETITEM pMsg;
		pMsg.h.set((LPBYTE)&pMsg, 0x57, lofs+sizeof(pMsg));
		pMsg.count = founditemcount;
		memcpy(pbuffer, &pMsg, sizeof(pMsg));
		DataServerSend((BYTE*)pbuffer, lofs+sizeof(pMsg));
	}
}

int gObjDrop(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	short map;
	short monster;

	for(int i = 0; i < dropd.count; i++)
	{
		if(droparray[i].mapa == -1)
		{
			map = lpObj->MapNumber;
		}
		else
		{
			map = droparray[i].mapa;
		}
		if(droparray[i].monstro == -1)
		{
			monster = lpObj->Class;
		}
		else
		{
			monster = droparray[i].monstro;
		}

		if(lpObj->MapNumber == map)
		{
			if(lpObj->Class == monster)
			{
				if(lpObj->Level >= droparray[i].minlevel && lpObj->Level <= droparray[i].maxlevel)
				{
					if(rand()%10000 < droparray[i].porcentagem)
				    {
					    int hitdmg = gObjMonsterTopHitDamageUser(lpObj);
					    int number = ItemGetNumberMake(droparray[i].index, droparray[i].id);
                        ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X, lpObj->Y,number,droparray[i].level, 0,droparray[i].skill,droparray[i].luck,droparray[i].addopt,hitdmg,droparray[i].addoptex,0);
						return true;
					}
				}
			}
		}
	}

	return gObjMonsterDrop(lpObj, lpTargetObj);
}

void gObjJGAnsMapSvrAuth(PMSG_ANS_MAPSVRAUTH * lpRecv)
{
	JGAnsMapSvrAuth(lpRecv);

	PLAYER_INFOR pDataServer;

	PHeadSetB((LPBYTE)&pDataServer, 0xE0, sizeof(pDataServer));

	strcpy(pDataServer.account, lpRecv->account);
	strcpy(pDataServer.name, lpRecv->name);
	pDataServer.index = lpRecv->index;

	DataServerSend((BYTE*)&pDataServer, pDataServer.h.size);
}