/*
문제
    +---+
    | D |
+---+---+---+---+
| E | A | B | F |
+---+---+---+---+
    | C |
    +---+
주사위는 위와 같이 생겼다. 주사위의 여섯 면에는 수가 쓰여 있다. 
위의 전개도를 수가 밖으로 나오게 접는다.

A, B, C, D, E, F에 쓰여 있는 수가 주어진다.

지민이는 현재 동일한 주사위를 N^3개 가지고 있다. 
이 주사위를 적절히 회전시키고 쌓아서, N×N×N크기의 정육면체를 만들려고 한다. 
이 정육면체는 탁자위에 있으므로, 5개의 면만 보인다.

N과 주사위에 쓰여 있는 수가 주어질 때, 보이는 5개의 면에 쓰여 있는 수의 합의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 
둘째 줄에 주사위에 쓰여 있는 수가 주어진다. 위의 그림에서 A, B, C, D, E, F에 쓰여 있는 수가 차례대로 주어진다. 
N은 1,000,000보다 작거나 같은 자연수이고, 쓰여 있는 수는 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

입력 형태
N
A B C D E F

예제 입력 1
2
1 2 3 4 5 6
예제 출력 1
36

예제 입력 2
3
1 2 3 4 5 6
예제 출력 2
69

예제 입력 3
1000000
50 50 50 50 50 50
예제 출력 3
250000000000000

예제 입력 4
10
1 1 1 1 50 1
예제 출력 4
500
*/

#include <iostream>
#include <algorithm>
#define MIN(a,b) (a < b ? a:b)

long long Q1041_solution() {
    int dice[6]={0,0,0,0,0,0}, min[3] = { 0,0,0 };
    long long N, result = 0, dice_side[3];

    std::cin >> N;
    for (int i = 0; i < 6; i++)  std::cin >> dice[i];

    if (N == 1) {
        std::sort(dice, dice + 6);
        for (int i = 0; i < 5; i++) result += dice[i];
    }
    else {
        for (int i = 0; i < 3; i++) {
            dice[i] = MIN(dice[i], dice[5 - i]);
        }

        std::sort(dice, dice + 3);

        //밖으로 보이는 면의 개수에 따른 최소값       
        min[2] = dice[0] + dice[1] + dice[2];        
        min[1] = dice[0] + dice[1];
        min[0] = dice[0];

        //밖으로 보이는 면의 개수
        dice_side[2] = 4;
        dice_side[1] = 4 * ((N - 1) + (N - 2));
        dice_side[0] = (N - 1) * (N - 2) * 4 + (N - 2) * (N - 2);

        for (int i = 0; i < 3; i++) {
            result += dice_side[i] * min[i];
        }
    }
    return result;

}

void Q1041() {
    std::cout << Q1041_solution();
}