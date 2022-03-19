#include "pch.h"
#include "Ž��.h"
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

	//�ʱ�ȭ �۾�
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int f, t, v;
		scanf("%d %d %d", &f, &t, &v);
		edge_v.push_back(edge(f, t, v));
	}
	
	std::sort(edge_v.begin(), edge_v.end());	//������ ����ġ ���� ��������
		
	int answer = 0;
	//auto�� ��������μ� ��ġ���� �������� �ʾƼ� �߻��ϴ� ��Ȯ�� ������ ��õ ���� ���� 
	//���Ĵ���(type shortcut)�̶�� �θ��� �Ͱ� ���õ� ������ ���� �� �ִ�.
	//���� ����ġ ������ ���� �� �ִ�.
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
	//new type[]();	//�ʱ�ȭ �۾� ����
	//new type[];	//�ʱ�ȭ �۾� ����
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