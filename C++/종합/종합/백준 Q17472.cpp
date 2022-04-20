/*
문제
https://www.acmicpc.net/problem/17472
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define Q17272_MAX 10

std::pair<int, int> Q17472_NM;
std::pair<int, int> Q17472_dir_yx[4] = { {1,0} ,{0,1}, {-1,0}, {0,-1} };
int Q17272_map[Q17272_MAX][Q17272_MAX];
int Q17272_bridge[7][7];	//다리 길이가 아무리 길어봤자 10을 못넘긴다(INF대신 적당히 20을 넣는다)
int land_number = 1;
int Q17272_ret = 0;

struct AdjointSet {
	std::vector<int>root;
	std::vector<int> rank;

	void init_AdjointSet(int g_size) {
		root.resize(g_size);
		rank.resize(g_size);

		for (int i = 1; i < g_size; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x) {
		if (root[x] == x)	
			return x;
		else	
			return root[x] = find(root[x]);
	}

	void union_set(int y, int x) {
		x = find(x);
		y = find(y);

		if (rank[x] < rank[y])
			root[x] = y;
		else {
			root[y] = x;

			if (rank[x] == rank[y]) {
				rank[x]++;
			}
		}
	}
}AJS;

//입력
void Q17472_input() {
	std::cin >> Q17472_NM.first >> Q17472_NM.second;
	for (int y = 0; y < Q17472_NM.first; y++) {
		for (int x = 0; x < Q17472_NM.second; x++) {
			std::cin >> Q17272_map[y][x];
		}
	}
}
//땅 번호 맵핑
void Q17272_gruoping() {
	bool visited[Q17272_MAX][Q17272_MAX] = {false,};	
	//땅 탐색
	for (int i = 0; i < Q17472_NM.first; i++) {
		for (int j = 0; j < Q17472_NM.second; j++) {
			//미지의 땅(방문한적 없는경우)
			if (Q17272_map[i][j] != 0 && !visited[i][j]) {
				//탐색 준비(BFS)
				std::queue<std::pair<int, int>> BFS;
				BFS.push(std::make_pair(i, j));
				visited[i][j] = true;

				//탐색
				while (!BFS.empty()) {
					std::pair<int, int> now = BFS.front();
					BFS.pop();
					Q17272_map[now.first][now.second] = land_number;

					for (int d = 0; d < 4; d++) {
						std::pair<int, int> next;
						next.first = now.first + Q17472_dir_yx[d].first;
						next.second = now.second + Q17472_dir_yx[d].second;

						if (next.first < 0 || next.second < 0 || next.first >= Q17472_NM.first || next.second >= Q17472_NM.second || Q17272_map[next.first][next.second] == 0 ||visited[next.first][next.second])	continue;
						
						visited[next.first][next.second] = true;
						BFS.push(next);						
					}
				}
				//땅의 번호
				land_number++;
			}
		}
	}
}

void Q17272_make_bridge() {
	for (int i = 0; i < Q17472_NM.first; i++) {
		for (int j = 0; j < Q17472_NM.second; j++) {
			//그룹화된 섬 발견
			if (Q17272_map[i][j] > 0) {
				//동서남북(직선) 탐색
				for (int d = 0; d < 4; d++) {					
					int dis = 0;

					std::pair<int, int> next = std::make_pair(i, j);
					next.first += Q17472_dir_yx[d].first;
					next.second += Q17472_dir_yx[d].second;

					while (next.first >= 0 && next.second >= 0 && next.first < Q17472_NM.first && next.second < Q17472_NM.second) {
						//같은 섬인 경우(막혀있다는의미(해당 방향으로는 전진 불가))
						if (Q17272_map[next.first][next.second] == Q17272_map[i][j])	break;
						//다른 섬
						if (Q17272_map[next.first][next.second]!=0 && Q17272_map[next.first][next.second] != Q17272_map[i][j]) {
							if (dis < 2)	break;
							Q17272_bridge[Q17272_map[i][j]][Q17272_map[next.first][next.second]] = std::min(Q17272_bridge[Q17272_map[i][j]][Q17272_map[next.first][next.second]], dis);
							break;
						}
						next.first += Q17472_dir_yx[d].first;
						next.second += Q17472_dir_yx[d].second;
						dis++;
					}
				}
				
			}
		}
	}
}

int Q17272_kruskal() {
	AJS.init_AdjointSet(land_number);

	std::priority_queue<std::pair<int,std::pair<int,int>>, std::vector< std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;

	for (int i = 1; i < land_number; i++) {
		for (int j = i + 1; j < land_number; j++) {
			if (Q17272_bridge[i][j] != 20) {
				pq.push(std::make_pair(Q17272_bridge[i][j], std::make_pair(i, j)));
			}
		}
	}

	while (!pq.empty()) {
		int from, to, val;

		val = pq.top().first;
		from = pq.top().second.first;
		to = pq.top().second.second;

		pq.pop();

		if (AJS.find(from) != AJS.find(to)) {
			AJS.union_set(from, to);
			Q17272_ret += val;
		}
	}

	bool complete = true;

	for (int i = 2; i < land_number; i++) {
		if (AJS.find(1) != AJS.find(i)) {
			complete = false;
		}
	}
	if (!complete)
		return -1;
	else
		return Q17272_ret;
}

void Q17472_soulution() {
	Q17472_input();

	Q17272_gruoping();
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			Q17272_bridge[i][j] = 20;
		}
	}
	Q17272_make_bridge();
	std::cout << Q17272_kruskal() << "\n";

}

void Q17472() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	Q17472_soulution();
}