#include "stdafx.h"

GMsystem gSystem;
GMsystem gSystemarray[255];

void GMsystem::load()
{
    this->count = 0;
    memset(gSystemarray, 0, sizeof(gSystemarray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\administrador.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(gSystemarray[this->count].name, sizeof(gSystemarray[this->count].name), (section.Rows[i].GetStringPtr(0)) );
			gSystemarray[this->count].type[0]       = section.Rows[i].GetInt(1);
			gSystemarray[this->count].type[1]       = section.Rows[i].GetInt(2);
			gSystemarray[this->count].type[2]       = section.Rows[i].GetInt(3);
			gSystemarray[this->count].type[3]       = section.Rows[i].GetInt(4);
			this->count++;
		}
	}
}

bool GMsystem::CheckGM(LPOBJ lpObj, unsigned com)
{
	if(lpObj->AuthorityCode > 0)
	{
	    for(int i = 0; i <  this->count; i++)
	    {
		    if(strcmp(lpObj->Name,gSystemarray[i].name) == 0)
		    {
			    if(gSystemarray[i].type[com] == 0)
			    {
				    return false;
			    }

			    return true;
		    }
	     }
	}

	return false;
}