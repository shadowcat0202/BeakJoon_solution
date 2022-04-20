#include <iostream>
#define MAX 1001
#define div 10007
using namespace std;

int d[MAX];

int dp_1(int n) {
	if (n <= 1)	return 1;
	else if (n == 2)	return 2;

	if (d[n] != 0) {
		return d[n];
	}
	else {
		d[n] = (dp_1(n - 1) + dp_1(n - 2)) % div;
		return d[n];
	}
}

int dp_2(int n) {
	if (n <= 1)	return 1;
	else if (n == 2)	return 3;
	else {
		d[n] = (dp_2(n - 1) + 2 * dp_2(n - 2)) % div;
		return d[n];
	}
}


int main() {
	int N = 0;
	cin >> N;
	cout << dp_2(N);
}