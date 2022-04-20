/*
문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 
각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 
가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.


예제 입력 1
3 2
1 65
5 23
2 99
10
2
예제 출력 1
164

힌트
첫 번째 보석을 두 번째 가방에, 세 번째 보석을 첫 번째 가방에 넣으면 된다.
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