#include "stdafx.h"

itemexdropselect itemarray[255];
itemexdropselect item;

dropadd droparray[255];
dropadd dropd;

configs          cfg;

void itemexdropselect::load()
{
    this->count = 0;
    memset(itemarray, 0, sizeof(itemarray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\blockitem.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			itemarray[this->count].index       = section.Rows[i].GetInt(0);
			itemarray[this->count].id          = section.Rows[i].GetInt(1);
			this->count++;
		}
	}
}

void dropadd::load()
{
    this->count = 0;
    memset(droparray, 0, sizeof(droparray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\customizações\\dropitem.season"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			droparray[this->count].index          = section.Rows[i].GetInt(0);
			droparray[this->count].id             = section.Rows[i].GetInt(1);
			droparray[this->count].level          = section.Rows[i].GetInt(2);
			droparray[this->count].luck           = section.Rows[i].GetInt(3);
			droparray[this->count].skill          = section.Rows[i].GetInt(4);
			droparray[this->count].addopt         = section.Rows[i].GetInt(5);
			droparray[this->count].addoptex       = section.Rows[i].GetInt(6);
			droparray[this->count].mapa           = section.Rows[i].GetInt(7);
			droparray[this->count].monstro        = section.Rows[i].GetInt(8);
			droparray[this->count].minlevel       = section.Rows[i].GetInt(9);
			droparray[this->count].maxlevel       = section.Rows[i].GetInt(10);
			droparray[this->count].porcentagem    = section.Rows[i].GetInt(11);
			this->count++;
		}
	}
}

void configs::hashload()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\hash.season"), group);

	if(group.GetSection(0, section))
	{
		this->hashratejewel         = section.Rows[0].GetInt(0,0,1);
		this->hashlevelsoldier      = section.Rows[1].GetInt(0,0,1);
		this->hashitemlevelmix      = section.Rows[2].GetInt(0,0,1);
		this->hashmovesystem        = section.Rows[3].GetInt(0,0,1);
		this->hashseal              = section.Rows[4].GetInt(0,0,1);
	}
}

