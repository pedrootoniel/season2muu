#include "stdafx.h"

GSClient gClient;

GSClient::GSClient()
{
}

GSClient::~GSClient()
{
}

void GSClient::GSPointsUP(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->p, 0xFF, 0, sizeof(this->p));

	this->p.points    = player->LevelUpPoint;

	DataSend(player->m_Index,(unsigned char *)&this->p,this->p.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, %d pontos",player->Name,this->p.points);
}

void GSClient::GSStatsUP(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->s, 0xFF, 1, sizeof(this->s));

	this->s.forca       = player->Strength;
	this->s.agilidade   = player->Dexterity;
	this->s.vitalidade  = player->Vitality;
	this->s.energia     = player->Energy;
	this->s.comando     = player->Leadership;
	this->s.manamax     = player->MaxMana + player->AddMana;

	DataSend(player->m_Index,(unsigned char *)&this->s,this->s.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, força, agilidade, vitalidade, energia",player->Name);
}

void GSClient::GSResetUP(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->r, 0xFF, 2, sizeof(this->r));

	this->r.forca       = player->Strength;
	this->r.agilidade   = player->Dexterity;
	this->r.vitalidade  = player->Vitality;
	this->r.energia     = player->Energy;
	this->r.comando     = player->Leadership;
	this->r.points      = player->LevelUpPoint;
	this->r.exp         = player->Experience;
	this->r.nextexp     = player->NextExp;
	this->r.level       = player->Level;

	DataSend(player->m_Index,(unsigned char *)&this->r,this->r.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, força, agilidade, vitalidade, energia, level, exp",player->Name);
}

void GSClient::GSMixLevel(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->g, 0xFF, 3, sizeof(this->g));

	this->g.mix10     = cfg.mix10[player_struct[player->m_Index].vip];
	this->g.mix10luck = cfg.mix10luck[player_struct[player->m_Index].vip];
	this->g.mix11     = cfg.mix11[player_struct[player->m_Index].vip];
	this->g.mix11luck = cfg.mix11luck[player_struct[player->m_Index].vip];
	this->g.mix12     = cfg.mix12[player_struct[player->m_Index].vip];
	this->g.mix12luck = cfg.mix12luck[player_struct[player->m_Index].vip];
	this->g.mix13     = cfg.mix13[player_struct[player->m_Index].vip];
	this->g.mix13luck = cfg.mix13luck[player_struct[player->m_Index].vip];
	#if DLLtype == 0
	this->g.fenrir1   = *(DWORD*)0x9F47D3C;
	this->g.fenrir2   = *(DWORD*)0x9F47D38;
	this->g.fenrir3   = *(DWORD*)0x9F47D34;
    #else
	this->g.fenrir1   = *(DWORD*)0x5D94DF0;
	this->g.fenrir2   = *(DWORD*)0x5D94DEC;
	this->g.fenrir3   = *(DWORD*)0x5D94DE8;
    #endif

	DataSend(player->m_Index,(unsigned char *)&this->g,this->g.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, vip: %d - globin level mix",player->Name,player_struct[player->m_Index].vip);
}

void GSClient::GSCalChart(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->c, 0xFF, 4, sizeof(this->c));

	this->c.elf1   = GetPrivateProfileInt("calcharacter","config_41", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.elf2   = GetPrivateProfileInt("calcharacter","config_42", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.bkmg1  = GetPrivateProfileInt("calcharacter","config_43", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.bkmg2  = GetPrivateProfileInt("calcharacter","config_44", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.dl1    = GetPrivateProfileInt("calcharacter","config_45", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.dl2    = GetPrivateProfileInt("calcharacter","config_46", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.sm1    = GetPrivateProfileInt("calcharacter","config_47", 0, ".\\configurações\\customizações\\calcharacter.season");
	this->c.sm2    = GetPrivateProfileInt("calcharacter","config_48", 0, ".\\configurações\\customizações\\calcharacter.season");

	DataSend(player->m_Index,(unsigned char *)&this->c,this->c.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, calcharacter speed",player->Name);
}

void GSClient::GSMainOpts(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->m, 0xFF, 5, sizeof(this->m));

	this->m.skillsiege = cfg.skillsiege;
	this->m.reflete    = cfg.reflete;

	DataSend(player->m_Index,(unsigned char *)&this->m,this->m.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, options main",player->Name);
}

