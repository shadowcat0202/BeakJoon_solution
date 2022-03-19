#include <iostream>

using namespace std;

const int INF = 1000000;

int N;	//시험장 수
int B, C;
int  A[INF];

long long minSupervisor(void) {
	long long total = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		total++;
		if (A[i] > 0) {
			total += (A[i] % C == 0) ? (A[i] / C) : (A[i] / C + 1);
		}
	}
	return total;
}
int main(void){
	cin >> N;
	if (N < 1 || N > INF)
		exit(-1);
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	cin >> B >> C;
	if (B<1 || B>INF || C<1 || C>INF) {
		exit(-1);
	}
	cout << minSupervisor();
	
	return 0;
}