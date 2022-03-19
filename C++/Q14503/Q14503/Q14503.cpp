#include <iostream>
#include <queue>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#define MAX 50
#define MIN 3

using namespace std;
int N, M, L;	//세로 가로 보는방향
int Room[MAX][MAX], tmp[MAX][MAX];	//방의 크기
//서쪽부터 반시계 방향
int xlook[] = { -1, 0, 1, 0 };
int ylook[] = { 0, 1, 0, -1 };

pair<int, int> Cpos;	//현재 위치<y,x>
int clean = 0;

void showvalue() {
	printf("L:%d Cpos:[%d,%d] 청소횟수:%d",L, Cpos.first+1, Cpos.second+1,clean);
}

/*--------------화면 보여주기---------------*/
void showRoom() {
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Cpos.first == i && Cpos.second == j) {
				cout << "	[" << Room[i][j] << "]";
			}
			else {
				cout << "	" << Room[i][j];
			}
		}
		cout << "\n";
	}
	showvalue();

}

/*----------------깊이 우선 탐색---------------*/
void DFS() {
	int Nx, Ny, back, Bx, By;

	while (true) {
		for (int c = 0; c < 4; c++) {
			showRoom();
			while (!(_getch())) {}	//키입력할때까지 대기
			L++;
			if (L > 3)	L = 0;

			Nx = Cpos.second + xlook[L];
			Ny = Cpos.first + ylook[L];

			if (Room[Ny][Nx] == 0) {
				Cpos = { Ny,Nx };
				Room[Ny][Nx] = -1;
				clean++;
				c = 0;
			}
			else if ( abs(Room[Ny][Nx]) == 1 ) {									
			}
			showRoom();
			while (!(_getch())) {}	//키입력할때까지 대기
		}
		back = (L + 2) % 4;
		By = Cpos.first + ylook[back];
		Bx = Cpos.second + xlook[back];
		if (Room[By][Bx] == 1)	break;	//더이상 움직일 곳 없음
		else {//뒤로 한칸
			cout << "뒤로";
			Cpos = { By,Bx };
		}	
		showRoom();
		while (!(_getch())) {}	//키입력할때까지 대기
	}
}

void inputmap(int y, int x) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Room[i][j];
		}
	}
	//시작 위치 청소 판정
	Cpos = { y, x };
	Room[y][x] = -1;
	clean++;
	showRoom();
	while (!(_getch())) {}	//키입력할때까지 대기
}




int main()
{
	int Sx, Sy;	//시작점
	int d;	//0북 1동 2남 3서
	cin >> N >> M;
	cin >> Sy >> Sx >> d;
	inputmap(Sy, Sx);
	L = 3 - d;
	DFS();
	cout << clean;
}
