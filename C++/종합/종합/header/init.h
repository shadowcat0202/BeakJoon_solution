#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>	
#include <string>	//std:;string + std::string + ... (문자열 이어 적기)
#include <cstdio>	//std::[printf() | scanf()]	(그냥 적으면 입출력 자료형에 문제가 생김)
#include <io.h>		//_access(찾고자하는 파일 이름, [0 | 2 | 4 | 6])
//								[e | r | w | rw]

#include "Search(탐색).h"


//입력 예제 파일 오픈
bool init_input(std::string number) {
	std::string input_txt = "Q" + number + ".txt";
	std::string input_path = "../input\\" + input_txt;
	if (_access(input_path.c_str(), 0) == 0) {
		freopen(input_path.c_str(), "r", stdin);	//입력
		//std::freopen("result.txt", "w", stdout);	//출력
		//printf("init 완료\n");
		return true;
	}
	else {
		fclose(stdin);
		std::printf("%s 입력 예제 없음\n", input_txt.c_str());
		return false;
	}
}