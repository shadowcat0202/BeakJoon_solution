/*
https://www.acmicpc.net/problem/1572
*/

#pragma warning(disable:4996)
#include <iostream>
#include <vector>

int Q1572_N, Q1572_K;
std::vector<int> Q1572_v;

void Q1572_upt() {

}
void Q1572_find() {

}

long long Q1572_solution() {
	long long answer = 0;
	scanf("%d %d", &Q1572_N, &Q1572_K);

	std::vector<int> st((1 << 27) * 2), a(Q1572_N);

	for (int i = 0; i < Q1572_N; i++) {
		scanf("%d", &a[i]);

	}
	return answer;
}

void Q1572() {
	printf("%lld\n",Q1572_solution());
}