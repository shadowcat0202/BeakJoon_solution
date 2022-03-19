/*#include <iostream>

using namespace std;

const int MAX = 100 + 1;

int map[MAX][MAX];
int N,L,result = 0;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
void Horizon(int y, int x) {

	int sidelevel;
	for (int i = 1; i < L; i++) {
		map[y][x]
	}

	
}
void Vertical() {

}



int main() {
	int c,ans;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < n; j++)
			map[i + n][j] = map[j][i];
	for (int i = 0; i < N * 2; i++) {
		c = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) c++;
			else if (map[i][j] + 1 == map[i][j + 1] && c >= 1) c = 1;
			else if (map[i][j] - 1 == a[i][j + 1] && c >= 0) c = -1 + 1;
			else break;
		}
		if (j == n - 1 && c >= 0) ans++;
	}
	printf("%d", ans);
	return 0;
	return 0;
}
*/
#include <cstdio>
#include <iostream>
#define endl "\n"

using namespace std;
int main() {
	int n, l, ans = 0, i, j, c;
	short a[200][100];
	scanf_s("%d %d", &n, &l);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf_s("%hd", &a[i][j]);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i + n][j] = a[j][i];

	cout << endl;

	for (i = 0; i < n*2; i++) {
		for (j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
			


	for (i = 0; i < n * 2; i++) {
		c = 1;
		for (j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) c++;
			else if (a[i][j] + 1 == a[i][j + 1] && c >= l) c = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && c >= 0) c = -l + 1;
			else break;
		}
		if (j == n - 1 && c >= 0) ans++;
	}
	printf("%d", ans);
	return 0;
}
