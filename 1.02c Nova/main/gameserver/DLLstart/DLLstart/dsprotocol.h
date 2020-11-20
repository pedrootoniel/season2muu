#include "stdafx.h"
#include "packets.h"

void ProtocolDS(BYTE protoNum, unsigned char* aRecv, int aLen);
void aRecvPlayerInfo(PLAYER_OBJECT * pDataServer);
int  DataServerSend(unsigned char* buf, int len);