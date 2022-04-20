#pragma once

#pragma warning(disable: 4996)
#include <iostream>
#include "declspec.h"	//DLL을 import 시켜주기 위한 전처리기 세팅
//#define _CRT_SECURE_NO_WARNINGS	//혹시 모를 printf scanf에 대한 C4996 에러 방지용

//해결
class Q1197 {
	/*
	최소스패닝 트리(기본)
	https://www.acmicpc.net/problem/1197
	#크루스칼알고리즘 #프림
	*/
	typedef struct edge {
		int from, to, val;

		edge(int _from, int _to, int _val) {
			this->from = _from;
			this->to = _to;
			this->val = _val;
		}
		//정렬을 위해 오버로딩
		bool operator<(edge const& e) {
			return val < e.val;
		}
	};


	int V, E;
	
	int* parent;	//kruskal
	
	//E의 수가 적다면 kruskal 많다면 prim을 사용하는 것이 효율적
	public:
		//kruskal
		int Find(int from);
		void Union(int x, int y);
		int kruskal_solution();
				
		//prim(우선순위 큐를 사용하여 방문할 수 있는 정점중 가중치가 가장 낮은 정점으로 이동
		// prim은 ElogV의 시간 복잡도)
		long long prim_solution();

		DECLSPEC void start();
};

class Q13023 {
	/*
	ABCDE
	https://www.acmicpc.net/problem/13023
	#그래프이론 #그래프탐색 #DFS
	*/

};

class Q2573 {
	/*
	https://www.acmicpc.net/problem/2573
	#구현 #그래프이론 #그래프탐색 #DFS #BFS
	*/
	int N, M;
	int map[300][300];
	int map_buf[300][300];

	bool visited[300][300];
	std::pair<int, int> dir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

public:
	void input();
	int check();
	void melt();
	int solution();
	DECLSPEC void start();
};

class Q2583 {
	/*
	https://www.acmicpc.net/problem/2583
	#그래프이론 #그래프탐색 #BFS #DFS
	*/
	int M, N, K, area_size;
	bool map[101][101];
	bool visited[101][101];
	std::pair<int, int> dir_yx[4] = { {1,0},{-1,0},{0,1},{0,-1} };

public:
	void input();
	void DFS(std::pair<int, int> node);
	void BFS(std::pair<int, int> start);
	void solution();
	DECLSPEC void start();
};

//미해결

