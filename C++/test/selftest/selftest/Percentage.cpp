#include<iostream>
#include"Percentage.h"

Percentage::Percentage() {
	zero_count = 0;
	std::cout << "�ۼ�Ʈ Ŭ���� ����" << std::endl;
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
	std::cout << "\n����: �𸣴� ��� 0�� �Է��ϼ���, ���Ḧ ���Ͻø� ��� ���� 0�� ��������\n";
	std::cout << "��ü�� �Է��ϼ���:";
	std::cin >> value[0];
	std::cout << "�κ��� �Է��ϼ���:";
	std::cin >> value[1];
	std::cout << "�ۼ�Ʈ�� �Է��ϼ���:";
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

