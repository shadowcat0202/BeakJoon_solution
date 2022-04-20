#include <iostream>
#include <deque>
using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];
pair<pair<int, int>, int> snake_haed = { {0,0}, 0 };	//초기 시작점	0:오른쪽 시계방향 증가
deque<pair<int, int>> snake;
int N, L, apple_count, live_time = 0;
pair<int, int> d[4] = { {0,1},{1,0},{0,-1},{-1,0} };



void forward() {
	map[snake.back().first][snake.back().second] = 0;
	live_time++;
}

void add_tail() {
	
}

void turnD() {	//오른쪽으로 90도
	
}

void turnL() {	//왼쪽으로 90도
}

bool is_out() {	//장외 혹은 꼬리를 밟은 여부 확인
	int ny;
	int nx;

	if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
		//장외
		return 1;
	}
	else if (map[ny][nx] == 2) {
		//꼬리 밟음
		return 1;
	}
	else if (map[ny][nx] == 1) {
		//사과 먹음
		add_tail();
		return 0;
	}
	else {
		forward();
		return 0;
	}
}

void input() {
	cin >> N >> apple_count;
	for (int i = 0; i < apple_count; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;	//사과 위치
	}
	snake.push_back(make_pair(0, 0));
	map[0][0] = 2;
	cin >> L;
	for (int i = 0; i < L; i++) {
		
	}
	
}

int main() {
	/*
		먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
		만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.
	
		사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.
	*/
	return 0;
}