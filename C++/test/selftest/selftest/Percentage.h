#pragma once
//�Ʒ��� ���� ��ó���⸦ ����ص� ���������� #pragma once�� ȿ�����̴�
/*
#ifndef Percentage_h
#define Percentage_h
*/

class Percentage
{
private:
	float value[3] = {0,0,0}; //total, part, percent
	int zero_count;

public:
	~Percentage(){}
	Percentage();

	float get_total();
	float get_part();
	float get_percent();
	int get_zero_count();

	void Percentage_input();
	float Percent_in_Total_Part();
	float Total_in_Percent_Part();
	float Part_in_Percent_Total();
	
};