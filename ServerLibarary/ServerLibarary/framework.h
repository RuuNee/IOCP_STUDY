#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "MSWSock.lib")
#pragma comment(lib, "Winm.lib")

#include <WS2tcpip.h>
#include <winsock.h>
#include <MSWSock.h>
#include <mmsystem.h>
#include <WS2spi.h>
#include <mstcpip.h>

#include <Windows.h>
#include <iostream>
#include <io.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdint>

#include <assert.h>
#include <fcntl.h>
#include <algorithm>
#include <functional>

#include <thread>
#include <mutex>
#include <memory>

#include <string>
#include <tchar.h>

#include <ctime>
#include <random>
#include <typeinfo>

//TODO : 공용 매크로
#if _DEBUG
#define CONTEXT_SWITCH Sleep(1)
#else
#define CONTEXT_SWITCH ::SwitchToThread()
#endif

typedef void(*Function)(void*);

//기타 유틸

//TODO : 필수 헤더 파일
//-----------------------------------------------------------//
#include "./Util/Type.h"
#include "./Util/Util.h"