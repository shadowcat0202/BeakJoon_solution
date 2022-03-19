#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
void test_init() {
	//입출력 방식 메모장
	std::string input_txt_name = "\\selftest1\\input\\Qtest1.txt";
	freopen(input_txt_name.c_str(), "r", stdin);            //입력
	//freopen("result.txt","w",stdout); //출력
}