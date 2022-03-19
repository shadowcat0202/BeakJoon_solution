#include <iostream>
#include <string>
#define MAX 10000 + 1
#define endl "\n"

using namespace std;

int N;  //와인잔의 개수
int W[MAX];
int D[MAX];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
}
int max(int a, int b, int c) {
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

void solution() {
    /*
        1.일렬로 있는 와인잔에서 와인잔을 선택하면 그 잔에 들어있는 와인은 전부 마시고 제자리에 두어야한다
        2.연속으로 놓여있는 3잔은 마실수 없다.
        3.각 와인잔의 내용물의 양이 주어졌을때 최대로 마실수 있는 양은?
    */

    D[1] = W[1];
    for (int i = 1; i <= N; i++) {
        if (i == 2) {
            D[2] = W[1] + W[2];
        }
        if (i > 2) {
            D[i] = max(D[i - 1], D[i - 2], D[i - 3] + W[i - 1]) + W[i];
        }
    }

    cout << D[N] << endl;


}

int main()
{
    input();
    solution();
}