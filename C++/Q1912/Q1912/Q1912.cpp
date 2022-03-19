#include <iostream>
#define endl "\n"
#define MAX 100000 + 1
using namespace std;

int N;
int DP[MAX];
int m = -1001;


int BIG(int a, int b) {
	return a > b ? a : b;
}

void solution() {
	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> DP[i];

		DP[i] = BIG(DP[i], DP[i] + DP[i - 1]);
		m = BIG(m, DP[i]);
	}
	cout << m << endl;
}


int main()
{
	solution();
}
