//문제
/*
https://www.acmicpc.net/problem/1028

다이아몬드 광산은 0과 1로 이루어진 R행*C열 크기의 배열이다.

다이아몬드는 1로 이루어진 정사각형의 경계선을 45도 회전시킨 모양이다. 
크기가 1, 2, 3인 다이아몬드 모양은 다음과 같이 생겼다.

size 1:    size 2:    size 3:
                         1
              1         1 1
   1         1 1       1   1
              1         1 1
                         1
다이아몬드 광산에서 가장 큰 다이아몬드의 크기를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 R과 C가 주어진다. R과 C는 750보다 작거나 같은 자연수이다. 
둘째 줄부터 R개의 줄에는 다이아몬드 광산의 모양이 주어진다.

출력
첫째 줄에 다이아몬드 광산에서 가장 큰 다이아몬드의 크기를 출력한다. 
만약 다이아몬드가 없을 때는 0을 출력한다.
*/

//예제
/*
예제 입력 1
5 5
01100
01011
11111
01111
11111
예제 출력 1
3
*/


#pragma warning(disable:4996)
#include <iostream>
#define Q1028_MAX 750

enum { rb, lb };

int Q1028_dp[Q1028_MAX + 1][Q1028_MAX + 1][2];  //좌측아래 우측아래
int Q1028_R, Q1028_C;

bool Q1028_is_outbound(int r, int c) {
    return r < 0 || c < 0 || r >= Q1028_R || c >= Q1028_C;
}

void Q1028() {
    int res = 0;
    scanf("%d %d", &Q1028_R, &Q1028_C);

    for (int i = 0; i < Q1028_R; i++) {
        char buf[Q1028_MAX];
        scanf("%s", &buf);
        for (int j = 0; j < Q1028_C; j++) {
            Q1028_dp[i][j][rb] = Q1028_dp[i][j][lb] = buf[j] - '0';
        }        
    }

    //밑에서 위로 올라가면서 DP 갱신
    for (int i = Q1028_R - 1; i >= 0; i--) {
        for (int j = 0; j < Q1028_C; j++) {
            if (!Q1028_is_outbound(i,j)) {
                Q1028_dp[i][j][rb] *= 1 + Q1028_dp[i + 1][j + 1][rb]; //오른쪽 밑으로 대각선
                Q1028_dp[i][j][lb] *= 1 + Q1028_dp[i + 1][j - 1][lb]; //왼쪽 밑으로 대각선
            }
        }
    }


    int t;
    for (int i = 0; i < Q1028_R; i++) {
        for (int j = 0; j < Q1028_C; j++) {
            for (int t = Q1028_dp[i][j][lb]-1; t >= res; t--) {
                //rc에서의 lb길이와 rb의 길이가 같아야 하며 왼쪽 밑으로 내려간 위치에서의 
                if (Q1028_dp[i][j][rb] >= t + 1 && Q1028_dp[i + t][j - t][rb] >= t + 1 && Q1028_dp[i + t][j + t][lb] >= t + 1) {
                    res = t + 1;
                }
            }
        }
    }
    printf("%d", res);

}