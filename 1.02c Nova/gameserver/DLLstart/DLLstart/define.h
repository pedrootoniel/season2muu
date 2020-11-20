#include "stdafx.h"

#define DLLtype          1 // 0 = gameserver, 1 = gameserver_cs

#if DLLtype == 0

#define VERSION           "1.0.0.5 SUPREMO GS"

#define       GS_GOBJPONTEIRO	             (0x660F078)
#define       GS_GOBJTAMANHO			     (0x1968)

#define	OBJECT_POINTER(aIndex)  ((aIndex * GS_GOBJTAMANHO) + GS_GOBJPONTEIRO)

#define       MAX_C1LEN                      (255)
#define       MIN_PLAYERID		             (0x1900)
#define       MAX_PLAYERID		             (0x1CE8)
#define       MIN_MONSTERID		             (0)
#define       MAX_MONSTERID		             (5800)

#define       OFFSET_ITEMCONVERT             0x0050E390

#define       OBJECTARRAYFILER               0x3

#else

#define VERSION           "1.0.0.5 SUPREMO CS"

#define       GS_GOBJPONTEIRO	             (0x3D995F8)
#define       GS_GOBJTAMANHO			     (0x197C)

#define	OBJECT_POINTER(aIndex)  ((aIndex * GS_GOBJTAMANHO) + GS_GOBJPONTEIRO)

#define       MAX_C1LEN                      (255)
#define       MIN_PLAYERID		             (0x9C4)
#define       MAX_PLAYERID		             (0xFA0)
#define       MIN_MONSTERID		             (0)
#define       MAX_MONSTERID		             (5800)

#define       OFFSET_ITEMCONVERT             0x004044D5

#define       OBJECTARRAYFILER               0x23
#endif