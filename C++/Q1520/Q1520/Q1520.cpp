#include <iostream>
#include <cstring>
#define endl "\n"
#define MAX 500 + 1


using namespace std;

int N, M;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 0,1,0,-1 },
	dx[4] = { 1,0,-1,0 };

void input() {
	//입력
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int DFS(int y, int x) {
	if (dp[y][x] != -1)	return dp[y][x];
	if (y < 0 || y >= M || x < 0 || x >= N) return 0;
	if (y == 0 && x == 0)	return 1;

	dp[y][x] = 0;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d], nx = x + dx[d];
		if (map[y][x] < map[ny][nx]) {
			dp[y][x] += DFS(ny,nx);
		}
	}
	return dp[y][x];
}

void solution() {
	input();
	cout << DFS(M - 1, N - 1);

}

int main()
{
	solution();
	return 0;
}