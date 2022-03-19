#include <iostream>
#include <cstring>	//memset
#define MAX 100000 + 1
using namespace std;

int T, N, cnt; 
int student[MAX];
bool visited[MAX];
bool finish[MAX];



void input() {
	int buf;
	cin >> N;
	for (int s = 0; s < N; s++) {
		cin >> buf;
		student[s] = buf - 1;

	}
}

void DFS(int num) {
	visited[num] = true;
	int next = student[num];

	if (!visited[next])	DFS(next);	//방문한적 없는 경우
	else if (!finish[next]) {	//방문은 했지만 싸이클이 끝나지 않은경우
		for (int i = next; i != num; i = student[i])	cnt++;
		cnt++;
	}
	finish[num] = true;

}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {	//테스트 케이스
		memset(visited, false, sizeof(visited));
		memset(finish, false, sizeof(finish));
		
		input();
		cnt = 0;
		
		for (int j = 0; j < N; j++) {
			if (!visited[j])	DFS(j);
		}

		cout << N - cnt << "\n";
	}
}