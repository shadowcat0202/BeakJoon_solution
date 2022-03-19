#include <iostream>
#define endl "\n"
#define MAX 11
using namespace std;

int N;
int sum[MAX];

int method() {
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	for (int i = 4; i <= N; i++) {
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
	return sum[N];
}

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> N;
		cout << method() << endl;
	}
	return 0;
}