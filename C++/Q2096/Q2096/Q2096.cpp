#include<iostream>

#define endl "\n"
#define MAX 100001
using namespace std;

int N;
int MAP[MAX][3];
int Max_DP[2][3];
int Min_DP[2][3];

int Bigger(int A, int B) { if (A > B) return A; return B; }
int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void Solution()
{
    Min_DP[0][0] = Max_DP[0][0] = MAP[1][0];
    Min_DP[0][1] = Max_DP[0][1] = MAP[1][1];
    Min_DP[0][2] = Max_DP[0][2] = MAP[1][2];

    for (int i = 2; i <= N; i++)
    {
        Max_DP[1][0] = MAP[i][0] + Bigger(Max_DP[0][0], Max_DP[0][1]);
        Max_DP[1][1] = MAP[i][1] + Bigger(Max_DP[0][0], Bigger(Max_DP[0][1], Max_DP[0][2]));
        Max_DP[1][2] = MAP[i][2] + Bigger(Max_DP[0][1], Max_DP[0][2]);

        Max_DP[0][0] = Max_DP[1][0];
        Max_DP[0][1] = Max_DP[1][1];
        Max_DP[0][2] = Max_DP[1][2];

        Min_DP[1][0] = MAP[i][0] + Min(Min_DP[0][0], Min_DP[0][1]);
        Min_DP[1][1] = MAP[i][1] + Min(Min_DP[0][0], Min(Min_DP[0][1], Min_DP[0][2]));
        Min_DP[1][2] = MAP[i][2] + Min(Min_DP[0][1], Min_DP[0][2]);

        Min_DP[0][0] = Min_DP[1][0];
        Min_DP[0][1] = Min_DP[1][1];
        Min_DP[0][2] = Min_DP[1][2];
    }

    int Max_Value = Bigger(Max_DP[0][0], Bigger(Max_DP[0][1], Max_DP[0][2]));
    int Min_Value = Min(Min_DP[0][0], Min(Min_DP[0][1], Min_DP[0][2]));

    cout << Max_Value << " " << Min_Value << endl;
}


int main(void){
    Input();
    Solution();
    return 0;
}