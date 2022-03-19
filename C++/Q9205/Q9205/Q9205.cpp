#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100

using namespace std;
typedef pair<int, int> pos_p;

int n;
bool visited[MAX], ishappy;
pos_p Start, End;
vector<pos_p> pos;
int beer = 20;

void input() {
	int x, y;

	cin >> n;
	cin >> Start.first>> Start.second;	//상근이네 집

	pos.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		cin >> x >> y;	//편의점 위치 * n 개
		pos.push_back(make_pair(x, y));
	}	

	cin >> End.first >> End.second;	//패스티벌 위치

}

void DFS(int x, int y) {
	int num;
	num = abs(End.first - x) + abs(End.second - y);

	if (num <= 1000)	ishappy = true;

	for (int i = 0; i < pos.size(); i++) {
		if (visited[i] == true)	continue;
		
		num = abs(pos[i].first - x) + abs(pos[i].second - y);

		if (num > 1000)	continue;
		else {
			visited[i] = true;
			DFS(pos[i].first, pos[i].second);
		}
	}

}

int main()
{
	int t;
	cin >> t;
	while(t--){
		input();

		ishappy = false;
		DFS(Start.first, Start.second);

		if (ishappy == true)	cout << "happy\n";
		else					cout << "sad\n";
	}
}