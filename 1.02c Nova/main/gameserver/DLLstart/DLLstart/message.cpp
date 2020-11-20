#include "stdafx.h"

Message ms[255];

void Message::load()
{
    memset(ms, 0, sizeof(ms));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\mensagem.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(ms[i].mensagem, sizeof(ms[i].mensagem), (section.Rows[i].GetStringPtr(0)));
		    ms[i].tipo    = section.Rows[i].GetInt(1);
		}
	}
}

void message(int index, int numero, int x)
{
	char message[255];
	wsprintf(message,ms[numero].mensagem,x);
	GCServerMsgStringSend(message,index,(BYTE)ms[numero].tipo);
}