#pragma once
void io_init() {
	//입출력 방식 메모장
	std::string input_txt_name = "input\\Qtest1.txt";
	freopen(input_txt_name.c_str(), "r", stdin);            //입력
	//freopen("result.txt","w",stdout); //출력
}

void input();
void output();