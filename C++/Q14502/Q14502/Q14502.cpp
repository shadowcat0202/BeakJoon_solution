﻿#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAX 9

using namespace std;

int R, C, zeroCnt, maxZero;
int dR[] = { 1,0,-1,0 };
int dC[] = { 0,1,0,-1 };

int map[MAX][MAX], tmp[MAX][MAX];
queue<pair<int, int>> VirusQ;

bool isInRange(int row, int col) {
	return (row >= 0 && row < R) && (col >= 0 && col < C);
}

void BFS(int& zero) {
	int afterWall[MAX][MAX];
	memcpy(afterWall, tmp, sizeof(tmp));
	int zC = zero;
	queue<pair<int, int>> Q = VirusQ;

	while (!Q.empty()) {
		int cR = Q.front().first;
		int cC = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {	//바이러스 시작점에서 이동한 바이러스 계산 nR nC
			int nR = cR + dR[i];
			int nC = cC + dC[i];

			if (isInRange(nR, nC) && afterWall[nR][nC] == 0) {
				afterWall[nR][nC] = 2;
				--zC;
				Q.push({ nR,nC });
			}
		}
	}
	maxZero = max(maxZero, zC);
}

void makeWall(int cnt, int& zero) {
	if (cnt == 3) {
		BFS(zero);
		return;
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				--zero;
				makeWall(cnt + 1, zero);
				tmp[i][j] = 0;
				++zero;
			}
		}
	}
}

void copyroom() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0) {
				memcpy(tmp, map, sizeof(map));
				tmp[i][j] = 1;
				--zeroCnt;
				makeWall(1, zeroCnt);
				tmp[i][j] = 0;
				++zeroCnt;
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	zeroCnt = R * C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				--zeroCnt;
				if (map[i][j] == 2) {
					VirusQ.push({ i,j });
				}
			}
		}
	}

	copyroom();

	cout << maxZero;
	return 0;
}