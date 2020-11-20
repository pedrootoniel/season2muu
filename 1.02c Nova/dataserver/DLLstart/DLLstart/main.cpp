#include "stdafx.h"

extern "C" _declspec(dllexport) void dllinit()
{
	DWORD Protect;

	if(VirtualProtect(LPVOID(0x401000),3543191,0x40,&Protect))
	{	
		//database connect
		database.Connect();
		//carrega as configurações
		cfg.load();
		//hooks
		HookFunc(0x00403FED, (DWORD)(&Protocol));
		HookFunc(0x004068AD, (DWORD)(&Protocol));
	}
}