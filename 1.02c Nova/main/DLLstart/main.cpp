#include "stdafx.h"
#include "camera.h"

void DTcarregarmain()
{
	//Load Correções
	fix();
	gSmokeEffect.Load();
	gFont.Load();

	//HookMiniMap();
	//ip
	memset((char*)0x007A16C0+2,0,50);
	memcpy((char*)0x007A16C0+2,"192.168.0.102",50);
	
	//serial
	memset((char*)0x007A2840,0,20);
    memcpy((char*)0x007A2840,"0000000000000000",20);

	// Titulo
	int *gTitle = (int*)(0x007A2448);
	memset(&gTitle[0],0x00,sizeof("MuOnline1"));
	memcpy(&gTitle[0],"MuOnline1",sizeof("MuOnline1"));
	

	//send e recv encrypt
	//encryptpackethook();
	//*(BYTE*) (0x00746D2C+1)    = 0xD6; //F8
	//*(BYTE*) (0x00746D2E+2)    = 0x76; //3D
	//*(BYTE*) (0x00746E93+1)    = 0xD6; //F8
	//*(BYTE*) (0x00746E97+1)    = 0x76; //3D

	//speed
	//hook_extended(0x006B458E,                (DWORD)(&speedhacker));
	//func_nop(0x006B458E+5, 8);

	//hook_extended(0x004DCFC3,                (DWORD)(&character_load));
	//func_nop(0x004DCFC3+5, 3);

	//hook_extended(0x00589F15,                (DWORD)(&calcharacter_restruct));
	//func_nop(0x00589F15+5, 2);

	//hook_extended(0x0058A4D7,                (DWORD)(&calcharacter_restruct_speed));
	//func_nop(0x0058A4D7+5, 14);

	//hook_extended(0x005142AE,                (DWORD)(&attack_speed_restruct));
	//func_nop(0x005142AE+5, 2);

	//camera 3D
	MouseSetHook(true); 
	KeyboardSetHook(true);

	//protocolo
   // hook_extended_call(0x004FF68D,           (DWORD)(&Protocol));
	LoadProtocol();
	//pontos fixado acima de 65535
	hook_extended(0x0064AACF,                (DWORD)(&gObjPointsFix));
	func_nop(0x0064AACF+5, 6);

	//mensagem vermelha
	hook_extended(0x004DF452,                (DWORD)(&gObjMessage));
	func_nop(0x004DF452+5, 42);

	//sistema de textura e cores
	LoadTexture(".\\DTserver\\texture\\texture.dat");
	hook_extended(0x0068458B,                (DWORD)(&gObjTexture));
	func_nop(0x0068458B+5, 20);
	LoadLibrary(".\\DTserver\\loadlibrary\\loadlibrary++.dll");		// texture
	LoadLibrary(".\\DTserver\\loadlibrary\\loadlibrary+.dll");		// glow
	LoadLibrary(".\\DTserver\\loadlibrary\\loadlibrary+++.dll");	// weapows
	//novas joias cores
	hook_extended(0x005FD935,                (DWORD)(&gObjItemColorInventory));
	func_nop(0x005FD935+5, 5);

	//novas joias informações
	hook_extended(0x006010AC,                (DWORD)(&gObjItemInformation));
	func_nop(0x006010AC+5, 55);

	//novas joias inserir no item 01
	hook_extended(0x00619217,                (DWORD)(&gObjItemInsertOne));
	func_nop(0x00619217+5, 2);

	//novas joias inserir no item 02
	hook_extended(0x0062F939,                (DWORD)(&gObjItemInsertTwo));
	func_nop(0x0062F939+5, 2);

	//novas joias cor
	hook_extended(0x0060644C,                (DWORD)(&gObjItemColorDrop));
	func_nop(0x0060644C+5, 5);

	//novas joias dropar
	hook_extended(0x006307C8,                (DWORD)(&gObjItemNoDrop));
	func_nop(0x006307C8+5, 5);

	//click
	hook_extended(0x00615458,                (DWORD)(&gObjItemClick));
	func_nop(0x00615458+5, 5);

	/* brilho dos items + 14 & + 15 */

	/* fumaça dos sets fixada em + 15 */
    *(BYTE*)(0x00521567+2)	 = 0x0D;
	*(BYTE*)(0x0052159D+2)	 = 0x0D;
	/* extensão até + 16 */
	*(BYTE*)(0x0067C390+3)  = 0x10; 
    /* extensão ate + 15 defesa, danos, etc..., alteração da variavel até + 11 */
	*(BYTE*)(0x00583B62+3)  = 0x0B;
    *(BYTE*)(0x00583B68+3)  = 0x0B;
	*(BYTE*)(0x00583B91+2)  = 0x0B;

	*(BYTE*)(0x00583C8D+3)  = 0x0B;
    *(BYTE*)(0x00583C93+3)  = 0x0B;
	*(BYTE*)(0x00583CBC+2)  = 0x0B;

	*(BYTE*)(0x00583DAF+3)  = 0x0B;
	*(BYTE*)(0x00583DB5+3)  = 0x0B;
	*(BYTE*)(0x00583DDB+2)  = 0x0B;

	*(BYTE*)(0x00583EC0+3)  = 0x0B;
	*(BYTE*)(0x00583EC6+3)  = 0x0B;
	*(BYTE*)(0x00583EEC+2)  = 0x0B;

	*(BYTE*)(0x00584069+3)  = 0x0B;
	*(BYTE*)(0x0058406F+3)  = 0x0B;

	*(BYTE*)(0x005840A4+3)  = 0x0B;
	*(BYTE*)(0x005840AA+3)  = 0x0B;

	*(BYTE*)(0x005840D1+3)  = 0x0B;
	*(BYTE*)(0x005840D7+3)  = 0x0B;
	*(BYTE*)(0x00584100+2)  = 0x0B;

	*(BYTE*)(0x00584177+3)  = 0x0B;
	*(BYTE*)(0x0058417D+3)  = 0x0B;
	*(BYTE*)(0x005841A6+2)  = 0x0B;

	//deixa a cor das wings level 1 normal
	//retira o nome excellente
	//visualisa as options
	*(BYTE*)(0x005FDA14+3)	= 0x00; 
	*(BYTE*)(0x005FF0D9+3)	= 0x00;
	*(BYTE*)(0x0058466E+1)	= 0x00;

	//altera o limite de items :: case sets
	func_byte(0x006813F3+3, 0x7F);
	func_byte(0x006819DD+3, 0x7F);
	func_byte(0x00681CDD+3, 0x7F);
	func_byte(0x006826E2+3, 0x7F);
	func_byte(0x006827B1+3, 0x7F);
	// case armas
	func_byte(0x006854A2+3, 0x7F);
	func_byte(0x00683B4D+3, 0x7F);
	func_byte(0x00683B8A+3, 0x7F);
	func_byte(0x00683C36+3, 0x7F);
	func_byte(0x00683CFB+3, 0x7F);
	func_byte(0x00683A08+3, 0x7F);
	func_byte(0x00683C8C+3, 0x7F);
	// case wings
	func_byte(0x00684BC3+3, 0x7F);
	func_byte(0x00684AED+3, 0x7F);

	//screenshots
	_mkdir("screenshots");
	memset((char*)0x007B5E10,0,60);
	memcpy((char*)0x007B5E10,".\\screenshots\\Screen(%02d_%02d-%02d_%02d)-%04d.jpg",60);

	rmdir(".\\DTserver\\dlls");
	rmdir(".\\DTserver\\scripts");
}

bool APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch(ul_reason_for_call)
	{
	    case DLL_PROCESS_ATTACH:
		  DTcarregarmain();
		break;
	    case DLL_PROCESS_DETACH: 
		break;
	}

	if(ul_reason_for_call == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	}

	return TRUE;
}