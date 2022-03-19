/*
�ּ� ���д� Ʈ��
https://www.acmicpc.net/problem/1197

����
�׷����� �־����� ��, �� �׷����� �ּ� ���д� Ʈ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ּ� ���д� Ʈ����, �־��� �׷����� ��� �������� �����ϴ� �κ� �׷��� �߿��� �� ����ġ�� ���� �ּ��� Ʈ���� ���Ѵ�.

�Է�
ù° �ٿ� ������ ���� V(1 �� V �� 10,000)�� ������ ���� E(1 �� E �� 100,000)�� �־�����. ���� E���� �ٿ��� �� ������ ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. �̴� A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ� �ִٴ� �ǹ��̴�. C�� ������ ���� ������, ������ 1,000,000�� ���� �ʴ´�.

�׷����� ������ 1������ V������ ��ȣ�� �Ű��� �ְ�, ������ �� ���� ���̿� ��ΰ� �ִ�. �ּ� ���д� Ʈ���� ����ġ�� -2,147,483,648���� ũ�ų� ����, 2,147,483,647���� �۰ų� ���� �����͸� �Է����� �־�����.

���
ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.

���� �Է� 1
3 3
1 2 1
2 3 2
1 3 3
���� ��� 1
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


//ũ�罺Į �˰���
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
	//�⺻����
	void Q1197_init_kruskal() {
		Q1197_res = 0;
		//�θ� �ڱ� �ڽ����� �ʱ�ȭ
		for (int i = 1; i <= V; i++) {
			Q1197_parent[i] = i;
		}
	}	

	//���ε�
	int Q1197_find(int u) {
		if (u == Q1197_parent[u])	return u;
		return Q1197_parent[u] = Q1197_find(Q1197_parent[u]);
	}

	//���Ͽ�
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
//ũ�罺Į
void Q1197_kruskal_solution() {
	Q1197_kruskal ks_s;
	scanf("%d %d", &ks_s.V, &ks_s.E);

	ks_s.Q1197_init_kruskal();

	//�׷��� ����
	for (int i = 0; i < ks_s.E; i++) {
		kruskal ks;
		scanf("%d %d %d", &ks.from, &ks.to, &ks.val);
		ks_s.Q1197_edge.push_back(ks);
	}
	//ũ�罺Į �˰��� ���� ������ �������� ����(�ּ� ���д�)
	std::sort(ks_s.Q1197_edge.begin(), ks_s.Q1197_edge.end(), Q1197_comp);

	for (int i = 0; i < ks_s.E; i++)
	{
		ks_s.Q1197_union(ks_s.Q1197_edge[i].from, ks_s.Q1197_edge[i].to);

		if (ks_s.Q1197_check)
			ks_s.Q1197_res += ks_s.Q1197_edge[i].val;
	}

	std::cout << ks_s.Q1197_res;
}


//����
void Q1197_prim(int start) {
	Q1197_visited[start] = true;

	std::priority_queue<Q1197_pii, std::vector<Q1197_pii>, std::greater<Q1197_pii>> pq;

	//1�� ������ �������� �Ѵ�
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