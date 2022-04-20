#include <iostream>
#define endl "\n"
#define MAX 2000 + 1
using namespace std;

int N, M;
int arr[MAX];
bool d[MAX][MAX];

void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << d[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	scanf_s("%d", &N);

	for(int i = 1; i <= N; i++)	
		scanf_s("%d", &arr[i]);



	for (int i = 1; i <= N; i++)	
		d[i][i] = true;
	cout << "거리 0\n";
	show();

	for (int i = 1; i < N; i++)
		if (arr[i] == arr[i + 1])
			d[i][i + 1] = true;
	cout << "거리 1\n";
	show();

	
	for (int i = 2; i < N; i++) 
		for (int j = 1; j <= N - i; j++) 
			if (arr[j] == arr[i + j] && d[j + 1][i + j - 1])
				d[j][i + j] = true;

	cout << "거리 2이상\n";
	show();
	
	scanf_s("%d", &M);
	while (M--) {
		int s, e;
		scanf_s("%d %d", &s, &e);
		printf("%d\n", d[s][e]);
	}


		
	
}