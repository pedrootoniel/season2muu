#include "stdafx.h"

resetconfig rStart[255];
resetconfig rStarted;

void resetconfig::load()
{
    this->count = 0;
    memset(rStart, 0, sizeof(rStart));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\reset.season"), group);

	if(group.GetSection(0, section))
	{
		this->active[0]         = section.Rows[0].GetInt(0);
		this->active[1]         = section.Rows[1].GetInt(0);
		this->active[2]         = section.Rows[2].GetInt(0);
		this->active[3]         = section.Rows[3].GetInt(0);

		this->type[0]           = section.Rows[0].GetInt(1);
		this->type[1]           = section.Rows[1].GetInt(1);
		this->type[2]           = section.Rows[2].GetInt(1);
		this->type[3]           = section.Rows[3].GetInt(1);

		this->move[0]           = section.Rows[0].GetInt(2);
		this->move[1]           = section.Rows[1].GetInt(2);
		this->move[2]           = section.Rows[2].GetInt(2);
		this->move[3]           = section.Rows[3].GetInt(2);

		this->leadership[0]     = section.Rows[0].GetInt(3);
		this->leadership[1]     = section.Rows[1].GetInt(3);
		this->leadership[2]     = section.Rows[2].GetInt(3);
		this->leadership[3]     = section.Rows[3].GetInt(3);
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{ 
			rStart[this->count].vip          = section.Rows[i].GetInt(0);
			rStart[this->count].resetmin     = section.Rows[i].GetInt(1);
			rStart[this->count].resetmax     = section.Rows[i].GetInt(2);
			rStart[this->count].level        = section.Rows[i].GetInt(3);
			rStart[this->count].money        = section.Rows[i].GetInt(4);
			rStart[this->count].points       = section.Rows[i].GetInt(5);
			this->count++;
		}
	}
}

void resetconfig::ResetStart(LPOBJ lpObj)
{
	if(this->active[player_struct[lpObj->m_Index].vip] == 0)
	{
		message(lpObj->m_Index,37,0);
		return;
	}

	for(int i = 0; i < this->count; i++)
	{
		if(player_struct[lpObj->m_Index].vip == rStart[i].vip)
		{
			if(player_struct[lpObj->m_Index].resets >= rStart[i].resetmin && player_struct[lpObj->m_Index].resets <= rStart[i].resetmax)
			{
				if(lpObj->Level < rStart[i].level)
				{
					message(lpObj->m_Index,38,rStart[i].level);
					return;
				}

				if(lpObj->Money < rStart[i].money)
				{
					message(lpObj->m_Index,39,rStart[i].money);
					return;
				}

				lpObj->Experience        = 1;
				lpObj->NextExp           = 100;
				lpObj->Level             = 1;
				lpObj->Money            -= rStart[i].money;

				player_struct[lpObj->m_Index].resets++;

				if(this->type[player_struct[lpObj->m_Index].vip] == 1)
				{
					lpObj->LevelUpPoint = player_struct[lpObj->m_Index].resets * rStart[i].points;
	                lpObj->Strength     = 25;
	                lpObj->Dexterity    = 25;
	                lpObj->Vitality     = 25;
					lpObj->MaxLife      = lpObj->VitalityToLife * 25;
	                lpObj->Energy       = 25;
					lpObj->MaxMana      = lpObj->EnergyToMana * 25;

					if(this->leadership[player_struct[lpObj->m_Index].vip] == 1)
					{
	                    lpObj->Leadership = 25;
					}

	                GCReFillSend(lpObj->m_Index,(WORD)lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
                    gObjSetBP(lpObj->m_Index);
	                GCManaSend(lpObj->m_Index,(short)lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
				}

				if(this->move[player_struct[lpObj->m_Index].vip] == 1)
				{
		            if(lpObj->DbClass == 0 || lpObj->DbClass == 1 || lpObj->DbClass == 16 || lpObj->DbClass == 17 || lpObj->DbClass == 48 || lpObj->DbClass == 64)
		            {
			            gObjTeleport(lpObj->m_Index,0,140,135);
		            }
		            if(lpObj->DbClass == 32 || lpObj->DbClass == 33)
		            {
			            gObjTeleport(lpObj->m_Index,3,174,114);
					}
				}

				//
	            RESET_SEND pReset;

	            PHeadSetB((LPBYTE)&pReset, 0xE2, sizeof(pReset));
	            memcpy(pReset.name, lpObj->Name, sizeof(pReset.name));
	            DataServerSend((BYTE*)&pReset, pReset.h.size);
	            LogAddFuncColor(3,"packet enviado: nome : %s - reset update",lpObj->Name);

				gClient.GSResetUP(lpObj);
				GCMoneySend(lpObj->m_Index,lpObj->Money);
				gObjCalCharacter(lpObj->m_Index);
				message(lpObj->m_Index,40,player_struct[lpObj->m_Index].resets);
				return;
			}
		}
	}

	message(lpObj->m_Index,41,0);
}