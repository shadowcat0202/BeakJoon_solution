#include<iostream>
#include<queue>

#define endl "\n"
#define MAX 50
using namespace std;

int R, C;
int Water_MAP[MAX][MAX];
char MAP[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

pair<int, int> Start_Pos, End_Pos;
queue<pair<int, int>> Water_Q;

void Input()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Water_MAP[i][j] = 999;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 'S')
			{
				Start_Pos.first = i;
				Start_Pos.second = j;
			}
			else if (MAP[i][j] == 'D')
			{
				End_Pos.first = i;
				End_Pos.second = j;
			}
			else if (MAP[i][j] == '*')
			{
				Water_MAP[i][j] = 0;
				Water_Q.push(make_pair(i, j));
			}
		}
	}
}

void Make_WaterMap()
{
	while (Water_Q.empty() == 0)
	{
		int Qs = Water_Q.size();
		for (int i = 0; i < Qs; i++)
		{
			int x = Water_Q.front().first;
			int y = Water_Q.front().second;
			Water_Q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < R && ny < C)
				{
					if (MAP[nx][ny] == '.')
					{
						if (Water_MAP[nx][ny] > Water_MAP[x][y] + 1)
						{
							Water_MAP[nx][ny] = Water_MAP[x][y] + 1;
							Water_Q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

void Move()
{
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(Start_Pos.first, Start_Pos.second), 0));
	Visit[Start_Pos.first][Start_Pos.second] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int Cnt = Q.front().second;
		Q.pop();

		if (x == End_Pos.first && y == End_Pos.second)
		{
			cout << Cnt << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C)
			{
				if (Visit[nx][ny] == false && MAP[nx][ny] != 'X' && Water_MAP[nx][ny] > Cnt + 1)
				{
					Visit[nx][ny] = true;
					Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
				}
			}
		}
	}
	cout << "KAKTUS" << endl;
}

void Solution()
{
	Make_WaterMap();
	Move();
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}