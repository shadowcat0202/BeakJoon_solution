#include "pch.h"
#include "탐색.h"
#include <vector>
#include <queue>
#include <algorithm>


//struct Q1197::edge;

int Q1197::Find(int from) {
	if (from == parent[from])	return from;
	return parent[from] = Find(parent[from]);
}
void Q1197::Union(int from, int to) {
	from = Find(from);
	to = Find(to);

	parent[to] = from;
}

int Q1197::kruskal_solution() {
	parent = new int[10001];
	std::vector<edge> edge_v;
	scanf("%d %d", &V, &E);

	//초기화 작업
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int f, t, v;
		scanf("%d %d %d", &f, &t, &v);
		edge_v.push_back(edge(f, t, v));
	}
	
	std::sort(edge_v.begin(), edge_v.end());	//간선의 가중치 기준 오름차순
		
	int answer = 0;
	//auto를 사용함으로서 초치값을 설정하지 않아서 발생하는 정확성 문제를 원천 봉쇄 가능 
	//형식단축(type shortcut)이라고 부르는 것과 관련된 문제를 피할 수 있다.
	//형식 불일치 문제를 줄일 수 있다.
	for (edge n : edge_v) {	
		if (Find(n.from) != Find(n.to)) {
			Union(n.from, n.to);
			answer += n.val;
		}
	}
	delete[] parent;
	return answer;
}

long long Q1197::prim_solution() {
	//new type[]();	//초기화 작업 있음
	//new type[];	//초기화 작업 없음
	int* visited = new int[10001]();
	std::vector<std::pair<int, int>>* edge_v = new std::vector<std::pair<int, int>>[10001]();

	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge_v[a].push_back(std::make_pair(c, b));
		edge_v[b].push_back(std::make_pair(c, a));
	}
	long long ans = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push(std::make_pair(0, 1));

	while (!pq.empty()) {
		std::pair<int, int> cur = pq.top();
		pq.pop();

		if (visited[cur.second])	continue;

		visited[cur.second] = 1;
		ans += cur.first;
		for (int i = 0; i < edge_v[cur.second].size(); i++) {
			if (!visited[edge_v[cur.second][i].second]) {
				pq.push(edge_v[cur.second][i]);
			}
		}
	}
	delete[] visited;
	delete[] edge_v;
	return ans;
}

void Q1197::start() {	
	printf("%d\n", prim_solution());
}