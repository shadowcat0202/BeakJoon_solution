#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define HIGHT 10	//빙산 최대 높이
#define MAX 300	//map의 가로 세로 각 최대 길이
using namespace std;


int N, M, year;	// N행 M열
int map[MAX][MAX], buf_map[MAX][MAX];
bool visited[MAX][MAX];
int dirY[4] = { -1, 0, 1, 0 },
	dirX[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> water;


void Qclear(queue<pair<int,int>> &q) {
	queue<pair<int, int>> clearQ;
	swap(q, clearQ);
}

void show() {

}


/*============ map <- buf_map ===============*/
void mapcopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = buf_map[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	memset(buf_map, 0, sizeof(buf_map));
}

void input() {
	//Line 1. 가로 세로 입력
	cin >> N >> M;

	//Line 2 ~. map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void BFS(int y, int x) {	//빙하 덩어리 하나 찾는 중
	queue<pair<int, int>> q;
	int melt = 0;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		visited[cy][cx] = true;	//방문 표시

		for (int d = 0; d < 4; d++) {
			int ny = cy + dirY[d];
			int nx = cx + dirX[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)	continue;	//범위 부적절
			if (map[ny][nx] == 0) {	//물인경우
				melt++;
				continue;
			}
			if (visited[ny][nx] == true)	continue;	//방문 여부
			
			q.push(make_pair(ny, nx));			
		}
		
		buf_map[y][x] = map[y][x] - melt;
		if (buf_map[y][x] < 0)	buf_map[y][x] = 0;
	}
}



void solution() {
	int land = 0;	//count = year
	while (land < 2) {		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {	//빙하 발견
					land++;
					BFS(i, j);
					
				}
			}
		}
		mapcopy();
		year++;
		land = 0;
	}

	cout << year << "\n";
	
}
int main()
{
	input();
	solution();
}
