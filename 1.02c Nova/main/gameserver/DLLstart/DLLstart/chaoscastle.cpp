#include "stdafx.h"

chaosCastle ccastle;
chaosCastle ccastlearray[255];

void chaosCastle::load()
{
    this->count = 0;
    memset(ccastlearray, 0, sizeof(ccastlearray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\eventitembags\\chaoscastle.season"), group);

	if(group.GetSection(0, section))
	{
		this->active  = section.Rows[0].GetInt(0);
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			ccastlearray[this->count].index         = section.Rows[i].GetInt(0);
			ccastlearray[this->count].id            = section.Rows[i].GetInt(1);
			ccastlearray[this->count].level         = section.Rows[i].GetInt(2);
			ccastlearray[this->count].skill         = section.Rows[i].GetInt(3);
			ccastlearray[this->count].luck          = section.Rows[i].GetInt(4);
			ccastlearray[this->count].addopt        = section.Rows[i].GetInt(5);
			ccastlearray[this->count].addoptex      = section.Rows[i].GetInt(6);
			ccastlearray[this->count].addoptanc     = section.Rows[i].GetInt(7);
			this->count++;
		}
	}
}

void ChaosCastleDROP(int cc, int index)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	int  luck      = Rand(0,ccastle.count);
	int  item      = ::ItemGetNumberMake(ccastlearray[luck].index,ccastlearray[luck].id);
	char level     = ccastlearray[luck].level;
	char skill     = ccastlearray[luck].skill;
	char opluck    = ccastlearray[luck].luck;
	char addopt    = ccastlearray[luck].addopt;
	char addoptex  = ccastlearray[luck].addoptex;
	char addoptanc = ccastlearray[luck].addoptanc;

	if(addoptanc == 1)
	{
		for(int i = 1; i < 6; i++)
		{
			addoptanc = i;
		}
	}

	ItemSerialCreateSend(index,lpObj->MapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,item,level,0,skill,luck,addopt,lpObj->m_Index,addoptex,addoptanc);
}