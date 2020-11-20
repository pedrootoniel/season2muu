#include "stdafx.h"

addPoints ap[65];

void addPoints::load()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\pontos.season"), group);

	if(group.GetSection(0, section))
	{
		//dark wizard
		ap[0].forca         = section.Rows[0].GetInt(0);
		ap[0].agilidade     = section.Rows[0].GetInt(1);
		ap[0].vitalidade    = section.Rows[0].GetInt(2);
		ap[0].energia       = section.Rows[0].GetInt(3);
		//soul master
		ap[1].forca         = section.Rows[1].GetInt(0);
		ap[1].agilidade     = section.Rows[1].GetInt(1);
		ap[1].vitalidade    = section.Rows[1].GetInt(2);
		ap[1].energia       = section.Rows[1].GetInt(3);
		//dark knight
		ap[16].forca        = section.Rows[2].GetInt(0);
		ap[16].agilidade    = section.Rows[2].GetInt(1);
		ap[16].vitalidade   = section.Rows[2].GetInt(2);
		ap[16].energia      = section.Rows[2].GetInt(3);
		//blade knight
		ap[17].forca        = section.Rows[3].GetInt(0);
		ap[17].agilidade    = section.Rows[3].GetInt(1);
		ap[17].vitalidade   = section.Rows[3].GetInt(2);
		ap[17].energia      = section.Rows[3].GetInt(3);
		//fairy elf
		ap[32].forca        = section.Rows[4].GetInt(0);
		ap[32].agilidade    = section.Rows[4].GetInt(1);
		ap[32].vitalidade   = section.Rows[4].GetInt(2);
		ap[32].energia      = section.Rows[4].GetInt(3);
		//muse elf
		ap[33].forca        = section.Rows[5].GetInt(0);
		ap[33].agilidade    = section.Rows[5].GetInt(1);
		ap[33].vitalidade   = section.Rows[5].GetInt(2);
		ap[33].energia      = section.Rows[5].GetInt(3);
		//magic gladiador
		ap[48].forca        = section.Rows[6].GetInt(0);
		ap[48].agilidade    = section.Rows[6].GetInt(1);
		ap[48].vitalidade   = section.Rows[6].GetInt(2);
		ap[48].energia      = section.Rows[6].GetInt(3);
		//dark lord
		ap[64].forca        = section.Rows[7].GetInt(0);
		ap[64].agilidade    = section.Rows[7].GetInt(1);
		ap[64].vitalidade   = section.Rows[7].GetInt(2);
		ap[64].energia      = section.Rows[7].GetInt(3);
		ap[64].comando      = section.Rows[7].GetInt(4);
	}

	gObjStatus();
}

bool gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj)
{
	if(lpObj->Type > 3)
	{
		return FALSE;
	}

	if(lpObj->LevelUpPoint < 1)
	{
		return FALSE;
	}

	switch(type)
	{
	    case 0: //----------- força
		if(lpObj->Strength >= ap[lpObj->DbClass].forca)
		{
			message(lpObj->m_Index,0,ap[lpObj->DbClass].forca);
			return FALSE;
		}
		else
		{
	        lpObj->Strength++;
		}
	    break;
	    case 1: //----------- agilidade
		if(lpObj->Dexterity >= ap[lpObj->DbClass].agilidade)
		{
			message(lpObj->m_Index,1,ap[lpObj->DbClass].agilidade);
			return FALSE;
		}
		else
		{
	        lpObj->Dexterity++;
		}
	    break;
	    case 2: //----------- vitalidade
		if(lpObj->Vitality >= ap[lpObj->DbClass].vitalidade)
		{
			message(lpObj->m_Index,2,ap[lpObj->DbClass].vitalidade);
			return FALSE;
		}
		else
		{
	        lpObj->Vitality++;
	        lpObj->MaxLife += lpObj->VitalityToLife;
	        gObjCalcMaxLifePower(lpObj->m_Index);
		}
		break;
	    case 3: //----------- energia
		if(lpObj->Energy >= ap[lpObj->DbClass].energia)
		{
			message(lpObj->m_Index,3,ap[lpObj->DbClass].energia);
			return FALSE;
		}
		else
		{
	        lpObj->Energy++;
	        lpObj->MaxMana += lpObj->EnergyToMana;
		}
		break;
	    case 4: //----------- comando
	    if(lpObj->Leadership >= ap[lpObj->DbClass].comando)
		{
			message(lpObj->m_Index,4,ap[lpObj->DbClass].comando);
		    return FALSE;
		}
		else
		{
	        lpObj->Leadership++;
		}
		break;
	}

	lpObj->LevelUpPoint--;
	gClient.GSPointsUP(lpObj);
	gObjCalCharacter(lpObj->m_Index);
	return TRUE;
}

