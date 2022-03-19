#include <iostream>
#define endl "\n"
#define MAX 1000 + 1
#define DIV 10007

using namespace std;

int N;
int DP[MAX];

int main()
{
	cin >> N;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = ( DP[i - 2] + DP[i - 1] ) % DIV;
	}
	cout << DP[N] << endl;
}
