/*
문제
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 
이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.



<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 
모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 
입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다.
둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

예제 입력 1
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
예제 출력 1
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

//DFS(재귀)
void Q2583_DFS(std::pair<int,int> node) {
	Q2583_visited[node.first][node.second] = true;
	Q2583_area_size++;
	for (int i = 0; i < 4; i++) {
		std::pair<int, int> next;
		next.first = node.first + dir_yx[i].first;
		next.second = node.second + dir_yx[i].second;

		//맵의 범위밖 무시
		if (next.first < 0 || next.second < 0 || next.first >= Q2583_M || next.second >= Q2583_N) continue;

		if (Q2583_map[next.first][next.second] == 0 && !Q2583_visited[next.first][next.second]) {
			Q2583_DFS(next);
		}

	}


}

//BFS(queue(BFS는 할 수 있는 방법은 큐 밖에 없다))//뭐지 이거 왜 안되는거지?
//->처음에 수치가 전부 +1씩 나오길래 뭔가 했는데 start부분을 방분 상태 변경은 안해서 그런것
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

			//맵의 범위 밖 무시
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