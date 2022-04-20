#include <iostream>
#include <queue>
#include <string>
#include <conio.h>
#include <windows.h>
#include <algorithm>

using namespace std;
/*
C라면 #define, C++라면 const
const가 자료형을 지정할 수있기 떄문에 안전함
enum도 사용 가능함
enum{
	MAX = 100 + 1;
}
*/  //변수 선언에 대한 설명
const int MAX = 100;
int R, C, N, Count = 1;
int visited[MAX][MAX];
pair<int, int> dir[4] = { {-1,0}, {0,1}, {1,0},{0,-1} };	//시계방향
char cave[MAX][MAX], buf_cave[MAX][MAX];
queue<pair<int, int>> Q;
queue<int> T;
bool TF = false;
bool ground[MAX];


void step() {
	while (true) {
		if (_getch())	break;
	}
	system("cls");
	
}

void Qclear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}
void Vclear(vector<int> &v) {
	vector<int> empty;
	empty.swap(v);
}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			cave[i][j] = s[j];
		}
	}
	cin >> N;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		T.push(t);
	}
}


void Throw(int h) {
	if (TF) {	//오른쪽에서 던짐
		cout << "오른\n";
		for (int i = C - 1; i >= 0; i--) {
			if (cave[R - h][i] == 'x') {
				cave[R - h][i] = '.';		
				break;
			}
		}
		TF = false;
	}
	else {	//왼쪽에서 던짐
		cout << "왼\n";
		for (int i = 0; i < C; i++) {
			if (cave[R - h][i] == 'x') {
				cave[R - h][i] = '.';				
				break;
			}
		}
		TF = true;
	}
}

bool checkground() {
	for (int i = 0; i < Count; i++) {
		if (ground[i] == false) {
			return false;	//땅에 닿지 않는것이 하나라도 존재
		}
	}
	return true;	//위의 반대
}
void gravity() {
	for (int i = R-1; i >= 0; i--) {
		for (int j = C-1; j >= 0; j--) {
			if (cave[i][j] == 'x') {				
				if (ground[(visited[i][j]-1)]) {
					buf_cave[i][j] = 'x';
				}
				else {
					buf_cave[i + 1][j] = 'x';
					buf_cave[i][j] = '.';					
				}
			}
			else {
				buf_cave[i][j] = '.';
			}
		}
	}
}

void BFS() {
	Count++;
	cout << "BFS실행\n";
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		if (cy == (R - 1)) {	
			//해당 클러스터가 바닥에 붙어있을 경우(중력에 의해 내려갈 필요 없음)
			ground[Count-1] = true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i].first;
			int nx = cx + dir[i].second;
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] > -1)	continue;
			if (cave[ny][nx] == 'x') {
				Q.push(make_pair(ny, nx));
				visited[ny][nx] = Count;
			}			
		}	
	}
	Count++;
}

void solution() {
	input();
	while (!T.empty()) {
		Throw(T.front());
		T.pop();

		while(true) {			
			memset(visited, 0, sizeof(int) * MAX * MAX);	
			memset(ground, false, sizeof(bool) * MAX);
			Count = 0;

			for (int i = R - 1; i >= 0; i--) {
				for (int j = C - 1; j >= 0; j--) {
					if (cave[i][j] == 'x' && visited[i][j] == 0) {
						Q.push(make_pair(i, j));
						BFS();
					}
				}
			}			
			Qclear(Q);
			for (int g = 0; g < Count; g++) {
				printf("ground[%d] = %d\n",g,ground[g]);
			}
			if (checkground()) {
				break;
			}
			gravity();		//buf_cave작업		
			memcpy(cave, buf_cave, sizeof(char) * MAX * MAX);
			memset(buf_cave, NULL, sizeof(char) * MAX * MAX);			
		} 
	}
}

int main() {
	memset(visited, -1, sizeof(int) * MAX * MAX);
	solution();
}