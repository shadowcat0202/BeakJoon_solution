/*
문제
백준이는 방 청소를 하면서 필요 없는 전공 서적을 사람들에게 나눠주려고 한다.
나눠줄 책을 모아보니 총 N권이었다. 책이 너무 많기 때문에 백준이는 책을 구분하기 위해 각각 1부터 N까지의 정수 번호를 중복되지 않게 매겨 두었다.

조사를 해 보니 책을 원하는 서강대학교 학부생이 총 M명이었다. 
백준이는 이 M명에게 신청서에 두 정수 a, b (1 ≤ a ≤ b ≤ N)를 적어 내라고 했다. 
그러면 백준이는 책 번호가 a 이상 b 이하인 책 중 남아있는 책 한 권을 골라 그 학생에게 준다. 
만약 a번부터 b번까지의 모든 책을 이미 다른 학생에게 주고 없다면 그 학생에게는 책을 주지 않는다.

백준이가 책을 줄 수 있는 최대 학생 수를 구하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다.

각 케이스의 첫 줄에 정수 N(1 ≤ N ≤ 1,000)과 M(1 ≤ M ≤ 1,000)이 주어진다.
다음 줄부터 M개의 줄에는 각각 정수 ai, bi가 주어진다. (1 ≤ ai ≤ bi ≤ N)

출력
각 테스트 케이스마다 백준이가 책을 줄 수 있는 최대 학생 수를 한 줄에 하나씩 출력한다.

예제 입력 1
1
2 3
1 2
1 2
1 2
예제 출력 1
2
*/


/*
이분매칭 알고리즘: A집단이 B집단을 선택하는 방법 알고리즘
효과적으로 매칭시켜준다는 말은 최대매칭(Max Matching)을 의미
모든 A(x)가 B(y)에 가장 많이 매칭되는경우
시간 복잡도가 가장 짧은것은 아니지만 DFS로 많이 해결한다
*/
#include <iostream>
#include <vector>
#define Q9576_MAX 1010
int Q9576_work[Q9576_MAX];
bool Q9576_book[Q9576_MAX];
std::vector<std::pair<int, int>> Q9576_v(Q9576_MAX);

bool Q9576_DFS(int x) {
	int size = Q9576_v[x].second - Q9576_v[x].first+ 1;
	for (int i = 0; i < size; i++) {
		int t = Q9576_v[x].first + i;
		if (Q9576_book[t]) {
			continue;
		}
		Q9576_book[t] = true;
		
		if (Q9576_work[t] == 0 || Q9576_DFS(Q9576_work[t])) {
			Q9576_work[t] = x;
			return true;
		}
	}
	return false;

}

int Q9576_solution() {
	int result = 0;
	int N, M;
	Q9576_v.clear();
	Q9576_v.push_back({ 0,0 });
	std::cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int start, end;
		std::cin >> start >> end;
		Q9576_v.push_back({ start, end });
	}
	std::fill(Q9576_work, Q9576_work + Q9576_MAX, 0);
	for (int i = 1; i <= M; i++) {
		std::fill(Q9576_book, Q9576_book + Q9576_MAX, false);
		if (Q9576_DFS(i))	result++;
	}


	return result;
}

void Q9576() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		std::cout << Q9576_solution() << "\n";
	}
}
