/*
https://www.acmicpc.net/problem/2573
문제

지구 온난화로 인하여 북극의 빙산이 녹고 있다. 
빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 
빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 
그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
	그림 1

그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 
단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 
바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.

그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 
2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 
따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.

0 0 0 0 0 0 0	0 0 0 0 0 0 0
0 0 2 4 1 0 0	0 0 0 3 0 0 0
0 1 0 1 5 0 0	0 0 0 0 4 0 0
0 5 4 1 2 0 0	0 3 2 0 0 0 0
0 0 0 0 0 0 0	0 0 0 0 0 0 0
	그림 2			그림 3

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 
그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

입력
첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. 
N과 M은 3 이상 300 이하이다. 
그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 
각 칸에 들어가는 값은 0 이상 10 이하이다. 
배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

출력
첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

예제 입력 1
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
예제 출력 1
2
*/
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <queue>
#define Q2573_MAX 300

int Q2573_N, Q2573_M;
int Q2573_map[Q2573_MAX][Q2573_MAX];
int Q2573_map_buf[Q2573_MAX][Q2573_MAX];

bool Q_2573_visited[Q2573_MAX][Q2573_MAX];

std::pair<int, int> Q2573_dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

void Q2573_input() {
	scanf("%d %d", &Q2573_N, &Q2573_M);
	for (int i = 0; i < Q2573_N; i++) {
		for (int j = 0; j < Q2573_M; j++) {
			scanf("%d", &Q2573_map[i][j]);
		}
	}
}

int Q2573_check() {
	std::memset(Q_2573_visited, false, sizeof(Q_2573_visited));
	int land_count = 0;
	for (int i = 0; i < Q2573_N; i++) {
		for (int j = 0; j < Q2573_M; j++) {
			if (Q2573_map[i][j] > 0 && Q_2573_visited[i][j] != true) {
				land_count++;
				if (land_count >= 2) return 2;
				std::queue<std::pair<int, int>> q;
				q.push({ i, j });
				Q_2573_visited[i][j] = true;

				while (!q.empty()) {
					int now_y = q.front().first;
					int now_x = q.front().second;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int next_y = now_y + Q2573_dir[d].first;
						int next_x = now_x + Q2573_dir[d].second;

						//범위 밖이면 다음 탐색
						if (next_y < 0 || next_x < 0 || next_y >= Q2573_N || next_x >= Q2573_M)	continue;
						//방문한적 있거나 빙산이 아닌경우 다음 탐색
						if (Q_2573_visited[next_y][next_x] == true || Q2573_map[next_y][next_x] == 0)	continue;

						q.push({ next_y, next_x });
						Q_2573_visited[next_y][next_x] = true;
					}
				}
			}
		}
	}
	return land_count;
}

void Q2573_melt() {
	for (int i = 0; i < Q2573_N; i++) {
		for (int j = 0; j < Q2573_M; j++) {
			if (Q2573_map[i][j]) {
				int water = 0;
				for (int d = 0; d < 4; d++) {
					int next_i = i + Q2573_dir[d].first;
					int next_j = j + Q2573_dir[d].second;

					if (Q2573_map[next_i][next_j] == 0)	water++;
				}
				if (Q2573_map[i][j] - water <= 0) {
					Q2573_map_buf[i][j] = 0;
				}
				else {
					Q2573_map_buf[i][j] = Q2573_map[i][j] - water;
				}
			}
		}
	}
}

int Q2573_solution() {
	Q2573_input();

	int year = 0;
	while (1){
		year++;
		Q2573_melt();
		std::memcpy(Q2573_map, Q2573_map_buf, sizeof(Q2573_map));
		
		int check = Q2573_check();
		if (check == 2) {
			return year;
		}
		else if (check == 1) {
			continue;
		}
		else 
			return 0;
		
	}
	

}

void Q2573() {
	printf("%d", Q2573_solution());
}