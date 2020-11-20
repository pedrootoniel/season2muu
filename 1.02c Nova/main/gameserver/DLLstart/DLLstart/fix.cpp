#include "stdafx.h"

unsigned char ProtocolServer(BYTE Type)
{
   switch(Type)
   {
   case 0x1D: return 0xD4;
   case 0xDC: return 0x11;
   case 0xD6: return 0x15;	
   }
   return Type;
}

unsigned char ProtocolClient(BYTE Type)
{
  switch(Type)
  {
  case 0xD4: return 0x1D;
  case 0x11: return 0xDC;
  case 0x15: return 0xD6;
  }
  return Type;
}

__declspec(naked) void ItemDurability()
{
	_asm
	{
		cmp dword ptr ss:[ebp+0xC],0x0E
		jnz item_15
		mov ecx,dword ptr ss:[ebp+8]
		imul ecx,ecx,0x6C
		xor edx, edx
        #if DLLtype == 0
		mov dl,byte ptr ds:[ecx+0x9DD3228]
        #else
		mov dl,byte ptr ds:[ecx+0x5C20308]
        #endif
		mov eax,dword ptr ss:[ebp+0xC]
		lea ecx,dword ptr ds:[edx+eax*2+7]
		mov dword ptr ss:[ebp-4],ecx
		jmp local
item_15:
		cmp dword ptr ss:[ebp+0xC],0x0F
		jnz return_
		mov ecx,dword ptr ss:[ebp+8]
		imul ecx,ecx,0x6C
		xor edx, edx
		#if DLLtype == 0
		mov dl,byte ptr ds:[ecx+0x9DD3228]
        #else
		mov dl,byte ptr ds:[ecx+0x5C20308]
        #endif
		mov eax,dword ptr ss:[ebp+0xC]
		lea ecx,dword ptr ds:[edx+eax*2+8]
		mov dword ptr ss:[ebp-4],ecx
		jmp local
local:
		#if DLLtype == 0
		mov edi, 0x0051636A
        #else
		mov edi, 0x0052978A
        #endif
		jmp edi
return_:
		mov eax,dword ptr ss:[ebp+8]
		imul eax,eax,0x6C
		xor ecx, ecx
		#if DLLtype == 0
		mov cl,byte ptr ds:[eax+0x9DD3228]
        #else
		mov cl,byte ptr ds:[eax+0x5C20308]
        #endif
		mov edx,dword ptr ss:[ebp+0xC]
		lea eax,dword ptr ds:[ecx+edx*2-4]
		mov dword ptr ss:[ebp-4],eax
		#if DLLtype == 0
		mov edi, 0x0051636A
        #else
		mov edi, 0x0052978A
        #endif
		jmp edi
	}
}

void __declspec(naked) QueueCompletionFix()
{
	_asm
	{
		cmp dword ptr ss:[ebp-0x30],0x3E3
		je retornar
		cmp dword ptr ss:[ebp-0x30],0x79
		je retornar
		#if DLLtype == 0
		mov edi, 0x0048AAC7
        #else
		mov edi, 0x0049B897
        #endif
		jmp edi;
retornar:
		#if DLLtype == 0
		mov edi, 0x0048AAF9
        #else
		mov edi, 0x0049B8C9
        #endif
		jmp edi;
	}
}

void __declspec(naked) GSPort()
{
	_asm
	{
	mov eax, cfg.gameserver
    mov dword ptr ss:[ebp-0x164],eax
	mov ecx, cfg.joinserver
	#if DLLtype == 0
    mov dword ptr ds:[0xB46DF24],ecx
    #else
	mov dword ptr ds:[0x727FE94],ecx
    #endif
	mov edx, cfg.dataserver
	#if DLLtype == 0
    mov dword ptr ds:[0xB46DF20],edx
    #else
	mov dword ptr ds:[0x727FE90],edx
    #endif
	mov ebx, cfg.exdbserver
	#if DLLtype == 0
    mov dword ptr ds:[0xB46DF18],ebx
    #else
	mov dword ptr ds:[0x727FE88],ebx
    #endif
	#if DLLtype == 0
	mov eax, 0x0052D83B
    #else
	mov eax, 0x00540C4B
    #endif
	jmp eax
	}
}

int itemexdrop(short id)
{
	for(int i = 0; i < item.count; i++)
	{
		if(id == ITEMGET(itemarray[i].index,itemarray[i].id))
		{
			return 1;
		}
	}

	return 0;
}

