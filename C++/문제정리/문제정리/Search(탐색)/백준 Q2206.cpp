
//문제
//https://www.acmicpc.net/problem/2206
/*
N×M의 행렬로 표현되는 맵이 있다. 
맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 

당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 

최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 
다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/

//입 출력 예제
/*
예제 입력 1
6 4
0100
1110
1000
0000
0111
0000
예제 출력 1
15
예제 입력 2
4 4
0111
1111
1111
1110
예제 출력 2
-1
*/



#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <queue>

#define Q2206_MAX 1001

typedef struct {
	int y, x;
}Dir;
Dir Q2206_dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int Q2206_N, Q2206_M;
int Q2206_map[Q2206_MAX][Q2206_MAX];
bool Q2206_visited[Q2206_MAX][Q2206_MAX][2] = {false,};

void Q2206_input() {
	scanf("%d %d", &Q2206_N, &Q2206_M);

	for (int i = 0; i < Q2206_N; i++) {
		char buf[1000];
		scanf("%s", &buf);
		for (int j = 0; j < Q2206_M; j++) {
			Q2206_map[i][j] = buf[j] - '0';
		}
	}
}

int Q2206_BFS() {
	std::queue<std::pair<std::pair<int,int>, std::pair<int,int>>> q;
	q.push(std::make_pair(std::make_pair(0, 0), std::make_pair(0, 1)));
	Q2206_visited[0][0][0] = true;
	
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		//도착
		if (y == Q2206_N -1 && x == Q2206_M -1)	return cnt;

		for (int d = 0; d < 4; d++) {
			int ny = y + Q2206_dir[d].y;
			int nx = x + Q2206_dir[d].x;
			
			//범위 밖
			if (ny < 0 || nx < 0 || ny >= Q2206_N || nx >= Q2206_M)	continue;
			
			if (Q2206_map[ny][nx] == 1 && block == 0) {
				Q2206_visited[ny][nx][block + 1] = true;
				q.push(std::make_pair( std::make_pair(ny,nx), std::make_pair(block + 1, cnt + 1) ));
			}
			else if (Q2206_map[ny][nx] == 0 && Q2206_visited[ny][nx][block] == false) {
				Q2206_visited[ny][nx][block] = true;
				q.push(std::make_pair( std::make_pair(ny,nx), std::make_pair(block, cnt + 1) ));
			}
		}
	}
	return -1;
}

void Q2206() {
	Q2206_input();
	for (int i = 0; i < Q2206_N; i++) {
		for (int j = 0; j < Q2206_M; j++) {
			printf("%d\t", Q2206_map[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",Q2206_BFS());

	for (int i = 0; i < Q2206_N; i++) {
		for (int j = 0; j < Q2206_M; j++) {
			printf("%d\t", Q2206_visited[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < Q2206_N; i++) {
		for (int j = 0; j < Q2206_M; j++) {
			printf("%d\t", Q2206_visited[i][j][1]);
		}
		printf("\n");
	}
}
