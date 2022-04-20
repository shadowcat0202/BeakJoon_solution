#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int max_n = 1501;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int visited_swan[max_n][max_n], R, C, day, swanY, swanX;
char _map[max_n][max_n];
bool isSwanMeet;
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void water_melting() {
	while (waterQ.size()) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
			if (_map[ny][nx] == 'X') {
				water_tempQ.push({ ny, nx });
				_map[ny][nx] = '.';
			}
		}
	}

}

void move_swan() {
	while (swanQ.size()) {
		int y = swanQ.front().first;
		int x = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
			if (_map[ny][nx] == '.')swanQ.push({ ny, nx });
			else if (_map[ny][nx] == 'X') swan_tempQ.push({ ny, nx });
			else if (_map[ny][nx] == 'L') { isSwanMeet = true; return; }
			visited_swan[ny][nx] = 1;
		}
	}
}
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			_map[i][j] = s[j];
			if (_map[i][j] == 'L') { swanY = i; swanX = j; }
			if (_map[i][j] == '.' || _map[i][j] == 'L')waterQ.push({ i, j });
		}
	}
	swanQ.push({ swanY, swanX });
	visited_swan[swanY][swanX] = 1;
}

int main() {
	input();	
	while (!isSwanMeet) {
		move_swan();
		if (isSwanMeet) break;
		water_melting();
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		Qclear(water_tempQ);
		Qclear(swan_tempQ);
		day++;
	}
	cout << day << "\n";

	return 0;
}