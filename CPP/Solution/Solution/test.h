#pragma once
class test
{
private:
	int hp;

public:
	void sayhi();
	void setHp(int input) {
		hp = input;
	}
	void getHp() {
		if (hp >= 800) {
			printf("Too much\n");
			printf("%d\n", hp);
		}

	}
};

