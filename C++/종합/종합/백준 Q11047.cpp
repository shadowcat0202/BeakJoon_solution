#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define endl "\n"

using namespace std;

int Q11047_N, Q11047_K;
int Q11047_money[10];
int Q11047_res;

void input() {
	cin >> Q11047_N >> Q11047_K;
	for (int i = 0; i < Q11047_N; i++) {
		cin >> Q11047_money[i];
	}
}

void DP() {
	while (Q11047_K > 0) {
		if (Q11047_K >= Q11047_money[Q11047_N - 1]) {

			Q11047_res += Q11047_K / Q11047_money[Q11047_N - 1];
			Q11047_K %= Q11047_money[Q11047_N - 1];
		}
		else {
			Q11047_N--;
		}
	}
}

void Q11047()
{
	input();
	DP();
	cout << Q11047_res << endl;
}