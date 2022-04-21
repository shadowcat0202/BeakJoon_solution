#include <iostream>
#include <filesystem>
#include "myClass.h"
#define endl "\n"
#pragma warning(disable:4996)
void init() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("./input.txt", "r", stdin);
}
void stub() {
	int arr[2][3][2] = {1,2,
		3,4,
		5,6,

		7,8,
		9,10,
		11,12};
	int(*p)[3][2] = NULL;
	//int** pdot = arr;	불가능하다(열의 크기를 명시하지 않았기 때문에 이중포인터는 인식하지 못한다)
	p = arr;
	std::cout << *p << endl;
}
int main() {
	return 0;
}