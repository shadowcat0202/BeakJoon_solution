#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
using namespace std;

int N;
int MAP[MAX][MAX], A[MAX][MAX];

bool BFS_Visit[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void showAnswer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {		
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}

void BFS(int a)
{
	queue<int> Q;
	Q.push(a);
	while (Q.empty() == 0)
	{
		int P = Q.front();
		Q.pop();

		for (int i = 0; i < N; i++)
		{
			if (MAP[P][i] == 1 && BFS_Visit[i] == false)
			{
				Q.push(i);
				BFS_Visit[i] = true;
				A[a][i] = 1;
			}
		}
	}
}

int main()
{
	input();

	for (int i = 0; i < N; i++) {
		BFS(i);
		memset(BFS_Visit, false, sizeof(BFS_Visit));
	}
	showAnswer();
}
