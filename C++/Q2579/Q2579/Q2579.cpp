#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 300 + 1

using namespace std;

int N;
int stairs[MAX];
int DP[MAX];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
}

void mathod() {
	DP[1] = stairs[1];
	DP[2] = stairs[1] + stairs[2];
	DP[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

	for (int i = 4; i <= N; i++) {
		DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << DP[N] << endl;	
}

void solution() {
	input();
	mathod();
}

int main()
{
	solution();
}