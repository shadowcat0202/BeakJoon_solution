#include <iostream>
#define endl "\n"

using namespace std;

const int MAX = 20 + 1;

int N, ans  = 1000;
int S[MAX][MAX];
int Ssum[MAX][MAX];
bool pick[MAX];

int min(int a, int b) {
    return ((a < b) ? a : b);
}

void showmatrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << Ssum[i][j] << " ";
        }
        cout << endl;
    }
}

void combi(int cnt, int cur) {
    if (cnt == N / 2) {
        int a = 0, b = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (pick[i] && pick[j]) {
                    a += Ssum[i][j];
                }
                else if (!pick[i] && !pick[j]) {
                    b += Ssum[i][j];
                }
            }           
        }        
        ans = min(ans, abs(a - b));
    }
    for (int i = 0; i < N; i++) {
        if (pick[i] == false && i > cur) {
            pick[i] = true;
            combi(cnt + 1, i);
            pick[i] = false;
        }
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            Ssum[i][j] = S[i][j] + S[j][i];
        }
    }
}


int main()
{
    input();
    combi(0, 0);
    cout << ans << endl;
    return 0;
}