#include <iostream>
#include <algorithm>
#define endl "\n"


using namespace std;
const int  MAX = 11 + 1;
const int INF = 1000000000 + 1;

int Operand[MAX];
int Operator[4];
int N;
int maxR = -INF, minR = INF;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Operand[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> Operator[i];
	}

}
void DFS(int plu, int sub, int mul, int div, int cnt, int sum) {
	if (cnt == N) {
		maxR = max(maxR, sum);
		minR = min(minR, sum);
	}

	if (plu > 0)
		DFS(plu - 1, sub, mul, div, cnt + 1, sum + Operand[cnt]);
	if (sub > 0)
		DFS(plu, sub - 1, mul, div, cnt + 1, sum - Operand[cnt]);
	if (mul > 0)
		DFS(plu, sub, mul - 1, div, cnt + 1, sum * Operand[cnt]);
	if (div > 0)
		DFS(plu, sub, mul, div - 1, cnt + 1, sum / Operand[cnt]);
	 
}
void solution() {
	//해결 방법
	//A1 ... An까지의 수열과 n-1개의 연산자 Operator(+ - * /)존재
	//수의 순서를 바꿀수 없다
	input();
	DFS(Operator[0], Operator[1], Operator[2], Operator[3], 1,Operand[0]);

	cout << maxR << endl << minR << endl;
}
int main() {
	solution();
	return 0;
}