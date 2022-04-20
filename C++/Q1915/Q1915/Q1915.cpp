#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"
#define MAX 1000 + 1
using namespace std;

int R, C;
bool map[MAX][MAX];
int dp[MAX][MAX];
int ans;

void input() {
	//입력

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string buf;
		cin >> buf;
		for (int j = 0; j < C; j++) {
			map[i][j] = buf[j] - 48;	//문자를 숫자 0이 ASCII 48번
			if (map[i][j] == 1) {
				dp[i][j] = 1;
				ans = 1;
			}
		}
			
	}
		
	
}

void solution() {
	input();
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			if (map[i - 1][j] == 1 && map[i - 1][j - 1] == 1 && map[i][j - 1] == 1) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
				dp[i][j] = min(dp[i][j], dp[i][j - 1]) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	}	
	cout << ans*ans << endl;
}

int main()
{
	solution();
}