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

void DFS(int node) {	//���� �켱Ž��
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
	bool* visited = new bool[N + 1]{ false, };	//�湮 ���� �迭 �����Ҵ�
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
	//cout << endl << "BFS ����" << endl;
}
int main() {
	//�б� ���� ����� ���� �������� ��ȯ
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