void configs::load()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\servidor.season"), group);

	this->hashload();

	if(group.GetSection(0, section))
	{
		this->gameserver         = section.Rows[0].GetInt(0);
		this->joinserver         = section.Rows[0].GetInt(1);
		this->dataserver         = section.Rows[0].GetInt(2);
		this->exdbserver         = section.Rows[0].GetInt(3);
		this->portserver         = section.Rows[0].GetInt(4);
		//
		this->checksum           = section.Rows[1].GetInt(0);
		this->charid             = section.Rows[1].GetInt(1);
		this->guildid            = section.Rows[1].GetInt(2);
		this->tempitems          = section.Rows[1].GetInt(3);
		this->ccplayer           = section.Rows[1].GetInt(4);
		this->allplayer          = section.Rows[1].GetInt(5);
		//
		this->manaagi            = section.Rows[2].GetInt(0);
		this->manaene            = section.Rows[2].GetInt(1);
		this->manadiv            = section.Rows[2].GetInt(2);
		//
		this->greatvit           = section.Rows[3].GetInt(0);
		this->greatene           = section.Rows[3].GetInt(1);
		//
		this->party2             = section.Rows[4].GetInt(0);
		this->party3             = section.Rows[4].GetInt(1);
		this->party4             = section.Rows[4].GetInt(2);
		this->party5             = section.Rows[4].GetInt(3);
		this->setparty3          = section.Rows[4].GetInt(4);
		this->setparty4          = section.Rows[4].GetInt(5);
		this->setparty5          = section.Rows[4].GetInt(6);
		//
		this->twistslash         = section.Rows[5].GetInt(0);
		this->ragefulblow        = section.Rows[5].GetInt(1);
		this->deathstab          = section.Rows[5].GetInt(2);
		this->greatfort          = section.Rows[5].GetInt(3);
		this->penetration        = section.Rows[5].GetInt(4);
		//
		this->dropex             = section.Rows[6].GetInt(0);
		this->dropexskill        = section.Rows[6].GetInt(1);
		this->dropexluck         = section.Rows[6].GetInt(2);
		this->dropskill          = section.Rows[6].GetInt(3);
		this->dropluck           = section.Rows[6].GetInt(4);
		//
	}

	if(group.GetSection(1, section))
	{
		this->pointsdl           = section.Rows[0].GetInt(0);
		this->pointsmg           = section.Rows[0].GetInt(1);
		this->pointsothers       = section.Rows[0].GetInt(2);
		//
		this->healing[0]         = section.Rows[1].GetInt(0);
		this->healing[1]         = section.Rows[1].GetInt(1);
		this->healing[2]         = section.Rows[1].GetInt(2);
		this->healing[3]         = section.Rows[1].GetInt(3);
		this->healing[4]         = section.Rows[1].GetInt(4);
		//
		this->mana[0]            = section.Rows[2].GetInt(0);
		this->mana[1]            = section.Rows[2].GetInt(1);
		this->mana[2]            = section.Rows[2].GetInt(2);
		this->mana[3]            = section.Rows[2].GetInt(3);
		this->mana[4]            = section.Rows[2].GetInt(4);
		this->mana[5]            = section.Rows[2].GetInt(5);
		//
		this->AG[0]              = section.Rows[3].GetInt(0);
		this->AG[1]              = section.Rows[3].GetInt(1);
		this->AG[2]              = section.Rows[3].GetInt(2);
		this->AG[3]              = section.Rows[3].GetInt(3);
		this->AG[4]              = section.Rows[3].GetInt(4);
		this->AG[5]              = section.Rows[3].GetInt(5);
		//
		this->SD[0]              = section.Rows[4].GetInt(0);
		this->SD[1]              = section.Rows[4].GetInt(1);
		this->SD[2]              = section.Rows[4].GetInt(2);
		this->SD[3]              = section.Rows[4].GetInt(3);
		this->SD[4]              = section.Rows[4].GetInt(4);
		this->SD[5]              = section.Rows[4].GetInt(5);
		//
		strcpy_s(this->message[0],   sizeof(this->message[0]),     (section.Rows[5].GetStringPtr(0)));
		this->color[0]              = section.Rows[5].GetInt(1);
		strcpy_s(this->message[1],   sizeof(this->message[1]),     (section.Rows[6].GetStringPtr(0)));
		this->color[1]              = section.Rows[6].GetInt(1);
		strcpy_s(this->message[2],   sizeof(this->message[2]),     (section.Rows[7].GetStringPtr(0)));
		this->color[2]              = section.Rows[7].GetInt(1);
		strcpy_s(this->message[3],   sizeof(this->message[3]),     (section.Rows[8].GetStringPtr(0)));
		this->color[3]              = section.Rows[8].GetInt(1);
		//
		this->experience[0]      = section.Rows[9].GetInt(0);
		this->experience[1]      = section.Rows[9].GetInt(1);
		this->experience[2]      = section.Rows[9].GetInt(2);
		this->experience[3]      = section.Rows[9].GetInt(3);
		//
		this->drops[0]           = section.Rows[10].GetInt(0);
		this->drops[1]           = section.Rows[10].GetInt(1);
		this->drops[2]           = section.Rows[10].GetInt(2);
		this->drops[3]           = section.Rows[10].GetInt(3);
		//
		if(this->hashratejewel == 0x8AF13C)
		{
		    this->soulluck[0]           = section.Rows[11].GetInt(0);
		    this->soulluck[1]           = section.Rows[11].GetInt(1);
		    this->soulluck[2]           = section.Rows[11].GetInt(2);
		    this->soulluck[3]           = section.Rows[11].GetInt(3);

		    this->soulnoluck[0]         = section.Rows[12].GetInt(0);
		    this->soulnoluck[1]         = section.Rows[12].GetInt(1);
		    this->soulnoluck[2]         = section.Rows[12].GetInt(2);
		    this->soulnoluck[3]         = section.Rows[12].GetInt(3);

		    this->life[0]               = section.Rows[13].GetInt(0);
		    this->life[1]               = section.Rows[13].GetInt(1);
		    this->life[2]               = section.Rows[13].GetInt(2);
		    this->life[3]               = section.Rows[13].GetInt(3);
		}
		else
		{
		    this->soulluck[0]           = section.Rows[11].GetInt(0);
		    this->soulluck[1]           = this->soulluck[0];
		    this->soulluck[2]           = this->soulluck[0];
		    this->soulluck[3]           = this->soulluck[0];

		    this->soulnoluck[0]         = section.Rows[12].GetInt(0);
		    this->soulnoluck[1]         = this->soulnoluck[0];
		    this->soulnoluck[2]         = this->soulnoluck[0];
		    this->soulnoluck[3]         = this->soulnoluck[0];

		    this->life[0]               = section.Rows[13].GetInt(0);
		    this->life[1]               = this->life[0];
		    this->life[2]               = this->life[0];
		    this->life[3]               = this->life[0];
		}

		if(this->hashlevelsoldier == 0x1AFC03)
		{
			this->levelsoldier[0]      = section.Rows[14].GetInt(0);
			this->levelsoldier[1]      = section.Rows[14].GetInt(1);
			this->levelsoldier[2]      = section.Rows[14].GetInt(2);
			this->levelsoldier[3]      = section.Rows[14].GetInt(3);
		}
		else
		{
			this->levelsoldier[0]      = section.Rows[14].GetInt(0);
			this->levelsoldier[1]      = this->levelsoldier[0];
			this->levelsoldier[2]      = this->levelsoldier[0];
			this->levelsoldier[3]      = this->levelsoldier[0];
		}

		if(this->hashitemlevelmix == 0x6BC074)
		{
			this->mix10[0]             =  section.Rows[15].GetInt(0);
			this->mix10[1]             =  section.Rows[15].GetInt(1);
			this->mix10[2]             =  section.Rows[15].GetInt(2);
			this->mix10[3]             =  section.Rows[15].GetInt(3);

			this->mix10luck[0]         =  section.Rows[16].GetInt(0);
			this->mix10luck[1]         =  section.Rows[16].GetInt(1);
			this->mix10luck[2]         =  section.Rows[16].GetInt(2);
			this->mix10luck[3]         =  section.Rows[16].GetInt(3);

			this->mix11[0]             =  section.Rows[17].GetInt(0);
			this->mix11[1]             =  section.Rows[17].GetInt(1);
			this->mix11[2]             =  section.Rows[17].GetInt(2);
			this->mix11[3]             =  section.Rows[17].GetInt(3);

			this->mix11luck[0]         =  section.Rows[18].GetInt(0);
			this->mix11luck[1]         =  section.Rows[18].GetInt(1);
			this->mix11luck[2]         =  section.Rows[18].GetInt(2);
			this->mix11luck[3]         =  section.Rows[18].GetInt(3);

			this->mix12[0]             =  section.Rows[19].GetInt(0);
			this->mix12[1]             =  section.Rows[19].GetInt(1);
			this->mix12[2]             =  section.Rows[19].GetInt(2);
			this->mix12[3]             =  section.Rows[19].GetInt(3);

			this->mix12luck[0]         =  section.Rows[20].GetInt(0);
			this->mix12luck[1]         =  section.Rows[20].GetInt(1);
			this->mix12luck[2]         =  section.Rows[20].GetInt(2);
			this->mix12luck[3]         =  section.Rows[20].GetInt(3);

			this->mix13[0]             =  section.Rows[21].GetInt(0);
			this->mix13[1]             =  section.Rows[21].GetInt(1);
			this->mix13[2]             =  section.Rows[21].GetInt(2);
			this->mix13[3]             =  section.Rows[21].GetInt(3);

			this->mix13luck[0]         =  section.Rows[22].GetInt(0);
			this->mix13luck[1]         =  section.Rows[22].GetInt(1);
			this->mix13luck[2]         =  section.Rows[22].GetInt(2);
			this->mix13luck[3]         =  section.Rows[22].GetInt(3);
		}
		else
		{
			this->mix10[0]             =  section.Rows[15].GetInt(0);
			this->mix10[1]             =  this->mix10[0];
			this->mix10[2]             =  this->mix10[0];
			this->mix10[3]             =  this->mix10[0];

			this->mix10luck[0]         =  section.Rows[16].GetInt(0);
			this->mix10luck[1]         =  this->mix10luck[0];
			this->mix10luck[2]         =  this->mix10luck[0];
			this->mix10luck[3]         =  this->mix10luck[0];

			this->mix11[0]             =  section.Rows[17].GetInt(0);
			this->mix11[1]             =  this->mix11[0];
			this->mix11[2]             =  this->mix11[0];
			this->mix11[3]             =  this->mix11[0];

			this->mix11luck[0]         =  section.Rows[18].GetInt(0);
			this->mix11luck[1]         =  this->mix11luck[0];
			this->mix11luck[2]         =  this->mix11luck[0];
			this->mix11luck[3]         =  this->mix11luck[0];

			this->mix12[0]             =  section.Rows[19].GetInt(0);
			this->mix12[1]             =  this->mix12[0];
			this->mix12[2]             =  this->mix12[0];
			this->mix12[3]             =  this->mix12[0];

			this->mix12luck[0]         =  section.Rows[20].GetInt(0);
			this->mix12luck[1]         =  this->mix12luck[0];
			this->mix12luck[2]         =  this->mix12luck[0];
			this->mix12luck[3]         =  this->mix12luck[0];

			this->mix13[0]             =  section.Rows[21].GetInt(0);
			this->mix13[1]             =  this->mix13[0];
			this->mix13[2]             =  this->mix13[0];
			this->mix13[3]             =  this->mix13[0];

			this->mix13luck[0]         =  section.Rows[22].GetInt(0);
			this->mix13luck[1]         =  this->mix13luck[0];
			this->mix13luck[2]         =  this->mix13luck[0];
			this->mix13luck[3]         =  this->mix13luck[0];
		}

		this->potionactive             =  section.Rows[23].GetInt(0);
		this->potiontime               =  section.Rows[23].GetInt(1);

		this->zentype                  =  section.Rows[24].GetInt(0);
		this->zenmix                   =  section.Rows[24].GetInt(1);

		this->skillsiege               =  section.Rows[25].GetInt(0);
		this->reflete                  =  section.Rows[25].GetInt(1);

		this->skillsiege               =  section.Rows[25].GetInt(0);
		this->reflete                  =  section.Rows[25].GetInt(1);

		this->kundumitem               =  section.Rows[26].GetInt(0);
		this->kundumrate               =  section.Rows[26].GetInt(1);

		this->DarkHorseMix             =  section.Rows[27].GetInt(0);
		this->DarkHorsePrice           =  section.Rows[27].GetInt(1);

		this->DarkRavenMix             =  section.Rows[28].GetInt(0);
		this->DarkRavenPrice           =  section.Rows[28].GetInt(1);
		this->DarkRavenDurability	   =  section.Rows[28].GetInt(2);
	}

	addPoints::load();
	Message::load();
	cmds.load();
	item.load();
	rStarted.load();
	bcastle.load();
	ccastle.load();
	dsquare.load();
	gSystem.load();
	dropd.load();
	Calcharacter();
}