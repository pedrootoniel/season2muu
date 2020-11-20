#include "stdafx.h"
void SetNop(DWORD dwOffset, int Size);
void HookFunc(DWORD offset, DWORD funcao);
void HookNop(DWORD offset, int x);
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size);
void buxconvert(char* buf, int size);
void GCAllianceMessage(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID);
int  Rand(int min, int max);
void GCGuildWarRequestResult(LPSTR GuildName, int aIndex, int type);