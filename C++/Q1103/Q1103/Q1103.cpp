/*
아직 못풀음 이해가 안됨
*/
#include <iostream>
#include <string>
#define max(a,b) a>b?a:b
#define endl "\n"
#define MAX 50
#define H 24
using namespace std;

int R, C, movecount = 0;
char map[MAX][MAX];
int dp[MAX][MAX] = {-1,};
int visited[MAX][MAX];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };


void input() {
	//입력
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

int moveDFS(int y, int x) {
	//풀이
	/*
		동전이 있는 곳의 숫자 X
		상하좌우 중 한방향 선택
		선택한 방향으로 X만큼 이동
		H에 도착하거나 map의 범위를 벗어나는 경우 종료
		종료 할수 없다면(무한으로 움직인다면) -1출력
	*/
	if (y < 0 || y >= R || x < 0 || x >= C || map[y][x] == 'H') return 0;	//범위 초과 || 구멍
	if (visited[y][x]) {	//재방문
		cout << "-1";
		exit(0);
	}

	int& ret = dp[y][x];
	if (ret != -1)	return ret;
	visited[y][x] = 1;

	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d] * map[y][x];
		int nx = x + dx[d] * map[y][x];

		int val = moveDFS(ny,nx) + 1;
		ret = max(ret, val);
	}

	visited[y][x] = 0;
	return ret;	

}


int main()
{
	input();
	cout << moveDFS(0,0) << endl;	//[0,0]시작점
}