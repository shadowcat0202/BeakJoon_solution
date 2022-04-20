#include <iostream>
#define endl "\n"
#define MAX 1000 + 1
#define MOD 1000000003
using namespace std;

int N, K;
long long dp[MAX][MAX];

void input() {
	//입력
	cin >> N;
	cin >> K;

}

void solution() {
	//풀이
	for (int i = 0; i <= 3; i++) {
		dp[i][1] = i;
	}
	for (int i = 4; i <= N; i++) {
		int maxchoos = i / 2;
		for (int c = 1; c <= maxchoos; c++) {
			if (c == 1)
				dp[i][c] = i;
			else {
				dp[i][c] = (dp[i - 2][c - 1] + dp[i - 1][c]) % MOD;
			}
		}

	}

}

int main()
{
	input();
	solution();
	
	cout << dp[N][K] << endl;
}