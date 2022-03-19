#pragma once
#include <iostream>

inline void error(char* str) {
	printf("%s", str);
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class Arraystack {
private:
	int data[MAX_STACK_SIZE];//요소 배열
	int top;	//요소 개수
public:
	Arraystack();	//기본 생성자 top = -1로 시작
	~Arraystack();
	void push(int x);	//데이터 쌓기
	int pop();	//가장 마지막에 넣은 데이터 빼기
	int peek();	//가장 위에있는 데이터 보여주기
	bool isFull();	//top == MAX_STACK_SIZE ? true:false
	bool isEmpty();	//top == -1 ? true:false
	int size();	//printf(top)
	void display();	//내용물 보여주기
};