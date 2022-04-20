#pragma once
#include <iostream>

inline void error(char* str) {
	printf("%s", str);
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class Arraystack {
private:
	int data[MAX_STACK_SIZE];//��� �迭
	int top;	//��� ����
public:
	Arraystack();	//�⺻ ������ top = -1�� ����
	~Arraystack();
	void push(int x);	//������ �ױ�
	int pop();	//���� �������� ���� ������ ����
	int peek();	//���� �����ִ� ������ �����ֱ�
	bool isFull();	//top == MAX_STACK_SIZE ? true:false
	bool isEmpty();	//top == -1 ? true:false
	int size();	//printf(top)
	void display();	//���빰 �����ֱ�
};