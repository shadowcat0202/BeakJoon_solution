/*
최소 스패닝 트리
https://www.acmicpc.net/problem/1197

문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

예제 입력 1
3 3
1 2 1
2 3 2
1 3 3
예제 출력 1
3
*/
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


int Q1197_parent[10002];

typedef std::pair<int, int> Q1197_pii;
std::vector<Q1197_pii> Q1197_vc[10001];
bool Q1197_visited[10001];


//크루스칼 알고리즘
struct kruskal {
	int from;
	int to;
	int val;
};
struct Q1197_kruskal {
	
	int V, E;
	int Q1197_res;
	bool Q1197_check;

	std::vector<kruskal> Q1197_edge;
	//기본설정
	void Q1197_init_kruskal() {
		Q1197_res = 0;
		//부모를 자기 자신으로 초기화
		for (int i = 1; i <= V; i++) {
			Q1197_parent[i] = i;
		}
	}	

	//파인드
	int Q1197_find(int u) {
		if (u == Q1197_parent[u])	return u;
		return Q1197_parent[u] = Q1197_find(Q1197_parent[u]);
	}

	//유니온
	void Q1197_union(int u, int v) {
		Q1197_check = false;
		u = Q1197_find(u);
		v = Q1197_find(v);

		if (u == v)	return;

		Q1197_parent[u] = v;
		Q1197_check = true;
	}
};
bool Q1197_comp(kruskal d1, kruskal d2) {
	return d1.val < d2.val;
}
//크루스칼
void Q1197_kruskal_solution() {
	Q1197_kruskal ks_s;
	scanf("%d %d", &ks_s.V, &ks_s.E);

	ks_s.Q1197_init_kruskal();

	//그래프 형성
	for (int i = 0; i < ks_s.E; i++) {
		kruskal ks;
		scanf("%d %d %d", &ks.from, &ks.to, &ks.val);
		ks_s.Q1197_edge.push_back(ks);
	}
	//크루스칼 알고리즘에 의해 간선을 오름차순 정렬(최소 스패닝)
	std::sort(ks_s.Q1197_edge.begin(), ks_s.Q1197_edge.end(), Q1197_comp);

	for (int i = 0; i < ks_s.E; i++)
	{
		ks_s.Q1197_union(ks_s.Q1197_edge[i].from, ks_s.Q1197_edge[i].to);

		if (ks_s.Q1197_check)
			ks_s.Q1197_res += ks_s.Q1197_edge[i].val;
	}

	std::cout << ks_s.Q1197_res;
}


//프림
void Q1197_prim(int start) {
	Q1197_visited[start] = true;

	std::priority_queue<Q1197_pii, std::vector<Q1197_pii>, std::greater<Q1197_pii>> pq;

	//1번 정점을 시작으로 한다
	for (int i = 0; i < Q1197_vc[start].size(); i++) {
		int next = Q1197_vc[start][i].first;
		int nextCost = Q1197_vc[start][i].second;

		pq.push(Q1197_pii(nextCost, next));
	}

	int ans = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int nowCost = pq.top().first;

		pq.pop();

		if (Q1197_visited[now])	continue;

		Q1197_visited[now] = true;

		ans += nowCost;

		for (int i = 0; i < Q1197_vc[now].size(); i++) {
			int next = Q1197_vc[now][i].first;
			int nextCost = Q1197_vc[now][i].second;

			pq.push(Q1197_pii(nextCost, next));
		}
	}
	printf("%d", ans);
}
void Q1197_prim_solution() {
	int V, E;
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		Q1197_vc[from].push_back(Q1197_pii(to, val));
		Q1197_vc[to].push_back(Q1197_pii(from, val));
	}
	Q1197_prim(1);
}
void Q1197() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	//Q1197_kruskal_solution();
	Q1197_prim_solution();
}