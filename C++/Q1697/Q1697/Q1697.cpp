#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int N, K;	//N수빈 K동생
int bfsCount;	//이동 횟수
int visited[MAX] = { 0, };
queue<int> q;

int BFS() {
	q.push(N);
	visited[N] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		
		if (p == K)	return visited[p] - 1;
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;	//몇번만에 이 좌표에 올수 있는가?
			q.push(p - 1);
		}
		if (p + 1 <= MAX && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		if (2 * p <= MAX && visited[2 * p] == 0) {
			visited[2*p] = visited[p] + 1;
			q.push(2*p);
		}
	}
}

int main()
{
	cin >> N >> K;
	cout << BFS();
}

