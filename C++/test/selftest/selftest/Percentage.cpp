#include<iostream>
#include"Percentage.h"

Percentage::Percentage() {
	zero_count = 0;
	std::cout << "퍼센트 클래스 생성" << std::endl;
}

float Percentage::get_total() {
	return value[0];
}
float Percentage::get_part() {
	return value[1];
}
float Percentage::get_percent() {
	return value[2];
}

int Percentage::get_zero_count() {
	return zero_count;
}

void Percentage::Percentage_input() {
	std::cout << "\n조건: 모르는 경우 0을 입력하세요, 종료를 원하시면 모든 값에 0을 넣으세요\n";
	std::cout << "전체를 입력하세요:";
	std::cin >> value[0];
	std::cout << "부분을 입력하세요:";
	std::cin >> value[1];
	std::cout << "퍼센트를 입력하세요:";
	std::cin >> value[2];
	
	zero_count = 0;
	for (int i = 0; i < 3; i++) {
		if (value[i] == 0)	zero_count++;
	}
}

float Percentage::Percent_in_Total_Part() {
	return (value[1] / value[0]) * 100;
}

float Percentage::Total_in_Percent_Part() {
	return value[1] / value[2] * 100;
}

float Percentage::Part_in_Percent_Total() {
	return value[2] * value[0] / 100;
}

