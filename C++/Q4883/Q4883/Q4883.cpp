#include <iostream>

#include <algorithm>

using namespace std;
int a[100005][3], b[100005][3];
int main(void) {
	int count = 1;
	while (true) {
		int n, temp, temp2;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < 3; t++) {
				cin >> a[i][t];
				b[i][t] = a[i][t];
			}
		}
		b[0][2] += b[0][1];
		b[1][0] += b[0][1];
		b[1][1] += min(min(b[0][1], b[1][0]), b[0][2]);
		b[1][2] += min(min(b[1][1], b[0][1]), b[0][2]);
		for (int i = 2; i < n; i++) {
			for (int t = 0; t < 3; t++) {
				if (t == 0)
					b[i][t] += min(b[i - 1][t], b[i - 1][t + 1]);
				else if (t == 1)
					b[i][t] += min(min(b[i - 1][t], b[i - 1][t + 1]), min(b[i - 1][t - 1], b[i][t - 1]));
				else if (t == 2)
					b[i][t] += min(min(b[i - 1][t - 1], b[i - 1][t]), b[i][t - 1]);
			}
		}
		cout << count << ". " << b[n - 1][1] << endl;
		count++;
	}
	return 0;
}