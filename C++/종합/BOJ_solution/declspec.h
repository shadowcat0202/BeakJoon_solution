#pragma once

//#ifdef CREATEDLL_EXPORTS�� CREATEDLL_EXPORTS��� ��ó���Ⱑ ���ǵǾ��ִ��� Ȯ���ϴ� ���ǹ�

/*
__declspec(dllexport)Ű���尡 ���� �Լ��� DLL�ܺη� ����
��, DLL�� ����Ͽ� �ش� Ű���尡 ���� �Լ��� ȣ���� �� �ִٴ� �ǹ�
�ݴ�� �ش� Ű���尡 ���� �Լ��� ���ǵǾ� �־ DLL�ܺο��� ȣ�� �Ұ�

__declspec(dllimport) Ű����� DLL�� ���ǵ� �Լ��� ȣ���ϱ� ���� ���˴ϴ�.
��, DLL���� __declspec(dllexport)�� ���ǵ� �Լ��� __declspec(dllimport)�� ȣ���Ѵٴ� ��
*/

#ifdef CREATEDLL_EXPORTS
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
