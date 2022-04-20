#include <iostream>
#include <algorithm>

#define endl "\n"
#define MAX 500 + 1

using namespace std;

int N;	//삼각형의 크기
int DP[MAX];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main()
{
	cin >> N;

	int buf[MAX];
	for (int i = 0; i < N; i++) {		//행 수
		for (int j = 0; j <= i; j++) {	//열 수	
			cin >> buf[j];
			if (i == 0){	//피라미드의 가장 위
				DP[0] = buf[j];
				continue;
			}			

			if (j == 0)	//가장 앞줄
				buf[j] = DP[0] + buf[j];
			else if (j == i)	//가장 뒷줄
				buf[j] = DP[j - 1] + buf[j];
			else {
				buf[j] = max(DP[j - 1], DP[j]) + buf[j];
			}
		}
		copy(buf, buf + N, DP);		
	}
	int m = 0;
	for (int i = 0; i < N; i++) {
		(DP[i] > m) ? m = DP[i] : m = m;
	}

	cout << m << endl;


}