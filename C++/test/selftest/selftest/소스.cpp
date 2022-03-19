#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include<iostream>
#include<vector>
#include <algorithm>
//#include "Percentage.h"
#include "hypnoApp_translate.h"
#include <OleAuto.h>	//BSTR = Basic STRing


int main(int argc, char** argv)
{	

	std::ifstream readfile;
	std::string path = "D:\\\\GAME\\Other\\\game_h\\\\Collection\\\\hypnoApp_ver1.0.2\\\\Korean(mytest)\\\\Subtitles.csv";
	readfile.open(path);

	if (!readfile.is_open()) {
		std::cout << "읽을 파일 없음\n";
		return 0;
	}

	run(readfile);
	readfile.close();

	return 0;

}