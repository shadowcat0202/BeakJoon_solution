#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
#define endl "\n"
#define MAX 1000

using namespace std;
int Q11399_N;
vector<int> Q11399_P;

void Q11399_input() {
	cin >> Q11399_N;
	for (int i = 0; i < Q11399_N; i++) {
		int buf;
		cin >> buf;
		Q11399_P.push_back(buf);
	}
}

void Q11399() {
	int res = 0;
	int memo[1000];

	Q11399_input();
	sort(Q11399_P.begin(), Q11399_P.end());

	memo[0] = Q11399_P[0];
	for (int i = 1; i < Q11399_N; i++) {
		memo[i] = memo[i - 1] + Q11399_P[i];
	}
	for (int i = 0; i < Q11399_N; i++) {
		res += memo[i];
	}
	cout << res;
}
