#include "stdafx.h"

configs cfg;

configs::configs()
{
}

configs::~configs()
{
}

void configs::load()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\database.season"), group);

	if(group.GetSection(0, section))
	{
		strcpy_s(this->vip[0],   sizeof(this->vip[0]),     (section.Rows[0].GetStringPtr(0)));
		strcpy_s(this->vip[1],   sizeof(this->vip[1]),     (section.Rows[1].GetStringPtr(0)));

		strcpy_s(this->resets[0], sizeof(this->resets[0]), (section.Rows[2].GetStringPtr(0)));
		strcpy_s(this->resets[1], sizeof(this->resets[1]), (section.Rows[3].GetStringPtr(0)));
		strcpy_s(this->resets[2], sizeof(this->resets[2]), (section.Rows[4].GetStringPtr(0)));
	}
}