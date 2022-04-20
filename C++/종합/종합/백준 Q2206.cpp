
//����
//https://www.acmicpc.net/problem/2206
/*
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. 
�ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����. 

����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �̶� �ִ� ��η� �̵��Ϸ� �Ѵ�. 

�ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �̶� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.

���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.

�� ĭ���� �̵��� �� �ִ� ĭ�� �����¿�� ������ ĭ�̴�.

���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. 
���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.
*/

//�� ��� ����
/*
���� �Է� 1
6 4
0100
1110
1000
0000
0111
0000
���� ��� 1
15
���� �Է� 2
4 4
0111
1111
1111
1110
���� ��� 2
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

		//����
		if (y == Q2206_N -1 && x == Q2206_M -1)	return cnt;

		for (int d = 0; d < 4; d++) {
			int ny = y + Q2206_dir[d].y;
			int nx = x + Q2206_dir[d].x;
			
			//���� ��
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
