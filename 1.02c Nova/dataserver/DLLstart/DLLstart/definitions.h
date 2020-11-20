#include "stdafx.h"

typedef void(*pProtocolCore)(BYTE protoNum, BYTE *aRecv, int aLen, short index);
extern pProtocolCore ProtocolCore;

typedef int(*pDataSend)(int aIndex, LPBYTE lpMsg, DWORD dwSize);
extern pDataSend DataSend;

typedef void(*pLogAddFuncColor)(BYTE Color, char* szLog, ...);
extern pLogAddFuncColor LogAddFuncColor;