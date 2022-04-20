/*
문제
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.

김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 
최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.

참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다.
(즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)

수강신청 대충한 게 찔리면, 선생님을 도와드리자!

입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)

이후 N개의 줄에 Si, Ti가 주어진다. (1 ≤ Si < Ti ≤ 109)

출력
강의실의 개수를 출력하라.

예제 입력 1
3
1 3
2 4
3 5
예제 출력 1
2
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int Q11000_solution() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> in_pq;	//오름차순
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq_r;	//오름차순
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::pair<int, int> buf;
		std::cin >> buf.first >> buf.second;
		in_pq.push(buf);
	}
	//처음 한개 pq_r에 대입
	pq_r.push(in_pq.top().second);
	in_pq.pop();

	while (!in_pq.empty()) {
		std::pair<int, int> now = in_pq.top();
		in_pq.pop();

		if (pq_r.top() <= now.first) {
			pq_r.pop();
			pq_r.push(now.second);
		}
		else {
			pq_r.push(now.second);
		}
	}
	
	return pq_r.size();
}

void Q11000() {
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << Q11000_solution();
}