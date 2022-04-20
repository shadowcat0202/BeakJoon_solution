#include <iostream>
#define endl "\n"
#define MAX 90 + 1

typedef long long ll;	
/*	long long	= 8byte	( abs(	9,223,372,036,854,775,808) )
	int			= 4byte	( abs(				2,147,483,647) )
	N
*/

using namespace std;

ll N;
ll DP[MAX];

void input() {
	cin >> N;
}

void solution() {
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
}
void solve() {
	input();
	solution();
	cout << DP[N] << endl;
}

int main()
{
	solve();	
}
