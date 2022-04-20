// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule, //DLL 모듈 핸들
                       DWORD  ul_reason_for_call,   //이 함수의 호출 이유
                       LPVOID lpReserved    //예약값 NULL을 넣어줌
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //DLL 초기화 코드가 있다면 이부분에 삽입
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}