#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
void test_init() {
	//����� ��� �޸���
	std::string input_txt_name = "\\selftest1\\input\\Qtest1.txt";
	freopen(input_txt_name.c_str(), "r", stdin);            //�Է�
	//freopen("result.txt","w",stdout); //���
}