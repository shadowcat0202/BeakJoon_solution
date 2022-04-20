#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 20000+1	//이부분 +1을 안하면 런타임 에러 배열 인덱스 부분에서 문제가 생기는 듯 하다
#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;	//테스트 케이스 개수, 정점의 개수, 간선의 개수
vector<int> graph[MAX];
int visited[MAX];

void input() {
	cin >> V >> E;
		
	/*-------그래프 정보 입력------*/
	for (int i = 0; i < E; i++) {
		int f, s;
		cin >> f >> s;
		graph[f].push_back(s);
		graph[s].push_back(f);
	}
		
}

/*-----------큐를 이용한 넓이 우선 탐색--------------*/
void BFS(int start) {
	queue<int> Q;
	int color = RED;	//시작 노드의 default 색상은 RED

	visited[start] = color;
	Q.push(start);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		if (visited[now] == RED)	color = BLUE;
		else if (visited[now] == BLUE)	color = RED;

		int gsize = graph[now].size();
		for (int i = 0; i < gsize; i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				visited[next] = color;
				Q.push(next);
			}
		}
	}
}

/*-----------재귀를 이용하는것이 가장 세련되게 푸는것-------------*/
void dfs(int start) {
	if (!visited[start]) {
		visited[start] = RED;
	}

	int gsize = graph[start].size();
	for (int i = 0; i < gsize; i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			if (visited[start] == RED) {
				visited[next] = BLUE;
			}
			else if (visited[start] == BLUE) {
				visited[next] = RED;
			}
			dfs(next);
		}
	}
}

/*------------------이분 그래프 증명----------------------*/
bool isBipartiteGraph() {
	for (int i = 0; i < V; i++) {
		int gsize = graph[i].size();
		for (int j = 0; j < gsize; j++) {
			int next = graph[i][j];	
			//현재 노드와 바로 다음 노드가 성질이 같으면 이분 그래프 오류
			if (visited[i] == visited[next])	return 0;			
		}
	}
	return 1;
}

int main()
{
	cin >> K;
	while (K--) {
		input();

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				BFS(i);
				//DFS(i);
			}
		}

		if (isBipartiteGraph())	cout << "YES\n";
		else					cout << "NO\n";

		for (int i = 0; i <= V; i++) {
			graph[i].clear();
		}
		
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
