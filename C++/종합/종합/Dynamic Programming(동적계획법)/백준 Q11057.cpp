/*
문제
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 
이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 
수는 0으로 시작할 수 있다.

입력
첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

예제 입력 1
1
예제 출력 1
10
예제 입력 2
2
예제 출력 2
55
예제 입력 3
3
예제 출력 3
220
*/
/*
아니 이거 풀이를 봐도 무슨 개소리인지 모르겠다 점화식 시발 애미 없네
*/

#include <iostream>
#define endl "\n"
#define DIV 10007

long long Q11057_dp[1000];

int Q11057_solution() {
	int N;
	std::cin >> N;

	Q11057_dp[0] = 10;
	Q11057_dp[1] = 55;
	for (int i = 2; i < N; i++) {
		Q11057_dp[i] = Q11057_dp[i - 1] * 5 - Q11057_dp[i - 1];
	}
	return Q11057_dp[N-1]%DIV;
}

void Q11057() {
	std::cout << Q11057_solution() << endl; 
}