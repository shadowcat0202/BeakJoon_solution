#include <iostream>
#include <cstring>
#define endl "\n"
#define MAX 16

using namespace std;

const static int INF = 987654321;
int N;
int W[MAX][MAX];
int memo[MAX][1<<MAX];
//풀이
	//dp[current][visited] 
	//	= min(dp[current][visited], tsp(next, visited + next) + w[current][next])
	//visited를 비트마스크 형식으로 작성(visdited 배열로 관리 할경우 시간초과 혹은 메모리 초과가 걸릴수 있다.)

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
}


int tsp(int curr, int visited) {
	int& now = memo[curr][visited];
	if (now != -1)	return now;
	//모든 도시 방문 
	if (visited == (1<<N) - 1) {
		//0번쨰 도시로 돌아옴
		if (W[curr][0] != 0)	return W[curr][0];
		else return INF;
	}

	now = INF;
	for (int i = 0; i < N; i++) {
		if (W[curr][i] && !(visited & (1<<i))) {
			int visit = visited | (1<<i);
			now = min(now, tsp(i, visit) + W[curr][i]);
		}
	}
	return now;
}

int main()
{
	input();
	memset(memo, -1, sizeof(memo));
	cout << tsp(0, 1) << endl;
	return 0;
}