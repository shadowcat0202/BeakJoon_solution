#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;


//input
int n;//맵크기
int map[MAX_SIZE][MAX_SIZE];//맵

//process
int visit[MAX_SIZE][MAX_SIZE];//방문체크
vector<pair<int, int> > land;//땅을 저장할 벡터
int land_number;//땅마다 넘버 붙이기
int visit_number;//방문체크 넘버

//direct
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

//땅마다 넘버붙이기 함수
void land_mark(int x, int y)
{
	if (visit[x][y] == 1) return;
	visit[x][y] = 1;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		map[x][y] = land_number;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) continue;
			if (!map[nx][ny]) continue;
			visit[nx][ny] = 1;

			q.push(make_pair(nx, ny));

		}
	}

	land_number++;
}

//거리를 측정하는 bfs함수 ln은 랜드 넘버
int dist(int x, int y, int ln)
{
	bool flag = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] == 0)
		{
			flag = 1;
			break;
		}
	}

	if (!flag) return INF;//네 방향에 바다가 없으면 리턴
	visit_number++;

	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(x, y), 0));

	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int weight = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == visit_number) continue;

			if (map[nx][ny] == ln) continue;
			else if (map[nx][ny] != ln && map[nx][ny] != 0) return weight;

			visit[nx][ny] = visit_number;
			q.push(make_pair(make_pair(nx, ny), weight + 1));
		}
	}

	return INF;
}


int main()
{

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) land.push_back(make_pair(i, j));
		}
	}

	land_number = 1;

	for (int i = 0; i < land.size(); i++) land_mark(land[i].first, land[i].second);

	memset(visit, 0, sizeof(visit));
	int ret = INF;

	for (int i = 0; i < land.size(); i++)
	{
		int x = land[i].first;
		int y = land[i].second;
		ret = min(ret, dist(x, y, map[x][y]));
	}

	printf("%d\n", ret);


	return 0;

}