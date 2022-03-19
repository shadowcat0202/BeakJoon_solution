#include <iostream>
#define endl "\n"

using namespace std;

int N;
int Gear[5][8];

void rotate_gear(int n, int d) {
	if (d == 1) {            // 시계방향
		int tmp = Gear[n][7];
		for (int i = 6; i >= 0; i--) {
			Gear[n][i + 1] = Gear[n][i];
		}
		Gear[n][0] = tmp;
	}
	else if (d == -1) {        // 반 시계 방향
		int tmp = Gear[n][0];
		for (int i = 1; i < 8; i++) {
			Gear[n][i - 1] = Gear[n][i];
		}
		Gear[n][7] = tmp;
	}
}

void right(int n, int d) {
	if (!(1 <= n && n <= 4))	return;
	if (Gear[n - 1][2] != Gear[n][6]) {
		d = (d == 1) ? -1 : 1;
		right(n + 1, d);
		rotate_gear(n, d);
	}
}

void left(int n, int d) {
	if (!(1 <= n && n <= 4))	return;
	if (Gear[n][2] != Gear[n + 1][6]) {
		d = (d == 1) ? -1 : 1;
		left(n - 1, d);
		rotate_gear(n, d);
	}
}

void input() {
	//입력
	/*
	1
	2
	3
	4번 톱니바퀴
	회전 횟수
	(번호 방향) * N번
	*/
	for (int i = 1; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			Gear[i][j] = s[j] - 48;
		}

	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int bun, dir;
		cin >> bun >> dir;
		left(bun - 1, dir);
		right(bun + 1, dir);

		rotate_gear(bun, dir);

	}

	int res = Gear[1][0] + (2 * Gear[2][0]) + (4 * Gear[3][0]) + (8 * Gear[4][0]);
	cout << res << endl;
}


int main()
{
	input();
}