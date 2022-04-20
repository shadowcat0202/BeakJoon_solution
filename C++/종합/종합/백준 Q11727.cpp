/*
https://www.acmicpc.net/problem/11727
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "header/Dynamic Programming(동적계획법).h"

int Q11727::solution() {
	int result = 0;
	int N;
	int dp[1001] = {};
	scanf("%d", &N);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % DIV;
	}
	return dp[N-1];
}

Q11727::Q11727() {
	printf("%d\n", solution());
}