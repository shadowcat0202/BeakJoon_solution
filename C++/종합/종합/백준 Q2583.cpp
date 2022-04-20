/*
����
������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�. 
�� ������ ���� ���ݿ� ���߾� K���� ���簢���� �׸� ��, �̵� K���� ���簢���� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ����������.

���� ��� M=5, N=7 �� ������ ���� <�׸� 1>�� ���� ���簢�� 3���� �׷ȴٸ�, �� ������ ������ <�׸� 2>�� ���� 3���� �и��� �������� ���������� �ȴ�.



<�׸� 2>�� ���� �и��� �� ������ ���̴� ���� 1, 7, 13�� �ȴ�.

M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������, �׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. M, N, K�� ��� 100 ������ �ڿ����̴�. 
��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. 
�������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. 
�ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.

���
ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�.
��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�.

���� �Է� 1
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
���� ��� 1
3
1 7 13
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define Q2583_MAX 101

int Q2583_M, Q2583_N, Q2583_K, Q2583_area_size;
bool Q2583_map[Q2583_MAX][Q2583_MAX];
bool Q2583_visited[Q2583_MAX][Q2583_MAX];
std::pair<int, int> dir_yx[4] = { {1,0},{-1,0},{0,1},{0,-1} };


void Q2583_input() {
	std::cin >> Q2583_M >> Q2583_N >> Q2583_K;
	while (Q2583_K--) {
		int p1x, p1y, p2x, p2y;
		std::cin >> p1x >> p1y >> p2x >> p2y;
		for (int y = p1y; y < p2y; y++) {
			for (int x = p1x; x < p2x; x++) {
				Q2583_map[y][x] = true;
			}
		}
	}
}

//DFS(���)
void Q2583_DFS(std::pair<int,int> node) {
	Q2583_visited[node.first][node.second] = true;
	Q2583_area_size++;
	for (int i = 0; i < 4; i++) {
		std::pair<int, int> next;
		next.first = node.first + dir_yx[i].first;
		next.second = node.second + dir_yx[i].second;

		//���� ������ ����
		if (next.first < 0 || next.second < 0 || next.first >= Q2583_M || next.second >= Q2583_N) continue;

		if (Q2583_map[next.first][next.second] == 0 && !Q2583_visited[next.first][next.second]) {
			Q2583_DFS(next);
		}

	}


}

//BFS(queue(BFS�� �� �� �ִ� ����� ť �ۿ� ����))//���� �̰� �� �ȵǴ°���?
//->ó���� ��ġ�� ���� +1�� �����淡 ���� �ߴµ� start�κ��� ��� ���� ������ ���ؼ� �׷���
void Q2583_BFS(std::pair<int,int> start) {
	std::queue<std::pair<int,int>> q;
	q.push(start);
	Q2583_visited[start.first][start.second] = true;

	while (!q.empty()) {		
		std::pair<int, int> now = q.front();
		q.pop();
		Q2583_area_size++;

		for (int i = 0; i < 4; i++) {
			std::pair<int, int> next;
			next.first = now.first + dir_yx[i].first;
			next.second = now.second + dir_yx[i].second;

			//���� ���� �� ����
			if (next.first < 0 || next.second < 0 || next.first >= Q2583_M || next.second >= Q2583_N)	continue;

			if (Q2583_map[next.first][next.second] == 0 && !Q2583_visited[next.first][next.second]) {
				Q2583_visited[next.first][next.second] = true;
				q.push(next);
			}

		}
	}

}

void Q2583_solution() {
	std::vector<int> res;
	for (int i = 0; i < Q2583_M; i++) {
		for (int j = 0; j < Q2583_N; j++) {
			if (Q2583_map[i][j] == false && !Q2583_visited[i][j]) {
				Q2583_area_size = 0;
				std::pair<int, int> start = {i,j};
				Q2583_BFS(start);
				res.push_back(Q2583_area_size);
			}
		}
	}

	std::sort(res.begin(), res.end());
	std::cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << " ";
	}
}


void Q2583() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	Q2583_input();
	Q2583_solution();
}