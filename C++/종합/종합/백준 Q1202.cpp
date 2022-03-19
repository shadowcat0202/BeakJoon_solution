/*
����
�������� ���� ����̴� �������� �б�� ����ߴ�.

����̰� �� ���������� ������ �� N�� �ִ�. 
�� ������ ���� Mi�� ���� Vi�� ������ �ִ�. 
����̴� ������ K�� ������ �ְ�, �� ���濡 ���� �� �ִ� �ִ� ���Դ� Ci�̴�. 
���濡�� �ִ� �� ���� ������ ���� �� �ִ�.

����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N, K �� 300,000)

���� N�� �ٿ��� �� ������ ���� Mi�� Vi�� �־�����. (0 �� Mi, Vi �� 1,000,000)

���� K�� �ٿ��� ���濡 ���� �� �ִ� �ִ� ���� Ci�� �־�����. (1 �� Ci �� 100,000,000)

��� ���ڴ� ���� �����̴�.

���
ù° �ٿ� ����̰� ��ĥ �� �ִ� ���� ������ ���� �ִ��� ����Ѵ�.


���� �Է� 1
3 2
1 65
5 23
2 99
10
2
���� ��� 1
164

��Ʈ
ù ��° ������ �� ��° ���濡, �� ��° ������ ù ��° ���濡 ������ �ȴ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 300000

int bag[MAX];
std::pair<int, int> J[MAX];
std::priority_queue<int> pq;

long long Q1202_solution() {
	int N, K;
	long long result = 0;

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::cin >> J[i].first >> J[i].second;
	}
	for (int i = 0; i < K; i++) {
		std::cin >> bag[i];
	}

	std::sort(J, J + N);
	std::sort(bag, bag + K);

	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && J[idx].first <= bag[i]) {
			pq.push(J[idx++].second);
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	

	return result;

	
}
void Q1202() {
	
	std::cout << Q1202_solution();
}