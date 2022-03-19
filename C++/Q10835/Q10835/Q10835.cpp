#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 2000 + 1

using namespace std;

int N;
int L[MAX], R[MAX];
int dp[MAX][MAX];

void input() {
	//입력
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> L[i];
	for (int i = 0; i < N; i++)	cin >> R[i];

}

int step(int l, int r) {
	//풀이
	/*
	왼쪽카드만 통에 버릴수 있고 왼쪽오른쪽 둘다 통에 버릴수 있다. (점수는 없다)
	if(오른쪽 < 왼쪽) drop 오른쪽 -> 카드에 점수 획득
	한쪽이라도 남은 카드가 없으면 게임 종료
	*/
	if (r == N || l == N) return 0;
	if (dp[l][r] != -1)	return dp[l][r];

	dp[l][r] = max(step(l + 1, r), step(l + 1, r + 1));	//점수 없음
	if (L[l] > R[r]) {
		dp[l][r] = max(dp[l][r], step(l,r+1) + R[r]);
	}
	return dp[l][r];
}

int main()
{
	input();
	memset(dp, -1, sizeof(dp));
	cout << step(0, 0);
}