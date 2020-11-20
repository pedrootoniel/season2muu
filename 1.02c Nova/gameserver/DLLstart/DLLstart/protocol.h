#include "stdafx.h"
#include "packets.h"

void Protocol(BYTE protoNum, unsigned char * aRecv, int aLen, int index, BOOL Encrypt, int serial);
void gObjPlayerDataLoad(PMSG_CHARMAPJOIN * lpRecv, int index);
void gObjPlayerLoad(int index);
void gObjGCUseItemRecv(PMSG_USEITEM* lpMsg,int index);
void GCDeleteItemConvert(int index, char slot, char target);