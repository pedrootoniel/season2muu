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

#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib, "wsock32.lib")
#include <gl\gl.h>
#include <gl\glu.h>

#include "points.h"
#include "functions.h"
#include "protocol.h"
#include "definitions.h"
#include "packets.h"
#include "objectstruct.h"
#include "gobjname.h"
#include "message.h"
#include "map.h"
#include "texture.h"
#include "tokenizer.h"
#include "item.h"
#include "camera.h"
#include "encrypt.h"
#include "hacker.h"
#include "fix.h"
#include "smoke.h"
#include "minimap.h"
#include "font.h"

#pragma warning(disable: 4996 4414)

static HINSTANCE hInstance;