/*
문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

예제 입력 1
10
1 100 2 50 60 3 5 6 7 8
예제 출력 1
113
*/

#include <iostream>
#include <algorithm>
#define endl "\n"
#define Q11055_MAX 1001

int Q11055_arr[Q11055_MAX];
int Q11055_dp[Q11055_MAX];

int Q11055_solution() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> Q11055_arr[i];
		Q11055_dp[i] = Q11055_arr[i];
	}

	int result = 0;
	int big = Q11055_arr[0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (Q11055_arr[i] > Q11055_arr[j]) {
				Q11055_dp[i] = std::max(Q11055_dp[j] + Q11055_arr[i], Q11055_dp[i]);
			}
		}
		result = (Q11055_dp[i] > result) ? Q11055_dp[i] : result;

	}

	return result;

}

void Q11055() {
	std::cout << Q11055_solution() << endl;
}