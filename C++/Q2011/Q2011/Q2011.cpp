#include <iostream>
#include <string>
#define endl "\n"
#define MAX 5000 + 1
#define MODUL 1000000

using namespace std;

int N, len;
int arr[MAX];
int DP[MAX];
string s;

void input() {
	cin >> s;
	len = s.length();
	for (int i = 1; i <= len; i++) {
		arr[i] = s[i-1] - '0';
	}
}

void solution() {
	DP[0] = 1;

	if (len == 1 && s[0] == '0') {
		cout << 0 << endl;
		exit(0);
	}

	for (int i = 1; i <= len; i++) {
		int tmp = arr[i] + arr[i - 1] * 10;
		
		if (arr[i] >= 1 && arr[i] <= 9) {
			DP[i] = (DP[i - 1] + DP[i]) % MODUL;
		}
		
		if (i == 1) continue;
		
		if (tmp >= 10 && tmp <= 26) {
			DP[i] = (DP[i - 2] + DP[i]) % MODUL;
		}
	}
	
	cout << DP[len] << endl;
}

int main()
{
	input();
	solution();
}