#include "stdafx.h"

// cores:
// 0x00 = branco
// 0x01 = azul
// 0x02 = vermelho
// 0x03 = amarelo
// 0x04 = verde
// 0x05 = branco no vermelho
// 0x06 = cinza
// 0x07 = branco no azul
// 0x08 = branco no amarelo
// 0x09 = verde no azul
// 0x0A = cinza (2)
// 0x0B = cinza escuro

//variaveis usadas
char * jewel_infor = "";
int   joia_ID      = 0;
short item_ID      = 0;
int   invcolor     = 0;
int   color        = 0;
int   text         = 0;
char  number       = 0;
float RR           = 0.0f;
float GG           = 0.0f;
float BB           = 0.0f;

__declspec(naked) void gObjItemColorInventory()
{
	_asm
	{
		mov dx,word ptr ds:[ebp]
		mov joia_ID, edx
	}

	if(joia_ID == ITEMGET(14,16)) // jewel of life
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(14,63)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,64)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,65)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,66)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,67)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,68)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,69)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,72)) // jewel
	{
		invcolor = 2;
	}
	else if(joia_ID == ITEMGET(14,73)) // jewel
	{
		invcolor = 2;
	}
	//inserir novos items
	else
	{
		_asm // retornar para a função original
		{
		mov eax, 0x005FD93F
	    jmp eax
		}
	}

	_asm // função da cor
	{
	mov edi, invcolor;
	mov eax,dword ptr ds:[0x79F4B00]
	mov dword ptr ss:[esp+0x20],edi
	mov eax, 0x005FDA10
	jmp eax
	}
}

__declspec(naked) void gObjItemInformation()
{
  	_asm
	{
		mov dx, word ptr ss:[ebp]
		mov joia_ID, edx
	}

	if(joia_ID == ITEMGET(14,16))
	{
		color = 0;
		text  = 0;
		jewel_infor = (char*)0x077D7C34;
	}
	else if(joia_ID == ITEMGET(14,63))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial deixa seu item excellente";
	}
	else if(joia_ID == ITEMGET(14,64))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial upa seu item em até + 13";
	}
	else if(joia_ID == ITEMGET(14,65))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial deixa seu item anciet";
	}
	else if(joia_ID == ITEMGET(14,66))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial adiciona luck ao seu item";
	}
	else if(joia_ID == ITEMGET(14,67))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial adiciona skill a sua arma ou shield";
	}
	else if(joia_ID == ITEMGET(14,68))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial aumenta o level do item";
	}
	else if(joia_ID == ITEMGET(14,69))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Joia rara especial adiciona life em + 16";
	}
	else if(joia_ID == ITEMGET(14,72))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Jewel: credita resets em seu char";
	}
	else if(joia_ID == ITEMGET(14,73))
	{
		color = 2;
		text  = 2;
		jewel_infor = "Jewel: retira opção anciet";
	}
	//inserir novos items
	else
	{
		_asm
		{
	        mov edi, 0x006010E8
	        jmp edi
		}
	}

	_asm
	{
    lea eax,dword ptr ds:[eax+eax*4]
    PUSH jewel_infor
    lea edx,dword ptr ds:[eax+eax*4]
	lea eax,dword ptr ds:[edx*4+0x79C1E10]
    push eax
    call CALL_INFOR
    mov eax,dword ptr ds:[0x79F4B00]
    add esp,8
	mov esi, color
    mov dword ptr ds:[EAX*4+0x79C2FAC],esi
	mov edi, text
    mov dword ptr ds:[EAX*4+0x79F1FA0],edi
    inc eax
    mov dword ptr ds:[0x79F4B00],eax
	mov edi, 0x006010E8
	jmp edi
	CALL_INFOR:
	mov edi, 0x00755E60
    jmp edi
	}
}

