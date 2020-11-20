#include "stdafx.h"

extern "C" _declspec(dllexport) void dllinit()
{
	DWORD Protect;

	if(VirtualProtect(LPVOID(0x401000),3543191,0x40,&Protect))
	{	
		//carrega as configurações
		cfg.load();
		AssemblyExcShops();
		//carrega as correções dos gameservers
		GSLoadFix();
		//sistema de noticias
		noticestart.load();
		//hooks
		#if DLLtype == 0
		HookFunc(0x00403314, (DWORD)(&Protocol));
		HookFunc(0x004057BD, (DWORD)(&ProtocolDS));
		HookFunc(0x00404D4F, (DWORD)(&gObjLevelUpPointAdd));
	    HookFunc(0x004E2C20, (DWORD)(&gObjMonsterExp));                 HookNop(0x004E2C25,  9);
	    HookFunc(0x004E3315, (DWORD)(&gObjMonsterExpParty));            HookNop(0x004E331A,  9);
	    HookFunc(0x004E3452, (DWORD)(&gObjMonsterExpPartyZen));         HookNop(0x004E3457,  9);
	    HookFunc(0x004658B9, (DWORD)(&gObjMonsterExpDevil));            HookNop(0x004658BE,  9);
	    HookFunc(0x00465F0E, (DWORD)(&gObjMonsterExpPartyDevil));       HookNop(0x00465F13,  9);
	    HookFunc(0x00466069, (DWORD)(&gObjMonsterExpPartyDevilZen));    HookNop(0x0046606E,  9);
		HookFunc(0x00401F3C, (DWORD)(&gObjLotteryItemMix));
		HookFunc(0x004060C3, (DWORD)(&gObjGCLevelUpMsgSend));
		HookFunc(0x00405E7A, (DWORD)(&gObjgObjAttack));
		HookFunc(0x0041B102, (DWORD)(&gObjItemDrop));                   HookNop(0x0041B102+5,23);
		HookFunc(0x00402FB3, (DWORD)(&NpcTalkClick));
		HookFunc(0x004033F5, (DWORD)(&BloodCastleDROP));
		if(ccastle.active == 1)
		{
			HookFunc(0x00401CAD, (DWORD)(&ChaosCastleDROP));
		}
		HookFunc(0x00467E5A, (DWORD)(&DevilSquareDROP));                HookNop(0x00467E5A+5, 3);
		HookFunc(0x004017C6, (DWORD)(&gObjGameMonsterAllAdd));
		HookFunc(0x004FE97C, (DWORD)(&gObjSoulRateLuck));               HookNop(0x004FE97C+5, 1);
		HookFunc(0x004FEA5B, (DWORD)(&gObjSoulRateNoLuck));             HookNop(0x004FE97C+5, 1);
		HookFunc(0x004FF1EA, (DWORD)(&gObjLifeRate));                   HookNop(0x004FF1EA+5, 1);
		HookFunc(0x00554DE5, (DWORD)(&gObjElfSoldier));                 HookNop(0x00554DE5+5, 12);
		HookFunc(0x00496607, (DWORD)(&gObjRateMixLevel));               HookNop(0x00496607+5, 239);
		HookFunc(0x00432375, (DWORD)(&gObjGMGlobalMsg));                HookNop(0x00432375+5, 10);
		HookFunc(0x00404426, (DWORD)(&gObjSavePetItemInfo));
		HookFunc(0x00404E4E, (DWORD)(&gObjDrop));
		HookFunc(0x00401406, (DWORD)(&gObjGCUseItemRecv));
		HookFunc(0x00490569, (DWORD)(&gObjZen));                        HookNop(0x00490569+5, 5);
		HookFunc(0x00403D91, (DWORD)(&gObjJGAnsMapSvrAuth));     
		//EncryptData();
		//HookFunc(0x00406389, (DWORD)(&DecryptData));
		//*(BYTE*) (0x00596C4C+1)    = 0xD6; //F8
		//*(BYTE*) (0x00596C4E+2)    = 0x76; //3D
		//*(BYTE*) (0x00596DB3+1)    = 0xD6; //F8
		//*(BYTE*) (0x00596DB7+1)    = 0x76; //3D

		//versão
	    memset(  (void*)0x006BF098, 0, 20);
	    strcpy_s((char*)0x006BF098, 20,VERSION);
	    *(DWORD*)(0x004A9747+1) = RGB(40, 40, 40);
	    *(DWORD*)(0x004A972D+1) = 0;

		NpcTalkGuardMessage();
		HookFunc(0x0040202C, (DWORD)(&GCGuildWarRequestResult));
		
		/*HookFunc(0x00402B08, (DWORD)(&gObjCalCharacter_Hook));*/
		/*HookFunc(0x004057EA, (DWORD)(&_gObjSetCharacter));*/

        #else
		HookFunc(0x004036AC, (DWORD)(&Protocol));
		HookFunc(0x00405C2C, (DWORD)(&ProtocolDS));
		HookFunc(0x00405010, (DWORD)(&gObjLevelUpPointAdd));
	    HookFunc(0x004F4E30, (DWORD)(&gObjMonsterExp));                 HookNop(0x004F4E35, 9);
	    HookFunc(0x004F5525, (DWORD)(&gObjMonsterExpParty));            HookNop(0x004F552A, 9);
	    HookFunc(0x004F5662, (DWORD)(&gObjMonsterExpPartyZen));         HookNop(0x004F5667, 9);
		HookFunc(0x004021CB, (DWORD)(&gObjLotteryItemMix));
		HookFunc(0x004066A9, (DWORD)(&gObjGCLevelUpMsgSend));
		HookFunc(0x004063FC, (DWORD)(&gObjgObjAttack));
		HookFunc(0x0041CB72, (DWORD)(&gObjItemDrop));                   HookNop(0x0041CB72+5,23);
		HookFunc(0x00406B5E, (DWORD)(&NpcTalkClick));
		HookFunc(0x00401929, (DWORD)(&gObjGameMonsterAllAdd));
		HookFunc(0x00511CCC, (DWORD)(&gObjSoulRateLuck));               HookNop(0x00511CCC+5, 1);
		HookFunc(0x00511DAB, (DWORD)(&gObjSoulRateNoLuck));             HookNop(0x00511DAB+5, 1);
		HookFunc(0x0051253A, (DWORD)(&gObjLifeRate));                   HookNop(0x0051253A+5, 1);
		HookFunc(0x0058B0F5, (DWORD)(&gObjElfSoldier));                 HookNop(0x0058B0F5+5, 12);
		HookFunc(0x004A73D7, (DWORD)(&gObjRateMixLevel));               HookNop(0x004A73D7+5, 239);
		HookFunc(0x00435335, (DWORD)(&gObjGMGlobalMsg));                HookNop(0x00435335+5, 10);
		HookFunc(0x00404557, (DWORD)(&gObjSavePetItemInfo));
		HookFunc(0x0040513C, (DWORD)(&gObjDrop));
		HookFunc(0x004014B5, (DWORD)(&gObjGCUseItemRecv));
		HookFunc(0x004A1339, (DWORD)(&gObjZen));                        HookNop(0x004A1339+5, 5);
		HookFunc(0x00403DC3, (DWORD)(&gObjJGAnsMapSvrAuth));   
		//EncryptData();
		//HookFunc(0x004069D3, (DWORD)(&DecryptData));
		//*(BYTE*) (0x005CA43C+1)    = 0xD6; //F8
		//*(BYTE*) (0x005CA43E+2)    = 0x76; //3D
		//*(BYTE*) (0x005CA5A3+1)    = 0xD6; //F8
		//*(BYTE*) (0x005CA5A7+1)    = 0x76; //3D

		//versão
	    memset(  (void*)0x00711A00, 0, 20);
	    strcpy_s((char*)0x00711A00, 20,VERSION);
	    *(DWORD*)(0x004BAD57+1) = RGB(40, 40, 40);
	    *(DWORD*)(0x004BAD3D+1) = 0;
		
		//HookFunc(0x00402FE0, (DWORD)(&gObjCalCharacter_Hook));
		/*HookFunc(0x00405C59, (DWORD)(&_gObjSetCharacter));*/
        #endif
	}
}