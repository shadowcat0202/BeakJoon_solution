#include "hypnoApp_translate.h"
#include <oleauto.h>

bool openfile(std::ifstream& readfile, std::string path) {
	readfile.open(path);
	if (readfile.is_open()) {
		return true;
	}
	return false;
}

bool run(std::ifstream& readfile) {
	std::string path = "D:\\\\GAME\\\\Other\\\\game_h\\\\Collection\\\\hypnoApp_ver1.0.2\\\\Korean(mytest)\\\\test.txt";
	std::string line;


	std::ofstream writefile;
	writefile.open(path);
	
	
	if (writefile.is_open()) {
		std::cout << "write file open\n";
		int count = 0;
		while (!readfile.eof()) {
			std::string key, value;
			std::getline(readfile, key, ',');
			std::getline(readfile, value, '\n');

			std::cout << ++count  << ".." << key << "=" << value << "\n";

			//if (key.compare("")) {	//key 값 없는 경우 = 뒤에 번역할 내용이 없는경우
			//	if (value.compare("0")) {	//",0" 적기
			//	}
			//	else {	//","  적기
			//	}
			//}
			//else {	//key 값 존재 = 뒤에 번역할 내용 있음

			//}
			//
			//std::cout << ++count << "\n";
		}
	}
	else {
		return false;
	}

	writefile.close();
	return true;
	
}

char* UTF8ToANSI(const char* pszCode){
	BSTR    bstrWide;
	char* pszAnsi;
	int     nLength;
	
	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	MultiByteToWideChar(CP_UTF8, 0, pszCode, lstrlen(pszCode) + 1, bstrWide, nLength);

	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);
	
	return pszAnsi;
}
char* ANSIToUTF8(const char* pszCode) {
	int     nLength, nLength2;
	BSTR    bstrCode;
	char* pszUTFCode = NULL;

	nLength = MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), NULL, NULL);
	bstrCode = SysAllocStringLen(NULL, nLength);
	MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), bstrCode, nLength);

	nLength2 = WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, 0, NULL, NULL);
	pszUTFCode = (char*)malloc(nLength2 + 1);
	WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, nLength2, NULL, NULL);

	return pszUTFCode;
}