void gObjStatus()
{
	#if DLLtype == 0
	*(BYTE*)(0x0044F25E+1)    = 0xB7;
	*(BYTE*)(0x0044F2CB+1)    = 0xB7;
	*(BYTE*)(0x00488297+1)    = 0xB7;
	*(BYTE*)(0x004B1DB4+1)    = 0xB7;
	*(BYTE*)(0x004B1DCD+1)    = 0xB7;
	*(BYTE*)(0x004B1DE6+1)    = 0xB7;
	*(BYTE*)(0x004B1DFF+1)    = 0xB7;
	*(BYTE*)(0x004B21A1+1)    = 0xB7;
	*(BYTE*)(0x004B21B5+1)    = 0xB7;
	*(BYTE*)(0x004B21C9+1)    = 0xB7;
	*(BYTE*)(0x004B21DD+1)    = 0xB7;
	*(BYTE*)(0x004B2209+1)    = 0xB7;
	*(BYTE*)(0x004B221D+1)    = 0xB7;
	*(BYTE*)(0x004B2231+1)    = 0xB7;
	*(BYTE*)(0x004B2245+1)    = 0xB7;
	*(BYTE*)(0x004B2272+1)    = 0xB7;
	*(BYTE*)(0x004B2286+1)    = 0xB7;
	*(BYTE*)(0x004B229A+1)    = 0xB7;
	*(BYTE*)(0x004B22AE+1)    = 0xB7;
	*(BYTE*)(0x004B22C7+1)    = 0xB7;
	*(BYTE*)(0x004B22DB+1)    = 0xB7;
	*(BYTE*)(0x004B22EF+1)    = 0xB7;
	*(BYTE*)(0x004B2303+1)    = 0xB7;
	*(BYTE*)(0x004B2BDA+1)    = 0xB7;
	*(BYTE*)(0x004B37E1+1)    = 0xB7;
	*(BYTE*)(0x004B4A45+1)    = 0xB7;
	*(BYTE*)(0x004B4AD7+1)    = 0xB7;
	*(BYTE*)(0x004B4AF7+1)    = 0xB7;
	*(BYTE*)(0x004B53FF+1)    = 0xB7;
	*(BYTE*)(0x004B6B41+1)    = 0xB7;
	*(BYTE*)(0x004B6B61+1)    = 0xB7;
	*(BYTE*)(0x004B6BDB+1)    = 0xB7;
	*(BYTE*)(0x004B6BFB+1)    = 0xB7;
	*(BYTE*)(0x004B6E95+1)    = 0xB7;
	*(BYTE*)(0x004B6ED8+1)    = 0xB7;
	*(BYTE*)(0x004B6F11+1)    = 0xB7;
	*(BYTE*)(0x004B6F51+1)    = 0xB7;
	*(BYTE*)(0x004B6F90+1)    = 0xB7;
	*(BYTE*)(0x004B6FC1+1)    = 0xB7;
	*(BYTE*)(0x004B6FFC+1)    = 0xB7;
	*(BYTE*)(0x004B7037+1)    = 0xB7;
	*(BYTE*)(0x004B7072+1)    = 0xB7;
	*(BYTE*)(0x004B70AD+1)    = 0xB7;
	*(BYTE*)(0x004B99CB+1)    = 0xB7;
	*(BYTE*)(0x004B99EB+1)    = 0xB7;
	*(BYTE*)(0x004B9A15+1)    = 0xB7;
	*(BYTE*)(0x004B9DD7+1)    = 0xB7;
	*(BYTE*)(0x004B9DF7+1)    = 0xB7;
	*(BYTE*)(0x004B9E22+1)    = 0xB7;
	*(BYTE*)(0x004B9FA5+1)    = 0xB7;
	*(BYTE*)(0x004BA236+1)    = 0xB7;
	*(BYTE*)(0x004BA9F0+1)    = 0xB7;
	*(BYTE*)(0x004BAB32+1)    = 0xB7;
	*(BYTE*)(0x004BDC99+1)    = 0xB7;
	*(BYTE*)(0x004BDCBC+1)    = 0xB7;
	*(BYTE*)(0x004C2A89+1)    = 0xB7;
	*(BYTE*)(0x004C2AA2+1)    = 0xB7;
	*(BYTE*)(0x004C2ABB+1)    = 0xB7;
	*(BYTE*)(0x004C2AD4+1)    = 0xB7;
	*(BYTE*)(0x004C706C+1)    = 0xB7;
	*(BYTE*)(0x004C70A2+1)    = 0xB7;
	*(BYTE*)(0x004C70D8+1)    = 0xB7;
	*(BYTE*)(0x004C710E+1)    = 0xB7;
	*(BYTE*)(0x004C7144+1)    = 0xB7;
	*(BYTE*)(0x004C7A4C+1)    = 0xB7;
	*(BYTE*)(0x004C7A91+1)    = 0xB7;
	*(BYTE*)(0x004C7AD6+1)    = 0xB7;
	*(BYTE*)(0x004C7B51+1)    = 0xB7;
	*(BYTE*)(0x004C7C33+1)    = 0xB7;
	*(BYTE*)(0x004C7C49+1)    = 0xB7;
	*(BYTE*)(0x004C7C61+1)    = 0xB7;
	*(BYTE*)(0x004C7C79+1)    = 0xB7;
	*(BYTE*)(0x004C940E+1)    = 0xB7;
	*(BYTE*)(0x004C9427+1)    = 0xB7;
	*(BYTE*)(0x004C9440+1)    = 0xB7;
	*(BYTE*)(0x004C9459+1)    = 0xB7;
	*(BYTE*)(0x004CA9E5+1)    = 0xB7;
	*(BYTE*)(0x004CAA28+1)    = 0xB7;
	*(BYTE*)(0x004CAA61+1)    = 0xB7;
	*(BYTE*)(0x004CAAA1+1)    = 0xB7;
	*(BYTE*)(0x004CAAE0+1)    = 0xB7;
	*(BYTE*)(0x004CAB11+1)    = 0xB7;
	*(BYTE*)(0x004CAB4C+1)    = 0xB7;
	*(BYTE*)(0x004CAB87+1)    = 0xB7;
	*(BYTE*)(0x004CABC2+1)    = 0xB7;
	*(BYTE*)(0x004CABFD+1)    = 0xB7;
	*(BYTE*)(0x004D3672+1)    = 0xB7;
	*(BYTE*)(0x004D3697+1)    = 0xB7;
	*(BYTE*)(0x004D36BC+1)    = 0xB7;
	*(BYTE*)(0x004D36E1+1)    = 0xB7;
	*(BYTE*)(0x004D47BC+1)    = 0xB7;
	*(BYTE*)(0x004D485B+1)    = 0xB7;
	*(BYTE*)(0x004D61D0+1)    = 0xB7;
	*(BYTE*)(0x004D61DB+1)    = 0xB7;
	*(BYTE*)(0x004D61E6+1)    = 0xB7;
	*(BYTE*)(0x004D61F1+1)    = 0xB7;
	*(BYTE*)(0x004E7D66+1)    = 0xB7;
	*(BYTE*)(0x004E7D9E+1)    = 0xB7;
	*(BYTE*)(0x004E7E0D+1)    = 0xB7;
	*(BYTE*)(0x004E7E37+1)    = 0xB7;
	*(BYTE*)(0x004FD675+1)    = 0xB7;
	*(BYTE*)(0x004FDB21+1)    = 0xB7;
	*(BYTE*)(0x004FE0AC+1)    = 0xB7;
	*(BYTE*)(0x00502313+1)    = 0xB7;
	*(BYTE*)(0x0050231D+1)    = 0xB7;
	*(BYTE*)(0x00502329+1)    = 0xB7;
	*(BYTE*)(0x00502335+1)    = 0xB7;
	*(BYTE*)(0x0050258D+1)    = 0xB7;
	*(BYTE*)(0x00502597+1)    = 0xB7;
	*(BYTE*)(0x005025A3+1)    = 0xB7;
	*(BYTE*)(0x005025AF+1)    = 0xB7;
	*(BYTE*)(0x0050277D+1)    = 0xB7;
	*(BYTE*)(0x00502787+1)    = 0xB7;
	*(BYTE*)(0x00502793+1)    = 0xB7;
	*(BYTE*)(0x0050279F+1)    = 0xB7;
	*(BYTE*)(0x00503ACD+1)    = 0xB7;
	*(BYTE*)(0x00503B0F+1)    = 0xB7;
	*(BYTE*)(0x00503B51+1)    = 0xB7;
	*(BYTE*)(0x00503B90+1)    = 0xB7;
	*(BYTE*)(0x0050441A+1)    = 0xB7;
	*(BYTE*)(0x0050443D+1)    = 0xB7;
	*(BYTE*)(0x00504460+1)    = 0xB7;
	*(BYTE*)(0x00504483+1)    = 0xB7;
	*(BYTE*)(0x0053F15D+1)    = 0xB7;
	*(BYTE*)(0x0053F171+1)    = 0xB7;
	*(BYTE*)(0x0053F185+1)    = 0xB7;
	*(BYTE*)(0x0053F199+1)    = 0xB7;
	*(BYTE*)(0x0053F356+1)    = 0xB7;
	*(BYTE*)(0x0053F36A+1)    = 0xB7;
	*(BYTE*)(0x0053F37E+1)    = 0xB7;
	*(BYTE*)(0x0053F392+1)    = 0xB7;
	*(BYTE*)(0x0053F59F+1)    = 0xB7;
	*(BYTE*)(0x0053F5B3+1)    = 0xB7;
	*(BYTE*)(0x0053F5C7+1)    = 0xB7;
	*(BYTE*)(0x0053F5DB+1)    = 0xB7;
	*(BYTE*)(0x005819E7+1)    = 0xB7;
	*(BYTE*)(0x005819F8+1)    = 0xB7;
	*(BYTE*)(0x00581A09+1)    = 0xB7;
	*(BYTE*)(0x00581A1A+1)    = 0xB7;
    #else
	*(BYTE*)(0x00451A0E+1)    = 0xB7;
	*(BYTE*)(0x004E4F52+1)    = 0xB7;
	*(BYTE*)(0x00516E60+1)    = 0xB7;
	*(BYTE*)(0x00552819+1)    = 0xB7;
	*(BYTE*)(0x00552A12+1)    = 0xB7;
	*(BYTE*)(0x00552C5B+1)    = 0xB7;
	*(BYTE*)(0x005B54FA+1)    = 0xB7;
	*(BYTE*)(0x00499067+1)    = 0xB7;
	*(BYTE*)(0x004C341E+1)    = 0xB7;
	*(BYTE*)(0x004C380B+1)    = 0xB7;
	*(BYTE*)(0x004C3873+1)    = 0xB7;
	*(BYTE*)(0x004C38DC+1)    = 0xB7;
	*(BYTE*)(0x004C3931+1)    = 0xB7;
	*(BYTE*)(0x004C4FC1+1)    = 0xB7;
	*(BYTE*)(0x004C6295+1)    = 0xB7;
	*(BYTE*)(0x004C6327+1)    = 0xB7;
	*(BYTE*)(0x004C6C4F+1)    = 0xB7;
	*(BYTE*)(0x004C8551+1)    = 0xB7;
	*(BYTE*)(0x004C85EB+1)    = 0xB7;
	*(BYTE*)(0x004D4859+1)    = 0xB7;
	*(BYTE*)(0x004D8E72+1)    = 0xB7;
	*(BYTE*)(0x004D981C+1)    = 0xB7;
	*(BYTE*)(0x004D9A03+1)    = 0xB7;
	*(BYTE*)(0x004DB265+1)    = 0xB7;
	*(BYTE*)(0x004E7CB1+1)    = 0xB7;
	*(BYTE*)(0x004FA336+1)    = 0xB7;
	*(BYTE*)(0x005155E3+1)    = 0xB7;
	*(BYTE*)(0x0051585D+1)    = 0xB7;
	*(BYTE*)(0x00515A4D+1)    = 0xB7;
	*(BYTE*)(0x00451A7B+1)    = 0xB7;
	*(BYTE*)(0x004E4F77+1)    = 0xB7;
	*(BYTE*)(0x00516E21+1)    = 0xB7;
	*(BYTE*)(0x00552805+1)    = 0xB7;
	*(BYTE*)(0x005529FE+1)    = 0xB7;
	*(BYTE*)(0x00552C47+1)    = 0xB7;
	*(BYTE*)(0x005B54E9+1)    = 0xB7;
	*(BYTE*)(0x004C3437+1)    = 0xB7;
	*(BYTE*)(0x004C381F+1)    = 0xB7;
	*(BYTE*)(0x004C3887+1)    = 0xB7;
	*(BYTE*)(0x004C38F0+1)    = 0xB7;
	*(BYTE*)(0x004C3945+1)    = 0xB7;
	*(BYTE*)(0x004C8531+1)    = 0xB7;
	*(BYTE*)(0x004C85CB+1)    = 0xB7;
	*(BYTE*)(0x004C8885+1)    = 0xB7;
	*(BYTE*)(0x004C88C8+1)    = 0xB7;
	*(BYTE*)(0x004C8901+1)    = 0xB7;
	*(BYTE*)(0x004C8941+1)    = 0xB7;
	*(BYTE*)(0x004C8980+1)    = 0xB7;
	*(BYTE*)(0x004C89B1+1)    = 0xB7;
	*(BYTE*)(0x004C89EC+1)    = 0xB7;
	*(BYTE*)(0x004C8A27+1)    = 0xB7;
	*(BYTE*)(0x004C8A62+1)    = 0xB7;
	*(BYTE*)(0x004C8A9D+1)    = 0xB7;
	*(BYTE*)(0x004CB7C7+1)    = 0xB7;
	*(BYTE*)(0x004D4872+1)    = 0xB7;
	*(BYTE*)(0x004D8E3C+1)    = 0xB7;
	*(BYTE*)(0x004D8EDE+1)    = 0xB7;
	*(BYTE*)(0x004D9861+1)    = 0xB7;
	*(BYTE*)(0x004D9A19+1)    = 0xB7;
	*(BYTE*)(0x004DB27E+1)    = 0xB7;
	*(BYTE*)(0x004DC945+1)    = 0xB7;
	*(BYTE*)(0x004DC988+1)    = 0xB7;
	*(BYTE*)(0x004DC9C1+1)    = 0xB7;
	*(BYTE*)(0x004DCA01+1)    = 0xB7;
	*(BYTE*)(0x004DCA40+1)    = 0xB7;
	*(BYTE*)(0x004DCA71+1)    = 0xB7;
	*(BYTE*)(0x004DCAAC+1)    = 0xB7;
	*(BYTE*)(0x004DCAE7+1)    = 0xB7;
	*(BYTE*)(0x004DCB22+1)    = 0xB7;
	*(BYTE*)(0x004DCB5D+1)    = 0xB7;
	*(BYTE*)(0x004E7CA6+1)    = 0xB7;
	*(BYTE*)(0x004FA36E+1)    = 0xB7;
	*(BYTE*)(0x005155ED+1)    = 0xB7;
	*(BYTE*)(0x00515867+1)    = 0xB7;
	*(BYTE*)(0x00515A57+1)    = 0xB7;
	*(BYTE*)(0x004E4F9C+1)    = 0xB7;
	*(BYTE*)(0x00516DDF+1)    = 0xB7;
	*(BYTE*)(0x005527F1+1)    = 0xB7;
	*(BYTE*)(0x005529EA+1)    = 0xB7;
	*(BYTE*)(0x00552C33+1)    = 0xB7;
	*(BYTE*)(0x005B54D8+1)    = 0xB7;
	*(BYTE*)(0x004C3450+1)    = 0xB7;
	*(BYTE*)(0x004C3833+1)    = 0xB7;
	*(BYTE*)(0x004C389B+1)    = 0xB7;
	*(BYTE*)(0x004C3904+1)    = 0xB7;
	*(BYTE*)(0x004C3959+1)    = 0xB7;
	*(BYTE*)(0x004CB3BB+1)    = 0xB7;
	*(BYTE*)(0x004D488B+1)    = 0xB7;
	*(BYTE*)(0x004D8F14+1)    = 0xB7;
	*(BYTE*)(0x004D9921+1)    = 0xB7;
	*(BYTE*)(0x004D9A31+1)    = 0xB7;
	*(BYTE*)(0x004DB297+1)    = 0xB7;
	*(BYTE*)(0x004E613F+1)    = 0xB7;
	*(BYTE*)(0x004E7C9B+1)    = 0xB7;
	*(BYTE*)(0x004FA3DD+1)    = 0xB7;
	*(BYTE*)(0x005155F9+1)    = 0xB7;
	*(BYTE*)(0x00515873+1)    = 0xB7;
	*(BYTE*)(0x00515A63+1)    = 0xB7;
	*(BYTE*)(0x005176EA+1)    = 0xB7;
	*(BYTE*)(0x0051770D+1)    = 0xB7;
	*(BYTE*)(0x00517730+1)    = 0xB7;
	*(BYTE*)(0x00517753+1)    = 0xB7;
	*(BYTE*)(0x004E4FC1+1)    = 0xB7;
	*(BYTE*)(0x00516D9D+1)    = 0xB7;
	*(BYTE*)(0x005527DD+1)    = 0xB7;
	*(BYTE*)(0x005529D6+1)    = 0xB7;
	*(BYTE*)(0x00552C1F+1)    = 0xB7;
	*(BYTE*)(0x005B54C7+1)    = 0xB7;
	*(BYTE*)(0x004C3469+1)    = 0xB7;
	*(BYTE*)(0x004C3847+1)    = 0xB7;
	*(BYTE*)(0x004C38AF+1)    = 0xB7;
	*(BYTE*)(0x004C3918+1)    = 0xB7;
	*(BYTE*)(0x004C396D+1)    = 0xB7;
	*(BYTE*)(0x004C4244+1)    = 0xB7;
	*(BYTE*)(0x004C6347+1)    = 0xB7;
	*(BYTE*)(0x004CB3DB+1)    = 0xB7;
	*(BYTE*)(0x004CB405+1)    = 0xB7;
	*(BYTE*)(0x004CB7E7+1)    = 0xB7;
	*(BYTE*)(0x004CB81C+1)    = 0xB7;
	*(BYTE*)(0x004CB995+1)    = 0xB7;
	*(BYTE*)(0x004CBC26+1)    = 0xB7;
	*(BYTE*)(0x004CC400+1)    = 0xB7;
	*(BYTE*)(0x004CC542+1)    = 0xB7;
	*(BYTE*)(0x004CF949+1)    = 0xB7;
	*(BYTE*)(0x004CF96C+1)    = 0xB7;
	*(BYTE*)(0x004D48A4+1)    = 0xB7;
	*(BYTE*)(0x004D8EA8+1)    = 0xB7;
	*(BYTE*)(0x004D98A6+1)    = 0xB7;
	*(BYTE*)(0x004D9A49+1)    = 0xB7;
	*(BYTE*)(0x004DB2B0+1)    = 0xB7;
	*(BYTE*)(0x004E61DE+1)    = 0xB7;
	*(BYTE*)(0x004E7C90+1)    = 0xB7;
	*(BYTE*)(0x004FA407+1)    = 0xB7;
	*(BYTE*)(0x005109C5+1)    = 0xB7;
	*(BYTE*)(0x00510E71+1)    = 0xB7;
	*(BYTE*)(0x005113FC+1)    = 0xB7;
	*(BYTE*)(0x00515605+1)    = 0xB7;
	*(BYTE*)(0x0051587F+1)    = 0xB7;
	*(BYTE*)(0x00515A6F+1)    = 0xB7;
    #endif
}