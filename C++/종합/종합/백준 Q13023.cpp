/*
문제
BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 
사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

A는 B와 친구다.
B는 C와 친구다.
C는 D와 친구다.
D는 E와 친구다.
위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

출력
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.
*/
/*
예제 입력 1
5 4
0 1
1 2
2 3
3 4
예제 출력 1
1
예제 입력 2
5 5
0 1
1 2
2 3
3 0
1 4
예제 출력 2
1
예제 입력 3
6 5
0 1
0 2
0 3
0 4
0 5
예제 출력 3
0
예제 입력 4
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7
예제 출력 4
1
*/

#include <iostream>
#include <vector>
int Q13023_N, Q13023_M;
std::vector<int> Q13023_v[2000];
bool Q13023_visited[2000];
bool Q13023_check;

void Q13023_input() {
	std::cin >> Q13023_N >> Q13023_M;

	for (int i = 0; i < Q13023_M; i++) {
		int a, b;
		std::cin >> a >> b;
		Q13023_v[a].push_back(b);
		Q13023_v[b].push_back(a);
	}
}
void Q13023_DFS(int idx, int cnt) {
	if (cnt == 4) {
		Q13023_check = true;
		return;
	}
	for (int i = 0; i < Q13023_v[idx].size(); i++) {
		int next = Q13023_v[idx][i];
		if (!Q13023_visited[next]) {
			Q13023_visited[next] = true;
			Q13023_DFS(next, cnt + 1);
			Q13023_visited[next] = false;
		}
	}
}
int Q13023_solution() {
	for (int i = 0; i < Q13023_N; i++) {
		for (int j = 0; j < Q13023_N; j++) {
			Q13023_visited[j] = false;
		}
		Q13023_visited[i] = true;
		Q13023_DFS(i, 0);
		if (Q13023_check)	break;
	}
	if (Q13023_check)	return 1;
	else return 0;
}
void Q13023() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	Q13023_input();
	std::cout << Q13023_solution() << "\n";

	
}