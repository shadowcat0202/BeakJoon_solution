#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>	
#include <string>	//std:;string + std::string + ... (���ڿ� �̾� ����)
#include <cstdio>	//std::[printf() | scanf()]	(�׳� ������ ����� �ڷ����� ������ ����)
#include <io.h>		//_access(ã�����ϴ� ���� �̸�, [0 | 2 | 4 | 6])
//								[e | r | w | rw]

#include "Search(Ž��).h"


//�Է� ���� ���� ����
bool init_input(std::string number) {
	std::string input_txt = "Q" + number + ".txt";
	std::string input_path = "../input\\" + input_txt;
	if (_access(input_path.c_str(), 0) == 0) {
		freopen(input_path.c_str(), "r", stdin);	//�Է�
		//std::freopen("result.txt", "w", stdout);	//���
		//printf("init �Ϸ�\n");
		return true;
	}
	else {
		fclose(stdin);
		std::printf("%s �Է� ���� ����\n", input_txt.c_str());
		return false;
	}
}