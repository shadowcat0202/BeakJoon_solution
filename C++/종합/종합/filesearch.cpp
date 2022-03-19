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
	std::string filepath = ".\\문제번호정리\\" + txtname + ".txt";
	std::ifstream read_file;

	read_file.open(filepath);
	if (read_file.is_open()) {
		while (!read_file.eof()) {
			char tmp[line_size];
			read_file.getline(tmp, line_size);
			if (strcmp(tmp, Q_number.c_str)) {	//문제 번호 있는가 찾는중
				read_file.close();
				return true;
			}
		}
		printf("fileRead_Find_Q : 문제 번호 없음\n");
	}
	else {
		printf("fileRead_Find_Q : 문제번호정리\\%s.txt 가 없음\n", txtname.c_str);
		return false;
	}
}

int searching_dir(std::string& path) {

	std::string dirpath = path + "\\.*/txt";

	struct _finddata_t fd;  //디렉토리 내 파일 및 폴더 정보 저장
	intptr_t handle;
	std::list<_finddata_t> fdlist;  //디렉토리, 파일 정보 객체 리스트


	if ((handle = _findfirst(dirpath.c_str(), &fd)) == -1L) {   //구조체 초기화

		printf("해당 디렉터리가 없습니다!\n");
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