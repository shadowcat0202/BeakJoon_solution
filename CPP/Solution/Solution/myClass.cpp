#include <iostream>
#include "myClass.h"
void myClass::sayhi() {
	printf("hello");
}
void myClass::setName(std::string x) {
	name = x;
}
std::string myClass::getName() {
	return name;
}

void myClass::setHp(int n) {
	hp = n;
}
int myClass::getHp() {
	return hp;
}