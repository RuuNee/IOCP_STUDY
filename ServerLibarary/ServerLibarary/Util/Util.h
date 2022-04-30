#pragma once
#include <algorithm>

//string 초기화
#define UNDEFINE_NAME L"Undefine_Name"

//snprintf 재정의, 안전을 위해 array 사용을 기본으로 한다.
#define snprintf(dst, format, ...) _snprintf_s(dst.data(),dst.size(), _TRUNCATE, format,_VA_ARGS__)
#define snwprintf(dst, format, ...) _snprintf_s(dst.data(),dst.size(), _TRUNCATE, format,_VA_ARGS__)

//범위 보정 및 체크
#define fixInRange(minium,x,maximum) min(maximun,max(x,minimum))

#define isInRange(minimum, x, maximum) (x == fixInRange(minimum, x, maximum)) ? true : false

//overflow 체크
inline bool isOverFlower_uint(unsigned int original, unsigned int add)
{
	unsigned int before = original;
	unsigned int after = original + add;
	if ((original & 0x80000000) != (after & 0x80000000))
	{
		return false;
	}
	return true;
}

//컴파일 기본 매크로 회피용 __FUNCTION__ 같은...
#define __W(x) L##x
#define _W(x) __W(x)

//----------------------------------------------------------//
//문자열 반환
inline void StrConvA2T(CHAR* src, TCHAR* dest, size_t destLen)
{                                  //r_winnt
#ifdef UNICODE
	if (destLen < 1)
	{
		return;
	}
	MultiByteToWideChar(CP_ACP, 0, src, -1, dest, (int)destLen - 1);
#endif // UNICODE
}

inline void StrConvA2T(TCHAR* src, CHAR* dest, size_t destLen)
{                                  //r_winnt
#ifdef UNICODE
	if (destLen < 1)
	{
		return;
	}
	WideCharToMultiByte(CP_ACP, 0, src, -1, dest, (int)destLen, NULL, FALSE);
#endif // UNICODE
}

inline void StrConvA2W(CHAR* src, WCHAR* dest, size_t destlen)
{
	if (destlen < 1)
	{
		return;
	}
	MultiByteToWideChar(CP_ACP, 0, src, -1, dest, (int)destlen - 1);
}

inline void StrConvW2A(WCHAR* src, CHAR* dest, size_t destlen)
{
	if (destlen < 1)
	{
		return;
	}
	WideCharToMultiByte(CP_ACP, 0, src, -1, dest, (int)destlen - 1, NULL,FALSE);
}

//----------------------------------------------------------//
//delete object
#undef SAFE_DELETE
#define SAFE_DELETE(obj)     \
{                            \
	if ((obj))delete(obj);   \
	(obj) = 0L;              \
}     

//delete object array
#undef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(arr)     \
{                                  \
	if ((arr)) delete[](arr);      \
	(arr) = 0L;                    \
}

//delete gameObject
#define SAFE_FREE(obj)        \
{                             \
	if ((obj)) obj->free();   \
	(obj) = 0L;               \
}

#define SAFE_RELEASE(obj)        \
{                                \
	if (obj) { obj.release(); }  \
}