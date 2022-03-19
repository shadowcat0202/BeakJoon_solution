#pragma once
#include <iostream>

#define MAX_LIST_SIZE 100

//오류 처리 함수
inline void error(char* str) {
	printf("%s", str);
	exit(1);
}

class ArrayList {
	private:
		int data[MAX_LIST_SIZE];
		int length;

public:
	ArrayList();
	~ArrayList();
	void insert(int pos, int e);
	void remove(int pos);
	int getEntry(int pos);
	bool isFull();
	bool find(int item);
	bool replace(int pos, int e);
	int size();
	void display();
	void clear();
};