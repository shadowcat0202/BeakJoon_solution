/*
문제
준규는 N×M 크기의 미로에 갇혀있다. 미로는 1×1크기의 방으로 나누어져 있고, 
각 방에는 사탕이 놓여져 있다. 미로의 가장 왼쪽 윗 방은 (1, 1)이고, 
가장 오른쪽 아랫 방은 (N, M)이다.

준규는 현재 (1, 1)에 있고, (N, M)으로 이동하려고 한다. 
준규가 (r, c)에 있으면, (r+1, c), (r, c+1), (r+1, c+1)로 이동할 수 있고, 
각 방을 방문할 때마다 방에 놓여져있는 사탕을 모두 가져갈 수 있다. 
또, 미로 밖으로 나갈 수는 없다.

준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수의 최댓값을 구하시오.

입력
첫째 줄에 미로의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 1,000)

둘째 줄부터 N개 줄에는 총 M개의 숫자가 주어지며, 
r번째 줄의 c번째 수는 (r, c)에 놓여져 있는 사탕의 개수이다. 
사탕의 개수는 0보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 준규가 (N, M)으로 이동할 때, 가져올 수 있는 사탕 개수를 출력한다.

예제 입력 1
3 4
1 2 3 4
0 0 0 5
9 8 7 6
예제 출력 1
31
예제 입력 2
3 3
1 0 0
0 1 0
0 0 1
예제 출력 2
3
예제 입력 3
4 3
1 2 3
6 5 4
7 8 9
12 11 10
예제 출력 3
47
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>	//이거도 문제 제출할때는 빼고
#define endl "\n"
#define Q11048_MAX 1000 + 1

int Q11048_candy[Q11048_MAX][Q11048_MAX] = {0};
int Q11048_dp[Q11048_MAX][Q11048_MAX] = {0};
int Q11048_N, Q11048_M;

void Q11048_input() {
	std::cin >> Q11048_N >> Q11048_M;
	for (int n = 1; n <= Q11048_N; n++) {
		for (int m = 1; m <= Q11048_M; m++) {
			std::cin >> Q11048_candy[n][m];
		}
	}
}

int Q11048_solution() {

	for (int y = 1; y <= Q11048_N; y++) {
		for (int x = 1; x <= Q11048_M; x++) {
			int bigger = 0;
			bigger = std::max(Q11048_dp[y - 1][x - 1], Q11048_dp[y-1][x]);
			bigger = std::max(bigger, Q11048_dp[y][x - 1]);
			Q11048_dp[y][x] = bigger + Q11048_candy[y][x];
		}
	}
	return Q11048_dp[Q11048_N][Q11048_M];
}

void Q11048() {
	//문제 제출때는 2줄 빼고
	std::memset(Q11048_candy, 0,sizeof(Q11048_candy));
	std::memset(Q11048_dp, 0, sizeof(Q11048_dp));

	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	Q11048_input();
	std::cout << Q11048_solution() << endl;
}