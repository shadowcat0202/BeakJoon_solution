#pragma once

//#ifdef CREATEDLL_EXPORTS는 CREATEDLL_EXPORTS라는 전처리기가 정의되어있는지 확인하는 조건문

/*
__declspec(dllexport)키워드가 붙은 함수는 DLL외부로 노출
즉, DLL을 사용하여 해당 키워드가 붙은 함수를 호출할 수 있다는 의미
반대로 해당 키워드가 없는 함수는 정의되어 있어도 DLL외부에서 호출 불가

__declspec(dllimport) 키워드는 DLL에 정의된 함수를 호출하기 위해 사용됩니다.
즉, DLL에서 __declspec(dllexport)로 정의된 함수를 __declspec(dllimport)로 호출한다는 것
*/

#ifdef CREATEDLL_EXPORTS
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
