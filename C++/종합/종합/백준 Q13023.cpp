/*
����
BOJ �˰��� ķ������ �� N���� �����ϰ� �ִ�. 
������� 0������ N-1������ ��ȣ�� �Ű��� �ְ�, �Ϻ� ������� ģ���̴�.

������ ������ ���� ģ�� ���踦 ���� ��� A, B, C, D, E�� �����ϴ��� ���غ����� �Ѵ�.

A�� B�� ģ����.
B�� C�� ģ����.
C�� D�� ģ����.
D�� E�� ģ����.
���� ���� ģ�� ���谡 �����ϴ��� ���ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)�� �־�����.

��° �ٺ��� M���� �ٿ��� ���� a�� b�� �־�����, a�� b�� ģ����� ���̴�. (0 �� a, b �� N-1, a �� b) ���� ģ�� ���谡 �� �� �̻� �־����� ���� ����.

���
������ ���ǿ� �´� A, B, C, D, E�� �����ϸ� 1�� ������ 0�� ����Ѵ�.
*/
/*
���� �Է� 1
5 4
0 1
1 2
2 3
3 4
���� ��� 1
1
���� �Է� 2
5 5
0 1
1 2
2 3
3 0
1 4
���� ��� 2
1
���� �Է� 3
6 5
0 1
0 2
0 3
0 4
0 5
���� ��� 3
0
���� �Է� 4
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7
���� ��� 4
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