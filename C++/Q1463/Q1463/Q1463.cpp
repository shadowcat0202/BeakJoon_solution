#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 1000000 + 1

using namespace std;

int N;
int DP[MAX];

void solution() {
	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)	DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)	DP[i] = min(DP[i], DP[i / 3] + 1);
	}
}

int main()
{
	cin >> N;

	solution();

	cout <<DP[N] << endl;
}