#include <iostream>
#define endl "\n";

using namespace std;


const int MAX = 50 + 1;
int R,C;
int map[MAX][MAX];
int clean[MAX][MAX];

pair<pair<int, int>, int> Robot;
pair<int,int> d[4] = { {-1,0},{0,-1},{1,0},{0,1} };	//북서남동	북쪽부터 반시계
bool stuck, flag = false;
int clean_count = 0;


void forward(int y, int x, int look) {
	Robot.first.first = y;
	Robot.first.second = x;
	Robot.second = look;
}

void clean_room() {
	clean[Robot.first.first][Robot.first.second] = true;
	clean_count++;
}


void input() {
	cin >> R >> C;
	cin >> Robot.first.first>> Robot.first.second >> Robot.second;
	if (Robot.second == 1)	Robot.second = 3;
	else if (Robot.second == 3) Robot.second = 1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	clean_room();
}

bool cant_move() {
	int bd = (Robot.second + 2) % 4;
	int back_y = Robot.first.first + d[bd].first;
	int back_x = Robot.first.second + d[bd].second;
	if (map[back_y][back_x] == 1)	return 1;
	else {
		Robot.first.first = back_y;
		Robot.first.second = back_x;
		return 0;
	}
}


bool serch() {
	int serch_look = Robot.second;
	//cout << Robot.first.first << "," << Robot.first.second << "에서" << endl;
	for (int i = 0; i < 4; i++) {
		
		serch_look = (serch_look + 1) % 4;
		int ny = Robot.first.first + d[serch_look].first;
		int nx = Robot.first.second + d[serch_look].second;
		//cout << "\t" << ny << "," << nx <<"탐색"<< endl;
		//범위를 벗어남
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
			//cout << "벗어남" << endl;
			continue;
		}
		//방문한적도 없고 청소한적도 없는 경우
		if (map[ny][nx] == 0 && clean[ny][nx] == 0) {
			forward(ny,nx,serch_look);
			clean_room();
			return 1;
		}
	}
	if (cant_move()) {
		//cout << "못움직임" << endl;
		cout << clean_count << endl;
		return 0;
	}
	return 1;
}



int main() {	
	/*
	1.현재 위치를 청소한다.
	2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		2_1.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		2_2.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		2_3.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		2_4.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
	*/
	input();

	while (serch()) {
		//cout << "탐색중" << endl; 
	}
	return 0;
}