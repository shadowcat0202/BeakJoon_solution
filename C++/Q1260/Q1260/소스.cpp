#include <iostream>
#include <Queue>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;
const int MAX = 10000;
int N, M,V;
vector<int> arr[1001];
bool visited[1001];

void DFS(int node) {	//깊이 우선탐색
	visited[node] = true;
	cout << node << " ";

	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (visited[next] == false) {
			DFS(next);
		}
	}
}
void BFS(int start_node) {
	queue<int> bfs;
	bool* visited = new bool[N + 1]{ false, };	//방문 여부 배열 동적할당
	memset(visited, false, sizeof(visited));
	bfs.push(start_node);
	visited[start_node] = true;

	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();
		cout << now << " ";

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] == false) {
				visited[next] = true;
				bfs.push(next);
			}
		}
	}
	cout << endl;
	//cout << endl << "BFS 종료" << endl;
}
int main() {
	//읽기 쓰기 방식을 파일 형식으로 전환
	/*freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);*/
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);

	}
	for (int i = 0; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	DFS(V);
	cout << endl;
	BFS(V);
	return 0;
}