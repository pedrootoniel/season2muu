#include "stdafx.h"

/* função para não bugarem o personagem na tela de seleção */

char namerecv[11];
void gObjNameExit(char * name)
{
	if(strcmp(name,namerecv) != 0)
	{
		ExitProcess(1);
	}
}

__declspec(naked) void gObjNameCheck(char * name)
{
	_asm
	{
    push ebp
    mov ebp,esp
    sub esp,0x1c
    push name
    mov ecx,0x5841988
    call load
    push name
    mov edx,0x5841988
    call gObjNameExit
    mov esp, ebp
    pop ebp
    retn
load:
	mov edi, 0x0040BA70
	jmp edi
	}
}