void __declspec(naked) GSExDropFix()
{
	if(rand()%10000 < cfg.dropex)
	{
	    _asm
	    {
            mov edx, dword ptr ss:[ebp-0x3C]
            movsx ecx, word ptr ds:[edx+6]
            push ecx
            mov eax, itemexdrop
			call eax
			cmp eax, 1
			je noexe
	        #if DLLtype == 0
			mov eax, 0x0041B44C
            #else
			mov eax, 0x0041CEBC
            #endif
			jmp eax
            noexe:
			#if DLLtype == 0
			mov eax, 0x0041B4A5
		    #else
			mov eax, 0x0041CF15
            #endif
			jmp eax

	    }
	}
	else
	{
	    _asm
	    {
			#if DLLtype == 0
			mov eax, 0x0041B4A5
		    #else
			mov eax, 0x0041CF15
            #endif
			jmp eax
	    }
	}
}

void GSLoadFix()
{
    #if DLLtype == 0
	//alteração do protocolo
    BYTE protocolo_00[] = {0x33,0xC9,0x8A,0x4D,0x0C,0x51,0xFF,0x15,0x60,0x00,0x61,0x00,0x8B,0x75,0x08,0x88,0x46,0x02,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3};
	memcpy((int*)(0x004A542B),protocolo_00,sizeof(protocolo_00));
    BYTE protocolo_01[] = {0x8A,0x51,0x02,0x52,0xFF,0x15,0x64,0x00,0x61,0x00,0x88,0x45,0xE4,0x8B,0x45,0xF0,0xE9,0x5B,0xF7,0xFF,0xFF};
	memcpy((int*)(0x0048B76F),protocolo_01,sizeof(protocolo_01));
    BYTE protocolo_02[] = {0x33,0xD2,0xE9,0x92,0x08,0x00,0x00,0x90,0x90,0x03,0x45,0xEC,0x8A,0x08,0x88,0x4D,0xE0,0xE9,0xAC,0x00,0x00,0x00,0x8B,0x55,0xF0,0x03,0x55,0xEC};
	memcpy((int*)(0x0048AED6),protocolo_02,sizeof(protocolo_02));

	_asm
	{
		mov dword ptr ds:[00610060H],Offset ProtocolServer;
		mov dword ptr ds:[00610064H],Offset ProtocolClient;
	}


	// Rate Kundum Drop	
	*(unsigned char*) (0x0041A4F8)		= cfg.kundumitem;
	*(unsigned int*)  (0x0041A692+1)	= cfg.kundumrate;

	//DarkHorse Mix
	*(unsigned int *) (0x00499D69+6) = cfg.DarkHorseMix;
	*(unsigned int *) (0x00499D88+3) = cfg.DarkHorsePrice;

	//Darj Spirit
	*(unsigned int *) (0x0049A46A+6) = cfg.DarkRavenMix;
	*(unsigned int *) (0x0049A489+3) = cfg.DarkRavenPrice;
	*(unsigned int*)  (0x004C9694+2) = cfg.DarkRavenDurability;

	//dragon invasion
    BYTE invasion01[] = {0xEB, 0x47, 0x90};
	memcpy((int*)(0x0046C214),invasion01,sizeof(invasion01));
    BYTE invasion02[] = {0x83, 0xC4, 0x08, 0x50, 0xE8, 0x2C, 0x7F, 0xF9, 0xFF, 0xEB, 0xAF};
	memcpy((int*)(0x0046C25D),invasion02,sizeof(invasion02));

	//service pack 2 disconnect
	HookFunc(0x0048AABE, (DWORD)(&QueueCompletionFix));
	HookNop(0x0048AABE+5, 4);

	//item + 14 & + 15
	*(BYTE*)(0x00429454+2) = 0x0F;
	*(BYTE*)(0x004D2DDE+2) = 0x0F;
	HookFunc(0x00516352, (DWORD)(&ItemDurability));
	HookNop(0x00516352+5,19);

	//move gate
	*(BYTE*) (0x004FBEF7)    = 0xEB;
	*(BYTE*) (0x004FC458+6)  = 0x01;

	//error l10
	*(BYTE*) (0x0048A0C0)    = 0xC3;

	//webzen sem autoridade
	*(BYTE*) (0x004D537C+6)  = 0x01; 
	*(BYTE*) (0x004D53BD+6)  = 0x01; 
	*(BYTE*) (0x004D5425+6)  = 0x01; 

	//potions 255
	*(BYTE*) (0x0042970F)    = 0xEB; 
	*(BYTE*) (0x004D304C)    = 0xEB; 
	*(BYTE*) (0x004D302F)    = 0xEB; 
	*(BYTE*) (0x004D30D1)    = 0xEB; 
	*(BYTE*) (0x004D3080)    = 0xEB; 
	*(BYTE*) (0x004D309D)    = 0xEB; 
	*(BYTE*) (0x004D30EE)    = 0xEB;

	//serial 0
	*(BYTE*) (0x00508642)    = 0x90;
	*(BYTE*) (0x00508642+1)  = 0x90;
	*(BYTE*) (0x00508776)    = 0x90;
	*(BYTE*) (0x00508776+1)  = 0x90;

	//pk item drop
	*(BYTE*) (0x004B638A)    = 0xEB;
	*(BYTE*) (0x004B665C)    = 0xEB;
	*(BYTE*) (0x004B6687)    = 0xEB;

	//reload connectserver
	*(BYTE*) (0x005920DF)    = 0x60;

	//GM mover pelo M
	*(BYTE*) (0x0051B714+2)  = 0x64;

	//pk count limite retirado
	HookNop(0x004DE272, 15);

	//anciet options + full
	*(BYTE*) (0x0050E556)    = 0xEB;
	*(BYTE*) (0x005735DB)    = 0xEB;

	//gameserver unico dataserver fix
	HookNop(0x0052D77B, 20);
	HookNop(0x0052D7A3, 10);
	HookNop(0x0052D7D2, 10);
	HookNop(0x0052D827, 10);
	HookNop(0x0052D848, 62);
	HookNop(0x004240C6, 230);
    HookNop(0x004242CF, 9);
	HookNop(0x004242EE, 20);
	*(BYTE*)(0x006C5CB9+3) = 0x00;
	*(BYTE*)(0x006C5CB9+4) = 0x00;
	*(BYTE*)(0x006C5CB9+5) = 0x00;
	*(BYTE*)(0x006C5CB9+6) = 0x00;
	*(BYTE*)(0x006C5CB9+7) = 0x00;
	*(BYTE*)(0x006C5CC1)   = 0x00;
	*(BYTE*)(0x0042400A+2) = 0x9C;
	*(BYTE*)(0x0042400A+3) = 0x01;

	//nao salva o personagem na database quando subir o level
    HookNop(0x004DC861, 5);

	//party zen
    BYTE party_zen[] = {
    0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8, 0x02,0x74,0x05,0x83,0xF8,0x03,
    0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55, 0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
    0xC8,0x18,0x6E,0x00,0xE8,0x1C,0x55,0x0B,0x00,0x8B, 0x4D,0x0C,0x89,0x81,0xB4,0x00,
    0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3} ;
	memcpy((int*)(0x004E3437),party_zen,sizeof(party_zen));

	//party zen devilsquare
    BYTE party_zen_square[] = {
    0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8,0x02,0x74,0x05,0x83,0xF8,0x03,
    0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55,0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
    0xC8,0x18,0x6E,0x00,0xE8,0x05,0x29,0x13,0x00,0x8B,0x4D,0x0C,0x89,0x81,0xB4,0x00,
    0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC2,0x10,0x00} ;
	memcpy((int*)(0x0046604E),party_zen_square,sizeof(party_zen_square));

	//POP EDI crash fix party
	*(BYTE*)(0x004E2E0B+1) = 0x59;

	//cliente hack check
	*(BYTE*)(0x00433E50) = 0xC3;

	//cliente speed hack
	*(BYTE*)(0x0043192F) = 0xEB;

	//elf mover em level baixo automatico
	*(BYTE*)(0x004DA4B3) = 0xEB;

	//error l2
	*(BYTE*)(0x0048BF3B)   = 0xEB;
	*(BYTE*)(0x0048BF3B+1) = 0x2A;
	*(BYTE*)(0x0048BF3B+2) = 0x90;

	//error invalid socket
	*(BYTE*)(0x0048CBB8)   = 0xEB;
	*(BYTE*)(0x0048CBB8+1) = 0x10;
	*(BYTE*)(0x0048CBB8+2) = 0x90;

	*(BYTE*)(0x0048CCD1)   = 0xEB;
	*(BYTE*)(0x0048CCD1+1) = 0x1E;
	*(BYTE*)(0x0048CCD1+2) = 0x90;

	//cashshop aceitar item full, original com numero de options
	HookNop(0x0058622B, 8);
	HookNop(0x00586249, 56);
	*(BYTE*)(0x00586246+2) = 0xC0;

	//personal shop reset
	*(BYTE*)(0x004D4F49)   = 0xE9;
	*(BYTE*)(0x004D4F49+1) = 0x9C;
	*(BYTE*)(0x004D4F49+2) = 0x02;
	*(BYTE*)(0x004D4F49+3) = 0x00;
	*(BYTE*)(0x004D4F49+5) = 0x90;

	//drop bag ex luck
	HookNop(0x0047E823, 7); //green ribbon box
	HookNop(0x0047ECB3, 7); //blue ribbon box
	HookNop(0x0047F573, 7); //red chocolate box
	HookNop(0x0047FA03, 7); //blue chocolate box
	HookNop(0x004802C3, 7); //vermilion box
	HookNop(0x00480753, 7); //depp blue box
	HookNop(0x00480C6A, 7); //kundun of kalima
	//crywolf no gs_cs apenas
	HookNop(0x00481BA6, 7); //kanturu maya hand
	HookNop(0x00481F16, 7); //kanturu night mare

	//drop item ex
	HookFunc(0x0041B446, (DWORD)(&GSExDropFix));
	HookNop(0x0041B446+5,1);

	//harmony item + 15
	*(BYTE*)(0x00575230+3) = 0x10; 
	*(BYTE*)(0x005723D4+3) = 0x10; 
	*(BYTE*)(0x00574116+3) = 0x10; 
	*(BYTE*)(0x005741E4+3) = 0x10; 

	//portas
	*(BYTE*) (0x0052D7C6)    = 0xEB;
	HookFunc(0x0052D80A, (DWORD)(&GSPort));
	HookNop(0x0052D80A+5,44);
	memset((char*)0x0B8A9E58,0,50);
	memcpy((char*)0x0B8A9E58,"127.0.0.1",50);
	memset((char*)0x0B8A9F58,0,50);
	memcpy((char*)0x0B8A9F58,"127.0.0.1",50);

	*(BYTE*) (0x0052112F+1)  = cfg.portserver;

	//checksum
	if(cfg.checksum == 1)
	{
	  *(BYTE*) (0x00431BDA)  = 0xEB; 
	  *(BYTE*) (0x00431C38)  = 0xEB;
	}

	//deletar char sem personal ID
	if(cfg.charid == 1)
	{
		*(BYTE*) (0x00434524)    = 0xEB;
	}

	//deletar guild sem personal ID
	if(cfg.guildid == 1)
	{
		HookNop(0x0044521A, 6);
	    HookNop(0x00445370, 2);
	}

	//tempo dos items
	*(unsigned int*) (0x00493A42+1)   = cfg.tempitems * 1000;
	*(unsigned int*) (0x00493BF3+1)   = cfg.tempitems * 1000;

	//chaos castle minimo de players
	*(BYTE*) (0x005442F0+3)  = cfg.ccplayer;

	//guild aliança minimo de membros
	*(BYTE*) (0x00457DEB+2)  = cfg.allplayer;

	//mana shield
	*(unsigned int*) (0x004B9DEB+1)  = cfg.manaagi;
	*(unsigned int*) (0x004B9E0B+1)  = cfg.manaene;
	*(unsigned int*) (0x004B9E36+1)  = cfg.manadiv;

	//great fortitude
	*(unsigned int*) (0x004B99DF+1)  = cfg.greatvit;
	*(unsigned int*) (0x004B99FF+1)  = cfg.greatene;

	//experiencia em party
	*(unsigned int*) (0x004E30B7+3)  = cfg.party2;
	*(unsigned int*) (0x00465CF6+3)  = cfg.party2;
	*(unsigned int*) (0x004E30C6+3)  = cfg.party3;
	*(unsigned int*) (0x00465D05+3)  = cfg.party3;
	*(unsigned int*) (0x004E30D5+3)  = cfg.party4;
	*(unsigned int*) (0x00465D14+3)  = cfg.party4;
	*(unsigned int*) (0x004E30E4+3)  = cfg.party5;
	*(unsigned int*) (0x00465D23+3)  = cfg.party5;
	*(unsigned int*) (0x004E3081+3)  = cfg.setparty3;
	*(unsigned int*) (0x00465CC0+3)  = cfg.setparty3;
	*(unsigned int*) (0x004E3090+3)  = cfg.setparty4;
	*(unsigned int*) (0x00465CCF+3)  = cfg.setparty4;
	*(unsigned int*) (0x004E309F+3)  = cfg.setparty5;
	*(unsigned int*) (0x00465CDE+3)  = cfg.setparty5;

	//skills
	*(unsigned int*) (0x00483640+7)  = cfg.twistslash;
	*(unsigned int*) (0x00483659+7)  = cfg.ragefulblow;
	*(unsigned int*) (0x00483672+7)  = cfg.deathstab;
	*(unsigned int*) (0x004836A4+7)  = cfg.greatfort;
	*(unsigned int*) (0x004836BD+7)  = cfg.penetration;

	//drop de items
	*(unsigned int*) (0x0041B44C+6)  = cfg.dropexskill;
	*(unsigned int*) (0x0041B456+6)  = cfg.dropexluck;
	*(unsigned int*) (0x0041B4A5+6)  = cfg.dropskill;
	*(unsigned int*) (0x0041B4AF+6)  = cfg.dropluck;

	//pontos por level
	*(BYTE*) (0x004DC58C+2)  = cfg.pointsdl;
	*(BYTE*) (0x004DC5B4+2)  = cfg.pointsmg;
	*(BYTE*) (0x004DC5CB+2)  = cfg.pointsothers;

	//potions life
	*(BYTE*) (0x0044D5CF+3)  = cfg.healing[0];
	*(BYTE*) (0x0044D5D8+3)  = cfg.healing[1];
	*(BYTE*) (0x0044D5E1+3)  = cfg.healing[2];
	*(BYTE*) (0x0044D5EA+3)  = cfg.healing[3];
	*(BYTE*) (0x0044D61F+1)  = cfg.healing[4];

	//desabilitar o + 5, level 1
	*(BYTE*) (0x0044D5FB)    = 0xEB;

	//potions mana
	*(BYTE*) (0x0044D90B+2)  = cfg.mana[0];
	*(BYTE*) (0x0044D90F+1)  = cfg.mana[1];
	*(BYTE*) (0x0044D943+2)  = cfg.mana[2];
	*(BYTE*) (0x0044D947+1)  = cfg.mana[3];
	*(BYTE*) (0x0044D97B+2)  = cfg.mana[4];
	*(BYTE*) (0x0044D97F+1)  = cfg.mana[5];

	//potions AG
	*(BYTE*) (0x0044DAEC+2)  = cfg.AG[0];
	*(BYTE*) (0x0044DAF0+1)  = cfg.AG[1];
	*(BYTE*) (0x0044DE32+2)  = cfg.AG[2];
	*(BYTE*) (0x0044DE36+1)  = cfg.AG[3];
	*(BYTE*) (0x0044E178+2)  = cfg.AG[4];
	*(BYTE*) (0x0044E17C+1)  = cfg.AG[5];

	//potions SD
	*(BYTE*) (0x0044E4BE+2)  = cfg.SD[0];
	*(BYTE*) (0x0044E4C2+1)  = cfg.SD[1];
	*(BYTE*) (0x0044E672+2)  = cfg.SD[2];
	*(BYTE*) (0x0044E676+1)  = cfg.SD[3];
	*(BYTE*) (0x0044E826+2)  = cfg.SD[4];
	*(BYTE*) (0x0044E82A+1)  = cfg.SD[5];

	if(cfg.skillsiege == 1)
	{
	    *(BYTE*) (0x004BF154)  = 0xEB;
	    *(BYTE*) (0x004BF164)  = 0xEB;
	    *(BYTE*) (0x004BF247)  = 0xEB;
	    *(BYTE*) (0x004BF257)  = 0xEB;
	    *(BYTE*) (0x004BF364)  = 0xEB;
	    *(BYTE*) (0x004BF374)  = 0xEB;
	    *(BYTE*) (0x004BF447)  = 0xEB;
	    *(BYTE*) (0x004BF457)  = 0xEB;
	    *(BYTE*) (0x004BF564)  = 0xEB;
	    *(BYTE*) (0x004BF574)  = 0xEB;
	    *(BYTE*) (0x004BF654)  = 0xEB;
	    *(BYTE*) (0x004BF664)  = 0xEB;
	    *(BYTE*) (0x004BF737)  = 0xEB;
	    *(BYTE*) (0x004BF747)  = 0xEB;
	}

	//Correções update 1.0.0.4

	//Remove GgSrvDll.dll e GgAuth.dll
	*(BYTE*)(0x00523A54) = 0xEB;

	//elf mover em level baixo automatico
	*(BYTE*)(0x004DA4B3) = 0xEB;

	//gObjGuildWarCheck
	*(DWORD*)(0x500493+1) = 50000;

    #else

	//Correções update 1.0.0.4

	//Remove mensage Box Erro Data Castle Siege
	SetNop(0x004B5D16,6);

	//Fix Summon
	*(BYTE*)(0x004CF3B0)   = 0xEB;
	
	//Remove GgSrvDll.dll e GgAuth.dll
	*(BYTE*)(0x00536FB4) = 0xEB;
	
	//elf mover em level baixo automatico
	*(BYTE*)(0x004EBF63) = 0xEB;

	//alteração do protocolo
    BYTE protocolo_00[] = {0x33,0xC9,0x8A,0x4D,0x0C,0x51,0xFF,0x15,0x60,0x00,0x61,0x00,0x8B,0x75,0x08,0x88,0x46,0x02,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3};
	memcpy((int*)(0x004B6A3B),protocolo_00,sizeof(protocolo_00));
    BYTE protocolo_01[] = {0x8A,0x51,0x02,0x52,0xFF,0x15,0x64,0x00,0x61,0x00,0x88,0x45,0xE4,0x8B,0x45,0xF0,0xE9,0x5B,0xF7,0xFF,0xFF};
	memcpy((int*)(0x0049C53F),protocolo_01,sizeof(protocolo_01));
    BYTE protocolo_02[] = {0x33,0xD2,0xE9,0x92,0x08,0x00,0x00,0x90,0x90,0x03,0x45,0xEC,0x8A,0x08,0x88,0x4D,0xE0,0xE9,0xAC,0x00,0x00,0x00,0x8B,0x55,0xF0,0x03,0x55,0xEC};
	memcpy((int*)(0x0049BCA6),protocolo_02,sizeof(protocolo_02));

	_asm
	{
		mov dword ptr ds:[00610060H],Offset ProtocolServer;
		mov dword ptr ds:[00610064H],Offset ProtocolClient;
	}

	//service pack 2 disconnect
	HookFunc(0x0049B88E, (DWORD)(&QueueCompletionFix));
	HookNop(0x0049B88E+5, 4);

	//item + 14 & + 15
    *(BYTE*)(0x0042ADB4+2) = 0x0F;
	*(BYTE*)(0x004E468E+2) = 0x0F;
	HookFunc(0x00529772, (DWORD)(&ItemDurability));
	HookNop(0x00529772+5,19);

	//move gate
	*(BYTE*) (0x0050F10A)    = 0xEB;
	*(BYTE*) (0x0050F6EC+6)  = 0x01;

	//error l10
	*(BYTE*) (0x0049AE90)    = 0xC3;

	//webzen sem autoridade
	*(BYTE*) (0x004E6D83+6)  = 0x01; 
	*(BYTE*) (0x004E6DC4+6)  = 0x01; 
	*(BYTE*) (0x004E6E2C+6)  = 0x01; 

	//potions 255
	*(BYTE*) (0x0042B06F)    = 0xEB; 
	*(BYTE*) (0x004E48FC)    = 0xEB; 
	*(BYTE*) (0x004E48DF)    = 0xEB; 
	*(BYTE*) (0x004E4981)    = 0xEB; 
	*(BYTE*) (0x004E4930)    = 0xEB; 
	*(BYTE*) (0x004E494D)    = 0xEB; 
	*(BYTE*) (0x004E499E)    = 0xEB;

	//serial 0
	*(BYTE*) (0x0051BA62)    = 0x90;
	*(BYTE*) (0x0051BA62+1)  = 0x90;
	*(BYTE*) (0x0051BB96)    = 0x90;
	*(BYTE*) (0x0051BB96+1)  = 0x90;

	//pk item drop
	*(BYTE*) (0x004C7BDA)    = 0xEB;
	*(BYTE*) (0x004C7EAC)    = 0xEB;
	*(BYTE*) (0x004C7ED7)    = 0xEB;

	//reload connectserver
	*(BYTE*) (0x005C58CE)    = 0x60;

	//GM mover pelo M
	*(BYTE*) (0x0052EA0D+2)  = 0x64;

	//pk count limite retirado
	HookNop(0x004F03C4, 15);

	//anciet options + full
	*(BYTE*) (0x00521976)    = 0xEB;
	*(BYTE*) (0x005A964B)    = 0xEB;

	//gameserver unico dataserver fix
	HookNop(0x00540B8B, 20);
	HookNop(0x00540BB3, 10);
	HookNop(0x00540BE2, 10);
	HookNop(0x00540C37, 10);
	HookNop(0x00540C58, 62);
	HookNop(0x00425A26, 230);
    HookNop(0x00425C2F, 9);
	HookNop(0x00425C4E, 20);
	*(BYTE*)(0x00718571+3) = 0x00;
	*(BYTE*)(0x00718571+4) = 0x00;
	*(BYTE*)(0x00718571+5) = 0x00;
	*(BYTE*)(0x00718571+6) = 0x00;
	*(BYTE*)(0x00718571+7) = 0x00;
	*(BYTE*)(0x0071857A)   = 0x00;
	*(BYTE*)(0x0042596A+2) = 0x9C;
	*(BYTE*)(0x0042596A+3) = 0x01;

	//nao salva o personagem na database quando subir o level
    HookNop(0x004EE881, 5);

	//party zen
    BYTE party_zen[] = {
    0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8, 0x02,0x74,0x05,0x83,0xF8,0x03,
    0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55, 0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
    0xC8,0x18,0x6E,0x00,0xE8,0x1C,0x55,0x0B,0x00,0x8B, 0x4D,0x0C,0x89,0x81,0xB4,0x00,
    0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3} ;
	memcpy((int*)(0x004F5647),party_zen,sizeof(party_zen));

	//cliente hack check
	*(BYTE*)(0x00436E10) = 0xC3;

	//cliente speed hack
	*(BYTE*)(0x004348EF) = 0xEB;

	//elf mover em level baixo automatico
	*(BYTE*)(0x004EBF63) = 0xEB;

	//error l2
	*(BYTE*)(0x0049CD0B)   = 0xEB;
	*(BYTE*)(0x0049CD0B+1) = 0x2A;
	*(BYTE*)(0x0049CD0B+2) = 0x90;

	//error invalid socket
	*(BYTE*)(0x0049D988)   = 0xEB;
	*(BYTE*)(0x0049D988+1) = 0x10;
	*(BYTE*)(0x0049D988+2) = 0x90;

	*(BYTE*)(0x0049DAA1)   = 0xEB;
	*(BYTE*)(0x0049DAA1+1) = 0x1E;
	*(BYTE*)(0x0049DAA1+2) = 0x90;

	//personal shop reset
	*(BYTE*)(0x004E68ED)   = 0xE9;
	*(BYTE*)(0x004E68ED+1) = 0xFF;
	*(BYTE*)(0x004E68ED+2) = 0x02;
	*(BYTE*)(0x004E68ED+3) = 0x00;
	*(BYTE*)(0x004E68ED+5) = 0x90;

	//summon
	*(BYTE*)(0x004CF3B0)   = 0xEB;

	//drop bag ex luck
	HookNop(0x00492462, 7); //hunter zone
	HookNop(0x004928CF, 7); //dark elf
	HookNop(0x00492CCF, 7); //crywolf boss

	//drop item ex
	HookFunc(0x0041CEB6, (DWORD)(&GSExDropFix));
	HookNop(0x0041CEB6+5,1);

	//harmony item + 15
	*(BYTE*)(0x005AB2A0+3) = 0x10; 
	*(BYTE*)(0x005A8444+3) = 0x10; 
	*(BYTE*)(0x005AA186+3) = 0x10; 
	*(BYTE*)(0x005AA254+3) = 0x10; 

	//portas
	*(BYTE*) (0x00540BD6)    = 0xEB;
	HookFunc(0x00540C1A, (DWORD)(&GSPort));
	HookNop(0x00540C1A+5,44);
	memset((char*)0x076B00C0,0,50);
	memcpy((char*)0x076B00C0,"127.0.0.1",50);
	memset((char*)0x076B01C0,0,50);
	memcpy((char*)0x076B01C0,"127.0.0.1",50);

	*(BYTE*) (0x005343CD+1)  = cfg.portserver;

	//checksum
	if(cfg.checksum == 1)
	{
	  *(BYTE*) (0x00434B9A)  = 0xEB; 
	  *(BYTE*) (0x00434BF8)  = 0xEB;
	}

	//deletar char sem personal ID
	if(cfg.charid == 1)
	{
		*(BYTE*) (0x004374E4)    = 0xEB;
	}

	//deletar guild sem personal ID
	if(cfg.guildid == 1)
	{
		HookNop(0x004481CC, 6);
	    HookNop(0x0044837D, 2);
	}

	//tempo dos items
	*(unsigned int*) (0x004A4812+1)   = cfg.tempitems * 1000;
	*(unsigned int*) (0x004A49C3+1)   = cfg.tempitems * 1000;

	//guild aliança minimo de membros
	*(BYTE*) (0x0045927B+2)  = cfg.allplayer;

	//mana shield
	*(unsigned int*) (0x004CB7DB+1)  = cfg.manaagi;
	*(unsigned int*) (0x004CB7FB+1)  = cfg.manaene;
	*(unsigned int*) (0x004CB826+1)  = cfg.manadiv;

	//great fortitude
	*(unsigned int*) (0x004CB3CF+1)  = cfg.greatvit;
	*(unsigned int*) (0x004CB3EF+1)  = cfg.greatene;

	//experiencia em party
	*(unsigned int*) (0x004F52C7+3)  = cfg.party2;
	*(unsigned int*) (0x0046B836+3)  = cfg.party2;
	*(unsigned int*) (0x004F52D6+3)  = cfg.party3;
	*(unsigned int*) (0x0046B845+3)  = cfg.party3;
	*(unsigned int*) (0x004F52E5+3)  = cfg.party4;
	*(unsigned int*) (0x0046B854+3)  = cfg.party4;
	*(unsigned int*) (0x004F52F4+3)  = cfg.party5;
	*(unsigned int*) (0x0046B863+3)  = cfg.party5;
	*(unsigned int*) (0x004F5291+3)  = cfg.setparty3;
	*(unsigned int*) (0x0046B800+3)  = cfg.setparty3;
	*(unsigned int*) (0x004F52A0+3)  = cfg.setparty4;
	*(unsigned int*) (0x0046B80F+3)  = cfg.setparty4;
	*(unsigned int*) (0x004F52AF+3)  = cfg.setparty5;
	*(unsigned int*) (0x0046B81E+3)  = cfg.setparty5;

	//skills
	*(unsigned int*) (0x00494410+7)  = cfg.twistslash;
	*(unsigned int*) (0x00494429+7)  = cfg.ragefulblow;
	*(unsigned int*) (0x00494442+7)  = cfg.deathstab;
	*(unsigned int*) (0x00494474+7)  = cfg.greatfort;
	*(unsigned int*) (0x0049448D+7)  = cfg.penetration;

	//drop de items
	*(unsigned int*) (0x0041CEBC+6)  = cfg.dropexskill;
	*(unsigned int*) (0x0041CEC6+6)  = cfg.dropexluck;
	*(unsigned int*) (0x0041CF15+6)  = cfg.dropskill;
	*(unsigned int*) (0x0041CF1F+6)  = cfg.dropluck;

	//pontos por level
	*(BYTE*) (0x004EE5AC+2)  = cfg.pointsdl;
	*(BYTE*) (0x004EE5D4+2)  = cfg.pointsmg;
	*(BYTE*) (0x004EE5EB+2)  = cfg.pointsothers;

	//potions life
	*(BYTE*) (0x0044FD7F+3)  = cfg.healing[0];
	*(BYTE*) (0x0044FD88+3)  = cfg.healing[1];
	*(BYTE*) (0x0044FD91+3)  = cfg.healing[2];
	*(BYTE*) (0x0044FD9A+3)  = cfg.healing[3];
	*(BYTE*) (0x0044FDCF+1)  = cfg.healing[4];

	//desabilitar o + 5, level 1
	*(BYTE*) (0x0044FDAB)    = 0xEB;

	//potions mana
	*(BYTE*) (0x004500BB+2)  = cfg.mana[0];
	*(BYTE*) (0x004500BF+1)  = cfg.mana[1];
	*(BYTE*) (0x004500F3+2)  = cfg.mana[2];
	*(BYTE*) (0x004500F7+1)  = cfg.mana[3];
	*(BYTE*) (0x0045012B+2)  = cfg.mana[4];
	*(BYTE*) (0x0045012F+1)  = cfg.mana[5];

	//potions AG
	*(BYTE*) (0x0045029C+2)  = cfg.AG[0];
	*(BYTE*) (0x004502A0+1)  = cfg.AG[1];
	*(BYTE*) (0x004505E2+2)  = cfg.AG[2];
	*(BYTE*) (0x004505E6+1)  = cfg.AG[3];
	*(BYTE*) (0x00450928+2)  = cfg.AG[4];
	*(BYTE*) (0x0045092C+1)  = cfg.AG[5];

	//potions SD
	*(BYTE*) (0x00450C6E+2)  = cfg.SD[0];
	*(BYTE*) (0x00450C72+1)  = cfg.SD[1];
	*(BYTE*) (0x00450E22+2)  = cfg.SD[2];
	*(BYTE*) (0x00450E26+1)  = cfg.SD[3];
	*(BYTE*) (0x00450FD6+2)  = cfg.SD[4];
	*(BYTE*) (0x00450FDA+1)  = cfg.SD[5];

	if(cfg.skillsiege == 1)
	{
	    *(BYTE*) (0x004D0E64)  = 0xEB;
	    *(BYTE*) (0x004D0E74)  = 0xEB;
	    *(BYTE*) (0x004D0F57)  = 0xEB;
	    *(BYTE*) (0x004D0F67)  = 0xEB;
	    *(BYTE*) (0x004D1074)  = 0xEB;
	    *(BYTE*) (0x004D1084)  = 0xEB;
	    *(BYTE*) (0x004D1157)  = 0xEB;
        *(BYTE*) (0x004D1167)  = 0xEB;
	    *(BYTE*) (0x004D1274)  = 0xEB;
	    *(BYTE*) (0x004D1284)  = 0xEB;
	    *(BYTE*) (0x004D1364)  = 0xEB;
	    *(BYTE*) (0x004D1374)  = 0xEB;
	    *(BYTE*) (0x004D1447)  = 0xEB;
	    *(BYTE*) (0x004D1457)  = 0xEB;
	}
    #endif
}

void FixSkillsNoWeapor(LPBYTE aRecv, int index)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);

	if(lpObj->Class == 1 || lpObj->Class == 3)
	{
		if(lpObj->HaveWeaponInHand == FALSE && aRecv[3] == 0x29)
		{
			GCServerMsgStringSend("Você não pode usar a Skill sem arma.",index,1);
			aRecv[3] = 0xFF;
		}
		else
		{
			CGDurationMagicRecv(aRecv,index);
		}
	}
}