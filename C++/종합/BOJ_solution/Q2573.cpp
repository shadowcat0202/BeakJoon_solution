#include "pch.h"
#include "탐색.h"

#include <queue>


void Q2573::input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int Q2573::check() {
	std::memset(visited, false, sizeof(visited));
	int land_count = 0;




	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0 && visited[i][j] != true) {
				land_count++;
				if (land_count >= 2) return 2;
				std::queue<std::pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					int now_y = q.front().first;
					int now_x = q.front().second;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int next_y = now_y + dir[d].first;
						int next_x = now_x + dir[d].second;

						//범위 밖이면 다음 탐색
						if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)	continue;
						//방문한적 있거나 빙산이 아닌경우 다음 탐색
						if (visited[next_y][next_x] == true || map[next_y][next_x] == 0)	continue;

						q.push({ next_y, next_x });
						visited[next_y][next_x] = true;
					}
				}
			}
		}
	}
	return land_count;
}

void Q2573::melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				int water = 0;
				for (int d = 0; d < 4; d++) {
					int next_i = i + dir[d].first;
					int next_j = j + dir[d].second;

					if (next_i < 0 || next_j < 0 || next_i > N || next_j > M)	continue;
					if (map[next_i][next_j] == 0)	water++;
				}
				if (map[i][j] - water <= 0) {
					map_buf[i][j] = 0;
				}
				else {
					map_buf[i][j] = map[i][j] - water;
				}
			}
		}
	}
}

int Q2573::solution() {
	input();

	int year = 0;
	while (1) {
		year++;
		melt();
		std::memcpy(map, map_buf, sizeof(map));

		int ck = check();
		if (ck == 2) {
			return year;
		}
		else if (ck == 1) {
			continue;
		}
		else
			return 0;

	}
}


void Q2573::start() {
	printf("%d\n", solution());
}