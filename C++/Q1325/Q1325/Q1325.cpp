#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10000 + 1

using namespace std;

int N, M, num,tmp_answer;
bool visited[MAX];
vector<int> computer[MAX];


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		computer[b].push_back(a);
	}
}

void DFS(int x) {
	visited[x] = true;
	for (int i = 0; i < computer[x].size(); i++) {
		int nx = computer[x][i];
		if (visited[nx] == false) {
			num++;
			DFS(nx);
		}

	}
}

void solution() {
	vector<int> q;
	for (int i = 0; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		num = 0;
		DFS(i);
		if (tmp_answer == num)
			q.push_back(i);
		else if (tmp_answer < num) {
			tmp_answer = num;
			q.clear();
			q.push_back(i);
		}
	}
	sort(q.begin(), q.end());
	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << " ";
	}
	cout << "\n";
}

int main()
{
	input();
	solution();
}