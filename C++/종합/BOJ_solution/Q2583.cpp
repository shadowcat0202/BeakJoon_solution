#include "pch.h"
#include "Å½»ö.h"

#include <vector>
#include <queue>
#include <algorithm>

void Q2583::input() {
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		int p1x, p1y, p2x, p2y;
		scanf("%d %d %d %d", &p1x, &p1y, &p2x, &p2y);
		for (int y = p1y; y < p2y; y++) {
			for (int x = p1x; x < p2x; x++) {
				map[y][x] = true;
			}
		}
	}
}

//DFS(Àç±Í)
void Q2583::DFS(std::pair<int, int> node) {
	visited[node.first][node.second] = true;
	area_size++;
	for (int i = 0; i < 4; i++) {
		std::pair<int, int> next;
		next.first = node.first + dir_yx[i].first;
		next.second = node.second + dir_yx[i].second;

		//¸ÊÀÇ ¹üÀ§¹Û ¹«½Ã
		if (next.first < 0 || next.second < 0 || next.first >= M || next.second >= N) continue;

		if (map[next.first][next.second] == 0 && !visited[next.first][next.second]) {
			DFS(next);
		}
	}
}

void Q2583::BFS(std::pair<int, int> start) {
	std::queue<std::pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		std::pair<int, int> now = q.front();
		q.pop();
		area_size++;

		for (int i = 0; i < 4; i++) {
			std::pair<int, int> next;
			next.first = now.first + dir_yx[i].first;
			next.second = now.second + dir_yx[i].second;

			//¸ÊÀÇ ¹üÀ§ ¹Û ¹«½Ã
			if (next.first < 0 || next.second < 0 || next.first >= M || next.second >= N)	continue;

			if (map[next.first][next.second] == 0 && !visited[next.first][next.second]) {
				visited[next.first][next.second] = true;
				q.push(next);
			}

		}
	}

}

void Q2583::solution() {
	std::vector<int> res;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == false && !visited[i][j]) {
				area_size = 0;
				std::pair<int, int> start = { i,j };
				BFS(start);
				res.push_back(area_size);
			}
		}
	}

	std::sort(res.begin(), res.end());
	std::cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << " ";
	}
}

void Q2583::start() {
	input();
	solution();
}