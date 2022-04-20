#include <iostream>
#define endl "\n";

using namespace std;


const int MAX = 50 + 1;
int R,C;
int map[MAX][MAX];
int clean[MAX][MAX];

pair<pair<int, int>, int> Robot;
pair<int,int> d[4] = { {-1,0},{0,-1},{1,0},{0,1} };	//�ϼ�����	���ʺ��� �ݽð�
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
	//cout << Robot.first.first << "," << Robot.first.second << "����" << endl;
	for (int i = 0; i < 4; i++) {
		
		serch_look = (serch_look + 1) % 4;
		int ny = Robot.first.first + d[serch_look].first;
		int nx = Robot.first.second + d[serch_look].second;
		//cout << "\t" << ny << "," << nx <<"Ž��"<< endl;
		//������ ���
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
			//cout << "���" << endl;
			continue;
		}
		//�湮������ ���� û�������� ���� ���
		if (map[ny][nx] == 0 && clean[ny][nx] == 0) {
			forward(ny,nx,serch_look);
			clean_room();
			return 1;
		}
	}
	if (cant_move()) {
		//cout << "��������" << endl;
		cout << clean_count << endl;
		return 0;
	}
	return 1;
}



int main() {	
	/*
	1.���� ��ġ�� û���Ѵ�.
	2.���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
		2_1.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		2_2.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		2_3.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
		2_4.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
	*/
	input();

	while (serch()) {
		//cout << "Ž����" << endl; 
	}
	return 0;
}