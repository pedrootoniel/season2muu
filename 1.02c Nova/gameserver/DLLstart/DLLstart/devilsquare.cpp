#include "stdafx.h"

devilSquare dsquare;
devilSquare dsquarearray[255];

void devilSquare::load()
{
    this->count = 0;
    memset(dsquarearray, 0, sizeof(dsquarearray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\eventitembags\\devilsquare.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			dsquarearray[this->count].index         = section.Rows[i].GetInt(0);
			dsquarearray[this->count].id            = section.Rows[i].GetInt(1);
			dsquarearray[this->count].level         = section.Rows[i].GetInt(2);
			dsquarearray[this->count].skill         = section.Rows[i].GetInt(3);
			dsquarearray[this->count].luck          = section.Rows[i].GetInt(4);
			dsquarearray[this->count].addopt        = section.Rows[i].GetInt(5);
			dsquarearray[this->count].addoptex      = section.Rows[i].GetInt(6);
			this->count++;
		}
	}
}

void DevilSquare(LPOBJ lpObj)
{
	int  luck      = Rand(0,bcastle.count);
	int  item      = ::ItemGetNumberMake(dsquarearray[luck].index,dsquarearray[luck].id);
	char level     = dsquarearray[luck].level;
	char skill     = dsquarearray[luck].skill;
	char opluck    = dsquarearray[luck].luck;
	char addopt    = dsquarearray[luck].addopt;
	char addoptex  = dsquarearray[luck].addoptex;
	ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,(BYTE)lpObj->X,(BYTE)lpObj->Y,item,level,0,skill,luck,addopt,lpObj->m_Index,addoptex,0);
}

__declspec(naked) void DevilSquareDROP()
{
	_asm
	{
		mov eax,dword ptr ss:[ebp+8]
		push eax
		call DevilSquare
		mov byte ptr ss:[ebp-0x2C],0x0C1
        mov byte ptr ss:[ebp-0x2A],1
		mov edi, 0x00467E62
		jmp edi
	}
}