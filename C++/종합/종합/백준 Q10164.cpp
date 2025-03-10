/*
문제
행의 수가 N이고 열의 수가 M인 격자의 각 칸에 1부터 N×M까지의 번호가 첫 행부터 시작하여 차례로 부여되어 있다. 
격자의 어떤 칸은 ○ 표시가 되어 있다. (단, 1번 칸과 N × M번 칸은 ○ 표시가 되어 있지 않다. 또한, ○ 표시가 되어 있는 칸은 최대 한 개이다. 즉, ○ 표시가 된 칸이 없을 수도 있다.)

행의 수가 3이고 열의 수가 5인 격자에서 각 칸에 번호가 1부터 차례대로 부여된 예가 아래에 있다. 이 격자에서는 8번 칸에 ○ 표시가 되어 있다.

1	2	3	4	5
6	7	[8]	9	10
11	12	13	14	15

격자의 1번 칸에서 출발한 어떤 로봇이 아래의 두 조건을 만족하면서 N×M번 칸으로 가고자 한다.

조건 1: 로봇은 한 번에 오른쪽에 인접한 칸 또는 아래에 인접한 칸으로만 이동할 수 있다. (즉, 대각선 방향으로는 이동할 수 없다.)
조건 2: 격자에 ○로 표시된 칸이 있는 경우엔 로봇은 그 칸을 반드시 지나가야 한다.
위에서 보인 것과 같은 격자가 주어질 때, 로봇이 이동할 수 있는 서로 다른 경로의 두 가지 예가 아래에 있다.

1 → 2 → 3 → 8 → 9 → 10 → 15
1 → 2 → 3 → 8 → 13 → 14 → 15
격자에 관한 정보가 주어질 때 로봇이 앞에서 설명한 두 조건을 만족하면서 이동할 수 있는 서로 다른 경로가 총 몇 개나 되는지 찾는 프로그램을 작성하라.

입력
입력의 첫째 줄에는 격자의 행의 수와 열의 수를 나타내는 두 정수 N과 M(1 ≤ N, M ≤ 15), 그리고 ○로 표시된 칸의 번호를 나타내는 정수 K(K=0 또는 1 < K < N×M)가 차례로 주어지며, 각 값은 공백으로 구분된다. 
K의 값이 0인 경우도 있는데, 이는 ○로 표시된 칸이 없음을 의미한다. N과 M이 동시에 1인 경우는 없다.

출력
주어진 격자의 정보를 이용하여 설명한 조건을 만족하는 서로 다른 경로의 수를 계산하여 출력해야 한다.

예제 입력 1
3 5 8
예제 출력 1
9
예제 입력 2
7 11 0
예제 출력 2
8008
예제 입력 3
7 11 76
예제 출력 3
5005
*/

/*
내풀이
점화식
dp[y][x] = dp[y-1][x] + dp[y][x-1]

중간 지점이있는경우 구역을 2개로 나눈다(시작->중간->끝)각각의 끝지점의 곱으로 출력

결론(안됨)
이론상으로도 다 정상인데 왜 런타임 에러인지 모르겠다
*/

#include <iostream>

int Q10164_N, Q10164_M, Q10164_K;

void Q10164_input() {
	std::cin >> Q10164_N >> Q10164_M >> Q10164_K;
}

//n by m 배열의 경우의 수 구하기
long long Q10164_Rectangle_case(int fy, int fx) {
	if (fy == 1 || fx == 1) {
		return 1;
	}
	else {
		//2차원 배열 동적 할당
		int** buf_arr = new int* [fy];
		for (int i = 0; i < fy; i++) {
			buf_arr[i] = new int[fx];
		}

		//0행과 0열의 칸의 경우의 수는 모두 1
		for (int i = 0; i < fy; i++) {
			buf_arr[i][0] = 1;
		}
		for (int i = 0; i < fx; i++) {
			buf_arr[0][i] = 1;
		}

		//dp 갱신
		for (int y = 1; y < fy; y++) {
			for (int x = 1; x < fx; x++) {
				buf_arr[y][x] = buf_arr[y - 1][x] + buf_arr[y][x - 1];
			}
		}
		return buf_arr[fy - 1][fx - 1];
	}


}

long long Q10164_solution() {
	if (Q10164_K) {	//중간 지점을 지나가야 하는 경우
		int pass_y, pass_x;
		if (Q10164_K % Q10164_M == 0) {
			pass_y = Q10164_K / Q10164_M;
			pass_x = Q10164_M;
		}
		else if (Q10164_K % Q10164_N == 0) {
			pass_y = Q10164_K;
			pass_x = Q10164_K / Q10164_N;
		}
		else {
			pass_y = Q10164_K / Q10164_M + 1;
			pass_x = Q10164_K % Q10164_M;
		}

		return Q10164_Rectangle_case(pass_y, pass_x) * Q10164_Rectangle_case(Q10164_N - pass_y + 1, Q10164_M - pass_x + 1);
	}
	else {	//중간 지점이 없는 경우
		return Q10164_Rectangle_case(Q10164_N, Q10164_M);
	}


}

void Q10164() {
	Q10164_input();
	std::cout << Q10164_solution() << "\n";
}