#pragma once
void io_init() {
	//����� ��� �޸���
	std::string input_txt_name = "input\\Qtest1.txt";
	freopen(input_txt_name.c_str(), "r", stdin);            //�Է�
	//freopen("result.txt","w",stdout); //���
}

void input();
void output();