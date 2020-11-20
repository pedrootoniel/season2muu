#include "stdafx.h"

bloodCastle bcastle;
bloodCastle bcastlearray[255];

void bloodCastle::load()
{
    this->count = 0;
    memset(bcastlearray, 0, sizeof(bcastlearray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\eventitembags\\bloodcastle.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			bcastlearray[this->count].index         = section.Rows[i].GetInt(0);
			bcastlearray[this->count].id            = section.Rows[i].GetInt(1);
			bcastlearray[this->count].level         = section.Rows[i].GetInt(2);
			bcastlearray[this->count].skill         = section.Rows[i].GetInt(3);
			bcastlearray[this->count].luck          = section.Rows[i].GetInt(4);
			bcastlearray[this->count].addopt        = section.Rows[i].GetInt(5);
			bcastlearray[this->count].addoptex      = section.Rows[i].GetInt(6);
			this->count++;
		}
	}
}

void BloodCastleDROP(int index)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	int  luck      = Rand(0,bcastle.count);
	int  item      = ::ItemGetNumberMake(bcastlearray[luck].index,bcastlearray[luck].id);
	char level     = bcastlearray[luck].level;
	char skill     = bcastlearray[luck].skill;
	char opluck    = bcastlearray[luck].luck;
	char addopt    = bcastlearray[luck].addopt;
	char addoptex  = bcastlearray[luck].addoptex;
	ItemSerialCreateSend(index,lpObj->MapNumber + 227,(BYTE)lpObj->X,(BYTE)lpObj->Y,item,level,0,skill,luck,addopt,lpObj->m_Index,addoptex,0);
}