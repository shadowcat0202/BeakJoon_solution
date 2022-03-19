#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <conio.h>
#include <windows.h>

#define MAX 100+1
using namespace std;
typedef struct {
	int y, x;
}dir;

int R, C;
int map[MAX][MAX];
int visited[MAX][MAX];
pair<pair<int,int>,pair<int,int>> Start, End;	//(y,x),방향
dir movedir[4] = { {0,1},{1,0},{0, -1} ,{-1,0} };
queue<pair<pair<int, int>, pair<int,int>>> q;

void step() {
	while (true) {
		if (_getch())	break;
	}
	system("cls");
}
void show() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited[i][j] << "	";
		}
		cout << "\n\n";
	}
	step();
}


int Change(int buf) {
	switch (buf) {
	case 1:
		return 0;
		break;
	case 3:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 4:
		return 3;
		break;
	default:
		break;
	}
}

void input() {
	int buf;
	cin >> R >> C;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			cin >> map[i][j];
		
	cin >> Start.first.first >> Start.first.second >> buf;
	Start.first.first -= 1;
	Start.first.second -= 1;
	Start.second.first = Change(buf);

	cin >> End.first.first >> End.first.second >> buf;	
	End.first.first -= 1;
	End.first.second -= 1;
	End.second.first = Change(buf) ;
	cout << "종료 방향"<<End.second.first<<"\n";

	q.push({ {Start.first.first,Start.first.second},{Start.second.first, 0} });	
}

int BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;		//y
		int x = q.front().first.second;		//x
		int d = q.front().second.first;		//방향
		int cost = q.front().second.second;	//비용
		q.pop();
		//visited[y][x] = d;
		printf("[%d,%d]에서 방향= %d cost = %d\n", y + 1, x + 1, d, cost);
		if (y == End.first.first && x == End.first.second) {	//도착
			cost += abs(d - End.second.first);
			printf("[%d,%d]도착 cost = %d\n", y + 1, x + 1, cost);
			return cost;	//출력
		}

		for (int i = 0; i < 4; i++) {	//방향
			for (int j = 1; j <= 3; j++) {	//거리
				int ny = y + movedir[i].y * j;
				int nx = x + movedir[i].x * j;
				
				if (map[ny][nx] == 1) {	//벽
					break;
				}
				if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
					break;
				}
				if (visited[ny][nx] < 999) {
					continue;
				}
				if (d > cost + abs(d - i) + 1) {
					cout << "들어오냐?\n";
					q.push({ {ny,nx},{i, cost + abs(d - i) + 1} });	//abs(d - i) = 방향 비용
					visited[ny][nx] = cost + abs(d - i) + 1;
				}				
				else {
					q.push({ {ny,nx},{i, cost} });

				}
				show();
			}
		}
	}
}	


void solution() {
	input();
	std::fill(&visited[0][0], &visited[0][0] + sizeof(int)*MAX*MAX, 999);
	cout << BFS() << "\n";
}


int main()
{
	solution();
}