#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <list>
#include <fstream>

#include "header/init.h"

#define line_size 256

bool fileRead_Find_Q(std::string txtname, std::string Q_number) {
	std::vector<std::string> Q_list;
	std::string filepath = ".\\������ȣ����\\" + txtname + ".txt";
	std::ifstream read_file;

	read_file.open(filepath);
	if (read_file.is_open()) {
		while (!read_file.eof()) {
			char tmp[line_size];
			read_file.getline(tmp, line_size);
			if (strcmp(tmp, Q_number.c_str)) {	//���� ��ȣ �ִ°� ã����
				read_file.close();
				return true;
			}
		}
		printf("fileRead_Find_Q : ���� ��ȣ ����\n");
	}
	else {
		printf("fileRead_Find_Q : ������ȣ����\\%s.txt �� ����\n", txtname.c_str);
		return false;
	}
}

int searching_dir(std::string& path) {

	std::string dirpath = path + "\\.*/txt";

	struct _finddata_t fd;  //���丮 �� ���� �� ���� ���� ����
	intptr_t handle;
	std::list<_finddata_t> fdlist;  //���丮, ���� ���� ��ü ����Ʈ


	if ((handle = _findfirst(dirpath.c_str(), &fd)) == -1L) {   //����ü �ʱ�ȭ

		printf("�ش� ���͸��� �����ϴ�!\n");
		return 0;
	}
	do {
		std::string file = fd.name;

		/*size_t cut = file.find('.');

		std::string f_name = file.substr(0, cut);
		printf("%s\n", f_name.c_str());*/


	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
}