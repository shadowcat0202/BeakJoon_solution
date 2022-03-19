#include <iostream>
#include <deque>
using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];
pair<pair<int, int>, int> snake_haed = { {0,0}, 0 };	//�ʱ� ������	0:������ �ð���� ����
deque<pair<int, int>> snake;
int N, L, apple_count, live_time = 0;
pair<int, int> d[4] = { {0,1},{1,0},{0,-1},{-1,0} };



void forward() {
	map[snake.back().first][snake.back().second] = 0;
	live_time++;
}

void add_tail() {
	
}

void turnD() {	//���������� 90��
	
}

void turnL() {	//�������� 90��
}

bool is_out() {	//��� Ȥ�� ������ ���� ���� Ȯ��
	int ny;
	int nx;

	if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
		//���
		return 1;
	}
	else if (map[ny][nx] == 2) {
		//���� ����
		return 1;
	}
	else if (map[ny][nx] == 1) {
		//��� ����
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
		map[y][x] = 1;	//��� ��ġ
	}
	snake.push_back(make_pair(0, 0));
	map[0][0] = 2;
	cin >> L;
	for (int i = 0; i < L; i++) {
		
	}
	
}

int main() {
	/*
		���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
		���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
		���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.��, �����̴� ������ �ʴ´�.
	
		����� ��ġ�� ���� �̵���ΰ� �־��� �� �� ������ �� �ʿ� �������� ����϶�.
	*/
	return 0;
}