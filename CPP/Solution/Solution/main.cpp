#include <iostream>
#include <filesystem>
#include "test.h"
#pragma warning(disable:4996)
void init() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("./input.txt", "r", stdin);
}
void stub() {
	test t;
	t.setHp(1200);
	t.getHp();

		
}
int main() {
	stub();
	
	return 0;
}