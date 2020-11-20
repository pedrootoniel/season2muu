#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <process.h>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <winsock2.h>
#include <WinSock.h>
#include <rpc.h>
#include <rpcdce.h>

#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "..\\SQLAPI\\lib\\sqlapi.lib")

#include "..\SQLAPI\include\SQLAPI.h"
#include "protocol.h"
#include "definitions.h"
#include "functions.h"
#include "packets.h"
#include "database.h"
#include "tokenizer.h"
#include "configs.h"