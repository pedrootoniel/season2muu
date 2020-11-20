#include "stdafx.h"

void Calcharacter()
{
	#if DLLtype == 0
	//----------------------------
	*(BYTE*)(0x004C2BD3+1) = GetPrivateProfileInt("calcharacter","config_01", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2BEA+2) = GetPrivateProfileInt("calcharacter","config_02", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2C02+1) = GetPrivateProfileInt("calcharacter","config_03", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2C19+2) = GetPrivateProfileInt("calcharacter","config_04", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C2C33+1) = GetPrivateProfileInt("calcharacter","config_05", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2C40+1) = GetPrivateProfileInt("calcharacter","config_06", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2C56+2) = GetPrivateProfileInt("calcharacter","config_07", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2C64+2) = GetPrivateProfileInt("calcharacter","config_08", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2C7B+1) = GetPrivateProfileInt("calcharacter","config_09", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2C88+1) = GetPrivateProfileInt("calcharacter","config_10", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2C9E+2) = GetPrivateProfileInt("calcharacter","config_11", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2CAC+2) = GetPrivateProfileInt("calcharacter","config_12", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C2CC8+1) = GetPrivateProfileInt("calcharacter","config_13", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2CDF+2) = GetPrivateProfileInt("calcharacter","config_14", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2CF7+1) = GetPrivateProfileInt("calcharacter","config_15", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2D0E+2) = GetPrivateProfileInt("calcharacter","config_16", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C2D39+1) = GetPrivateProfileInt("calcharacter","config_17", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2D4D+2) = GetPrivateProfileInt("calcharacter","config_18", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2D62+1) = GetPrivateProfileInt("calcharacter","config_19", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2D76+2) = GetPrivateProfileInt("calcharacter","config_20", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C2DA5+1) = GetPrivateProfileInt("calcharacter","config_21", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2DB2+1) = GetPrivateProfileInt("calcharacter","config_22", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2DC8+2) = GetPrivateProfileInt("calcharacter","config_23", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2DD6+2) = GetPrivateProfileInt("calcharacter","config_24", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2DED+1) = GetPrivateProfileInt("calcharacter","config_25", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2DFA+1) = GetPrivateProfileInt("calcharacter","config_26", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2E10+2) = GetPrivateProfileInt("calcharacter","config_27", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2E1E+2) = GetPrivateProfileInt("calcharacter","config_28", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C2E4F+1) = GetPrivateProfileInt("calcharacter","config_29", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2E5C+1) = GetPrivateProfileInt("calcharacter","config_30", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2E72+1) = GetPrivateProfileInt("calcharacter","config_31", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2E7F+1) = GetPrivateProfileInt("calcharacter","config_32", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2E95+1) = GetPrivateProfileInt("calcharacter","config_33", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2EA2+1) = GetPrivateProfileInt("calcharacter","config_34", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2EB8+1) = GetPrivateProfileInt("calcharacter","config_35", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C2EC5+1) = GetPrivateProfileInt("calcharacter","config_36", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C2EDD+2) = GetPrivateProfileInt("calcharacter","config_37", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2EF2+2) = GetPrivateProfileInt("calcharacter","config_38", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2F07+2) = GetPrivateProfileInt("calcharacter","config_39", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C2F1C+2) = GetPrivateProfileInt("calcharacter","config_40", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C3436+1) = GetPrivateProfileInt("calcharacter","config_41", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C344A+1) = GetPrivateProfileInt("calcharacter","config_42", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C3485+1) = GetPrivateProfileInt("calcharacter","config_43", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3499+1) = GetPrivateProfileInt("calcharacter","config_44", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C34C0+1) = GetPrivateProfileInt("calcharacter","config_45", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C34D4+1) = GetPrivateProfileInt("calcharacter","config_46", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C34EA+1) = GetPrivateProfileInt("calcharacter","config_47", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C34FE+1) = GetPrivateProfileInt("calcharacter","config_48", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C3882+2) = GetPrivateProfileInt("calcharacter","config_49", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3886+1) = GetPrivateProfileInt("calcharacter","config_50", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38AA+2) = GetPrivateProfileInt("calcharacter","config_51", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38AE+1) = GetPrivateProfileInt("calcharacter","config_52", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38D2+2) = GetPrivateProfileInt("calcharacter","config_53", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38D6+1) = GetPrivateProfileInt("calcharacter","config_54", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38FA+2) = GetPrivateProfileInt("calcharacter","config_55", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C38FE+1) = GetPrivateProfileInt("calcharacter","config_56", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3922+2) = GetPrivateProfileInt("calcharacter","config_57", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3926+1) = GetPrivateProfileInt("calcharacter","config_58", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C394A+2) = GetPrivateProfileInt("calcharacter","config_59", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C394E+1) = GetPrivateProfileInt("calcharacter","config_60", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3972+2) = GetPrivateProfileInt("calcharacter","config_61", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3987+2) = GetPrivateProfileInt("calcharacter","config_62", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C3A5C+2) = GetPrivateProfileInt("calcharacter","config_63", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C3A84+1) = GetPrivateProfileInt("calcharacter","config_64", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3A9A+1) = GetPrivateProfileInt("calcharacter","config_65", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C3EB5+1) = GetPrivateProfileInt("calcharacter","config_66", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3EDC+1) = GetPrivateProfileInt("calcharacter","config_67", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3F03+1) = GetPrivateProfileInt("calcharacter","config_68", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C3F19+2) = GetPrivateProfileInt("calcharacter","config_69", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004C4C53+2) = GetPrivateProfileInt("calcharacter","config_70", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4C57+1) = GetPrivateProfileInt("calcharacter","config_71", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4C70+2) = GetPrivateProfileInt("calcharacter","config_72", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4C74+1) = GetPrivateProfileInt("calcharacter","config_73", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4C8D+2) = GetPrivateProfileInt("calcharacter","config_74", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4C91+1) = GetPrivateProfileInt("calcharacter","config_75", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4CAA+2) = GetPrivateProfileInt("calcharacter","config_76", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C4CAE+1) = GetPrivateProfileInt("calcharacter","config_77", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B6E8F+2) = GetPrivateProfileInt("calcharacter","config_78", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6E9C+2) = GetPrivateProfileInt("calcharacter","config_79", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6EA0+1) = GetPrivateProfileInt("calcharacter","config_80", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B6ED2+2) = GetPrivateProfileInt("calcharacter","config_81", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B6F0B+2) = GetPrivateProfileInt("calcharacter","config_82", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6F18+2) = GetPrivateProfileInt("calcharacter","config_83", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6F1C+1) = GetPrivateProfileInt("calcharacter","config_84", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B6F4B+2) = GetPrivateProfileInt("calcharacter","config_85", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6F58+2) = GetPrivateProfileInt("calcharacter","config_86", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B6F5C+1) = GetPrivateProfileInt("calcharacter","config_87", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B6F8A+2) = GetPrivateProfileInt("calcharacter","config_88", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004B703F+1) = GetPrivateProfileInt("calcharacter","config_89", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004B707A+2) = GetPrivateProfileInt("calcharacter","config_90", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004B70B5+2) = GetPrivateProfileInt("calcharacter","config_91", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
    #else
	//----------------------------
	*(BYTE*)(0x004D49A3+1) = GetPrivateProfileInt("calcharacter","config_01", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D59BA+2) = GetPrivateProfileInt("calcharacter","config_02", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D49D2+1) = GetPrivateProfileInt("calcharacter","config_03", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D49E9+2) = GetPrivateProfileInt("calcharacter","config_04", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D4A03+1) = GetPrivateProfileInt("calcharacter","config_05", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4A10+1) = GetPrivateProfileInt("calcharacter","config_06", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4A26+2) = GetPrivateProfileInt("calcharacter","config_07", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4A34+2) = GetPrivateProfileInt("calcharacter","config_08", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4A4B+1) = GetPrivateProfileInt("calcharacter","config_09", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4A58+1) = GetPrivateProfileInt("calcharacter","config_10", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4A6E+2) = GetPrivateProfileInt("calcharacter","config_11", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4A7C+2) = GetPrivateProfileInt("calcharacter","config_12", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D4A98+1) = GetPrivateProfileInt("calcharacter","config_13", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4AAF+2) = GetPrivateProfileInt("calcharacter","config_14", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4AC7+1) = GetPrivateProfileInt("calcharacter","config_15", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4ADE+2) = GetPrivateProfileInt("calcharacter","config_16", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D4B09+1) = GetPrivateProfileInt("calcharacter","config_17", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4B1D+2) = GetPrivateProfileInt("calcharacter","config_18", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4B32+1) = GetPrivateProfileInt("calcharacter","config_19", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4B46+2) = GetPrivateProfileInt("calcharacter","config_20", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D4B75+1) = GetPrivateProfileInt("calcharacter","config_21", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4B82+1) = GetPrivateProfileInt("calcharacter","config_22", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4B98+2) = GetPrivateProfileInt("calcharacter","config_23", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4BA6+2) = GetPrivateProfileInt("calcharacter","config_24", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4BBD+1) = GetPrivateProfileInt("calcharacter","config_25", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4BCA+1) = GetPrivateProfileInt("calcharacter","config_26", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4BE0+2) = GetPrivateProfileInt("calcharacter","config_27", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4BEE+2) = GetPrivateProfileInt("calcharacter","config_28", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D4C1F+1) = GetPrivateProfileInt("calcharacter","config_29", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C2C+1) = GetPrivateProfileInt("calcharacter","config_30", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C42+1) = GetPrivateProfileInt("calcharacter","config_31", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C4F+1) = GetPrivateProfileInt("calcharacter","config_32", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C65+1) = GetPrivateProfileInt("calcharacter","config_33", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C72+1) = GetPrivateProfileInt("calcharacter","config_34", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C88+1) = GetPrivateProfileInt("calcharacter","config_35", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D4C95+1) = GetPrivateProfileInt("calcharacter","config_36", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D4CAD+2) = GetPrivateProfileInt("calcharacter","config_37", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4CC2+2) = GetPrivateProfileInt("calcharacter","config_38", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4CD7+2) = GetPrivateProfileInt("calcharacter","config_39", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D4CEC+2) = GetPrivateProfileInt("calcharacter","config_40", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D5206+1) = GetPrivateProfileInt("calcharacter","config_41", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D521A+1) = GetPrivateProfileInt("calcharacter","config_42", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D5255+1) = GetPrivateProfileInt("calcharacter","config_43", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5269+1) = GetPrivateProfileInt("calcharacter","config_44", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D5290+1) = GetPrivateProfileInt("calcharacter","config_45", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D52A4+1) = GetPrivateProfileInt("calcharacter","config_46", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D52BA+1) = GetPrivateProfileInt("calcharacter","config_47", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D52CE+1) = GetPrivateProfileInt("calcharacter","config_48", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D5652+2) = GetPrivateProfileInt("calcharacter","config_49", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5656+1) = GetPrivateProfileInt("calcharacter","config_50", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D567A+2) = GetPrivateProfileInt("calcharacter","config_51", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D567E+1) = GetPrivateProfileInt("calcharacter","config_52", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56A2+2) = GetPrivateProfileInt("calcharacter","config_53", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56A6+1) = GetPrivateProfileInt("calcharacter","config_54", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56CA+2) = GetPrivateProfileInt("calcharacter","config_55", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56CE+1) = GetPrivateProfileInt("calcharacter","config_56", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56F2+2) = GetPrivateProfileInt("calcharacter","config_57", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D56F6+1) = GetPrivateProfileInt("calcharacter","config_58", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D571A+2) = GetPrivateProfileInt("calcharacter","config_59", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D571E+1) = GetPrivateProfileInt("calcharacter","config_60", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5742+2) = GetPrivateProfileInt("calcharacter","config_61", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5757+2) = GetPrivateProfileInt("calcharacter","config_62", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D582C+2) = GetPrivateProfileInt("calcharacter","config_63", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004D5854+1) = GetPrivateProfileInt("calcharacter","config_64", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D586A+1) = GetPrivateProfileInt("calcharacter","config_65", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004D5C85+1) = GetPrivateProfileInt("calcharacter","config_66", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5CAC+1) = GetPrivateProfileInt("calcharacter","config_67", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5CD3+1) = GetPrivateProfileInt("calcharacter","config_68", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D5CE9+2) = GetPrivateProfileInt("calcharacter","config_69", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	//----------------------------
	*(BYTE*)(0x004D6A23+2) = GetPrivateProfileInt("calcharacter","config_70", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A27+1) = GetPrivateProfileInt("calcharacter","config_71", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A40+2) = GetPrivateProfileInt("calcharacter","config_72", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A44+1) = GetPrivateProfileInt("calcharacter","config_73", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A5D+2) = GetPrivateProfileInt("calcharacter","config_74", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A61+1) = GetPrivateProfileInt("calcharacter","config_75", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A7A+2) = GetPrivateProfileInt("calcharacter","config_76", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004D6A7E+1) = GetPrivateProfileInt("calcharacter","config_77", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C887F+2) = GetPrivateProfileInt("calcharacter","config_78", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C888C+2) = GetPrivateProfileInt("calcharacter","config_79", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C8890+1) = GetPrivateProfileInt("calcharacter","config_80", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C88C2+2) = GetPrivateProfileInt("calcharacter","config_81", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C88FB+2) = GetPrivateProfileInt("calcharacter","config_82", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C8908+2) = GetPrivateProfileInt("calcharacter","config_83", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C890C+1) = GetPrivateProfileInt("calcharacter","config_84", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C893B+2) = GetPrivateProfileInt("calcharacter","config_85", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C8948+2) = GetPrivateProfileInt("calcharacter","config_86", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C894C+1) = GetPrivateProfileInt("calcharacter","config_87", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C897A+2) = GetPrivateProfileInt("calcharacter","config_88", 0, ".\\configurações\\customizações\\calcharacter.season");
	//----------------------------
	*(BYTE*)(0x004C8A2F+1) = GetPrivateProfileInt("calcharacter","config_89", 0, ".\\configurações\\customizações\\calcharacter.season");
	*(BYTE*)(0x004C8A6A+2) = GetPrivateProfileInt("calcharacter","config_90", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
	*(BYTE*)(0x004C8AA5+2) = GetPrivateProfileInt("calcharacter","config_91", 0, ".\\configurações\\customizações\\calcharacter.season") - 1;
    #endif
}

void CalCharacterEx(int aIndex)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	gObjCalCharacter(aIndex);

	PMSG_CHARINFOMAIN Result;

	Result.h.c			= 0xC1;
	Result.h.size		= sizeof(Result);
	Result.h.headcode	= 0xFE;
	Result.Code			= 0x07;
	Result.Class		= lpObj->Class;
	Result.Dexterity	= (WORD)(lpObj->Dexterity);
	Result.AttackSpeed	= (WORD)(lpObj->m_AttackSpeed);
	Result.MagicSpeed	= (WORD)(lpObj->m_MagicSpeed);

	DataSend(aIndex, (LPBYTE)(&Result), Result.h.size);
}

//void gObjCalCharacter_Hook(int aIndex)
//{
//	gObjCalCharacter(aIndex);
//	CalCharacterEx(aIndex);
//}

//BOOL _gObjSetCharacter(LPBYTE lpdata, int aIndex)
//{
//	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);
//
//	BOOL retornar = gObjSetCharacter(lpdata,lpObj->m_Index);
//
//	if(retornar == TRUE)
//	{
//		PMSG_CHARINFOMAIN Result;
//
//		Result.h.c = 0xC1;
//		Result.h.size = sizeof(Result);
//		Result.h.headcode = 0xFE;
//		Result.Code = 0x07;
//		Result.Class = lpObj->Class;
//		Result.Dexterity = (WORD)(lpObj->Dexterity);
//		Result.AttackSpeed = (WORD)(lpObj->m_AttackSpeed);
//		Result.MagicSpeed = (WORD)(lpObj->m_MagicSpeed);
//
//		DataSend(aIndex, (LPBYTE)(&Result), Result.h.size);
//	}
//
//	return retornar;
//}