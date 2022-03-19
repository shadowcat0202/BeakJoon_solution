#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define MAX 31
using namespace std;

int N, M, T;   //서쪽 동쪽 사이트 N <= M, T = 테스트 케이스
long long Result[2][MAX];
bool breakflag = 0;



void solution() {
    //솔루션
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int P = 0;
        //n_C_m
        for (int i = 0; i <= M; i++) {
            Result[0][i] = i;
        }   //초기화

        for (int n = 1; n <= N; n++) {
            for (int i = n; i <= M; i++) {
                Result[1][i] = Result[0][i - 1] + Result[1][i - 1];
                if (n == N && i == M)   breakflag = 1;
                if (breakflag)   break;
            }
            if (breakflag)   break;
            copy(Result[1],Result[1] + 31, Result[0]);
        }

        cout << Result[0][M] << endl;
        breakflag = 0;
    }   
}

int main()
{
    solution();
}