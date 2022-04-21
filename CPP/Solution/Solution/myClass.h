#pragma once
#include <iostream>
class myClass
{
private:
	int hp;
	std::string name;
public:
	myClass(std::string nn) {
		setName(nn);
	}
	void setName(std::string x);
	std::string getName();

	void setHp(int n);
	int getHp();

	void sayhi();

};