__declspec(naked) void gObjItemInsertOne()
{
	_asm
	{
		mov joia_ID, esi
	}

	if(joia_ID == ITEMGET(14,13)) // jewel of bless
	{
	}
	else if(joia_ID == ITEMGET(14,63)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,64)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,65)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,66)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,67)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,68)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,69)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,72)) // jewel
	{
	}
	else if(joia_ID == ITEMGET(14,73)) // jewel
	{
	}
	else
	{
			_asm
			{
			   mov edi, 0x0061921E
	           jmp edi
			}
	}

	_asm // função de inserir na jewel
    {
	   MOV EDI, 0x0061925F
	   JMP EDI
    }
}

__declspec(naked) void gObjItemInsertTwo()
{
	_asm
	{
		mov joia_ID, edx
	}

	switch(joia_ID)
	{
	    case ITEMGET(14,16): // jewel of life
		break;
	    case ITEMGET(14,63): // jewel
		break;
	    case ITEMGET(14,64): // jewel
		break;
	    case ITEMGET(14,65): // jewel
		break;
	    case ITEMGET(14,66): // jewel
		break;
	    case ITEMGET(14,67): // jewel
		break;
	    case ITEMGET(14,68): // jewel
		break;
	    case ITEMGET(14,69): // jewel
		break;
	    case ITEMGET(14,72): // jewel
		break;
	    case ITEMGET(14,73): // jewel
		break;
		default: // caso não ache a joia volta para a função original
			_asm
			{
			   mov edx,dword ptr ds:[0x79C29C8] // fix
			   mov eax, 0x0062F940
	           jmp eax
			}
		break;
	}

	_asm // função de inserir na jewel
	{
	mov eax, 0x0062F959
	jmp eax
	}
}

__declspec(naked) void gObjItemColorDrop()
{
	_asm
	{
	   mov item_ID, ax
	}

	if(item_ID == ITEM_GET(14,13)) // jewel of bless
	{
		RR = 1.000000f;
		GG = 0.800000f;
		BB = 0.100000f;
	}
	else if(item_ID == ITEM_GET(14,63)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,64)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,65)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,66)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,67)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,68)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,69)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,72)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	else if(item_ID == ITEM_GET(14,73)) // jewel
	{
		RR = 0.95f;
		GG = 0.1425f;
		BB = 0.1425f;
	}
	//adicionar cores dos novos items drops
	else
	{
		_asm // retornar para a função original
		{
	    mov edx, 0x00606456
	    jmp edx
		}
	}

	_asm // função das cores
	{
    mov edx,dword ptr ds:[0x5841E44]
    mov eax,dword ptr ds:[0x5841DD8]
    push edx
    push eax
    call ebx
	push BB
	push GG
	push RR
    call dword ptr ds:[0x78337C]
	mov edx, 0x006075B2
	jmp edx
	}
}

__declspec(naked) void gObjItemNoDrop()
{

	_asm
	{
		mov item_ID, ax
	}

	if(item_ID == ITEMGET(14,16)) // jewel of life
	{
	}
	else if(item_ID == ITEMGET(14,63)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,64)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,65)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,66)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,67)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,68)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,69)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,72)) // jewel
	{
	}
	else if(item_ID == ITEMGET(14,73)) // jewel
	{
	}
	else
	{
		_asm // retorna para a função original
		{
	        mov ebx, 0x006307D2
	        jmp ebx
		}
	}

	_asm // função de não dropar
	{
	mov ebx, 0x00630895
	jmp ebx
	}
}

__declspec(naked) void gObjItemClick()
{

	_asm
	{
		mov joia_ID, eax
	}

	switch(joia_ID)
	{
	    case ITEMGET(12,35): // scroll fire scream
		break;
		default: // caso não ache a joia volta para a função original
			_asm
			{
			   mov ecx, 0x00615462
	           jmp ecx
			}
		break;
	}

	_asm // função de inserir na jewel
	{
	mov ecx, 0x00616A90
	jmp ecx
	}
}