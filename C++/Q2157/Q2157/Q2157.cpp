#include <iostream>
#include <cstring>
#define endl "\n"
#define MAX 300 + 1
#define max(a,b) (a>b)?a:b
#define INF 987654321;
using namespace std;

int N, M, K;
int map[MAX][MAX];
int visited[MAX][MAX];


int move(int idx, int visit) {
	if (visit == M && idx != N)	return -INF;
	if (idx == N)	return 0;

	int& res = visited[idx][visit];
	if (res != -1)	return res;

	res = 0;
	for (int to = (idx + 1); to <= N; to++) {
		if (map[idx][to])
			res = max(res, map[idx][to] + move(to, visit + 1));
	}
	return res;
}

void input() {
	//입력
	/*
	N개의 도시 존재 최대 M번의 이동 K개의 항공로
	a 에서 b로의 기내식의 점수 c
	*/

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = max(map[a][b], c);
	}

}



int main()
{
	input();
	memset(visited, -1, sizeof(visited));
	cout << move(1, 1) << endl;
}