#pragma once

#pragma warning(disable: 4996)
#include <iostream>
#include "declspec.h"	//DLL�� import �����ֱ� ���� ��ó���� ����
//#define _CRT_SECURE_NO_WARNINGS	//Ȥ�� �� printf scanf�� ���� C4996 ���� ������

//�ذ�
class Q1197 {
	/*
	�ּҽ��д� Ʈ��(�⺻)
	https://www.acmicpc.net/problem/1197
	#ũ�罺Į�˰��� #����
	*/
	typedef struct edge {
		int from, to, val;

		edge(int _from, int _to, int _val) {
			this->from = _from;
			this->to = _to;
			this->val = _val;
		}
		//������ ���� �����ε�
		bool operator<(edge const& e) {
			return val < e.val;
		}
	};


	int V, E;
	
	int* parent;	//kruskal
	
	//E�� ���� ���ٸ� kruskal ���ٸ� prim�� ����ϴ� ���� ȿ����
	public:
		//kruskal
		int Find(int from);
		void Union(int x, int y);
		int kruskal_solution();
				
		//prim(�켱���� ť�� ����Ͽ� �湮�� �� �ִ� ������ ����ġ�� ���� ���� �������� �̵�
		// prim�� ElogV�� �ð� ���⵵)
		long long prim_solution();

		DECLSPEC void start();
};

class Q13023 {
	/*
	ABCDE
	https://www.acmicpc.net/problem/13023
	#�׷����̷� #�׷���Ž�� #DFS
	*/

};

class Q2573 {
	/*
	https://www.acmicpc.net/problem/2573
	#���� #�׷����̷� #�׷���Ž�� #DFS #BFS
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
	#�׷����̷� #�׷���Ž�� #BFS #DFS
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

//���ذ�

