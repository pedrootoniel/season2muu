#include "stdafx.h"

typedef int (WINAPI*send_gameserver)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
send_gameserver send_gameserver_hook;

void MU_ForceDecode(unsigned char* buf, int len) 
{
	for(int n = 0;n < len;n++)
	{
		buf[n] = (buf[n]^0x35)-0xC8;
	}
}

void MU_ForceEncode(unsigned char* buf, int len) 
{
	for(int n = 0; n < len; n++)
	{
		buf[n] = (buf[n]+0xC8)^0x35;
	}
}

int WINAPI send_gameserver_encrypt(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
{
	MU_ForceEncode((BYTE*)lpBuffers->buf,lpBuffers->len);
	return send_gameserver_hook(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine);
}

void EncryptData()
{
    #if DLLtype == 0
	send_gameserver_hook = *(send_gameserver*)(0xC8CC32C);
	*(DWORD*)(0xC8CC32C) = (DWORD)send_gameserver_encrypt;
    #else
	send_gameserver_hook = *(send_gameserver*)(0x86F232C);
	*(DWORD*)(0x86F232C) = (DWORD)send_gameserver_encrypt;
    #endif
}

BOOL DecryptData(_PER_IO_CONTEXT * context, int index)
{
	MU_ForceDecode((BYTE*)context->Buffer,context->nSentBytes);
	return RecvDataParse(context,index);
}