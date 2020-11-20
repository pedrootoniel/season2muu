#include "stdafx.h"

notice noticearray[255];
notice noticestart;

void notice::load()
{
    this->count = 0;
    memset(noticearray, 0, sizeof(noticearray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\structnoticia.season"), group);

	if(group.GetSection(0, section))
	{
		this->active       = section.Rows[0].GetInt(0);
		this->time         = section.Rows[0].GetInt(1);

		if(this->active == 1)
		{
			CreateThread(0,0,(LPTHREAD_START_ROUTINE)StartNotice,0,0,0);
		}
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(noticearray[this->count].message, sizeof(noticearray[this->count].message), (section.Rows[i].GetStringPtr(0)));
			noticearray[this->count].type       = section.Rows[i].GetInt(1);
			this->count++;
		}
	}
}

void __stdcall StartNotice()
{
    SYSTEMTIME Time;
    GetLocalTime(&Time);

	while(true)
	{
		for(int i = 0; i < noticestart.count; i++)
		{
			Sleep(noticestart.time*1000);

            for(int a = MIN_PLAYERID; a < MAX_PLAYERID; a++)
	        {
	            OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(a);

				if(lpObj->Connected > 2 &&	lpObj->Type == 1)
				{
				    GCServerMsgStringSend(noticearray[i].message,a,noticearray[i].type);
				}
		    }
		}
	}
}