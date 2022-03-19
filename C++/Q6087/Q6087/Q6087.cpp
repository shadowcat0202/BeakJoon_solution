#include <iostream>
#include <queue>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

const int MAX = 100;
vector<pair<int, int>> L;
pair<int, int> dir[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };//북쪽부터 시계방향

pair<int, int> start[2];
int W, H;	//가로 세로
int map[MAX][MAX], cost_map[MAX][MAX];
int visited[MAX][MAX];

void step() {
	while (true) {
		if (_getch())	break;
	}
	system("cls");
}

void input() {
	cin >> W >> H;	//가로 세로
	string s;
	for (int i = 0; i < H; i++) {
		cin >> s;
		for (int j = 0; j < W; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'C') {
				L.push_back(make_pair(i, j));
			}
		}
	}	
}

void BFS() {		
	queue<pair<int, int>> q;
	q.push(L[0]);
	int cy = q.front().first;
	int cx = q.front().second;
	q.pop();

	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i].first;
			int nx = cx + dir[i].second;
			while (!(ny < 0 || ny >= H || nx < 0 || nx >= W || map[ny][nx] == '*')) {
				if (!cost_map[ny][nx]) {
					cost_map[ny][nx] = cost_map[cy][cx] + 1;
					q.push(make_pair(ny,nx));
				}
				ny += dir[i].first, nx += dir[i].second;
			}
		}		
	}
}

void solution() {
	input();	
	BFS();
	cout << cost_map[L[1].first][L[1].second];
}

int main()
{
	solution();
	return 0;
}