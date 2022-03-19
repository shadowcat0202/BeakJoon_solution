#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 1000 + 1
using namespace std;

int arr[MAX], dp[MAX];
int N, cnt = 1;

void input() {
	//입력
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
}

void solution() {
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < N; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
			cnt = max(cnt, dp[i]);
		}
	}
}

int main()
{
	input();
	solution();
	cout << cnt << endl;

}