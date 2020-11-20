#ifndef SHOPS_H
#define SHOPS_H

#if DLLtype == 0
#define ShopExcellentMod_Hook1						0x00519C84
#define ShopExcellentMod_Exit1						0x00519C8F
#define ShopExcellentMod_Hook2						0x005191FE
#define ShopExcellentMod_Exit2						0x00519203 
#define GetNumber									0x00596470
#define GetToken									0x005964C0
#else
#define ShopExcellentMod_Hook1						0x0052D0A4
#define ShopExcellentMod_Exit1						0x0052D0AF
#define ShopExcellentMod_Hook2						0x0052C61E
#define ShopExcellentMod_Exit2						0x0052C623
#define GetNumber									0x005C9C60
#define GetToken									0x005C9CB0 

#endif

void AssemblyExcShops();

#endif