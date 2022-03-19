#include <iostream>
#include <cstring>
#define endl "\n"
#define MAX 500 + 1

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n;
int map[MAX][MAX], dp[MAX][MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}
int maxday(int y,int x) {
	int& result = dp[y][x];
	if (result != -1)	return result;

	result = 1;
	int tmp;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)	continue;
		if (map[ny][nx] > map[y][x]) {
			tmp = 1 + maxday(ny, nx);
			if (tmp > result)	result = tmp;
		}
	}

	return result;
}
void solution() {
	int longtime = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int buf = maxday(i,j);
			if (longtime < buf)	longtime = buf;
		}
	}
	cout << longtime << endl;
}

int main()
{
	input();
	memset(dp, -1, sizeof(dp));
	solution();
	return 0;
}