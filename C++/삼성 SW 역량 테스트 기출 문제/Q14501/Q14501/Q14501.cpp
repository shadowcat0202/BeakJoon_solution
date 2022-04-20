#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define max(a,b) (a>b)?a:b

using namespace std;
const int MAX = 15+1;
const int INF = 987654321;
int N;
pair<int,int> counsel[MAX];
int money[MAX];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> counsel[i].first >> counsel[i].second;
    }
}

void show(int c) {
    switch (c) {
        case 1:
            cout << endl;
            for (int i = 1; i <= N; i++) {
                cout << counsel[i].first << "\t";
            }
            cout << endl;
            for (int i = 1; i <= N; i++) {
                cout << counsel[i].second << "\t";
            }
            cout << endl;           
            break;
        case 2:
            for (int i = 1; i <= N; i++) {
                cout << money[i] << "\t";
            }
            cout << endl;
            break;
    }
}

int maxprofit(int day) {
    if (day == N + 1)
        return 0;
    if (day > N + 1)
        return -INF;
    int& result = money[day];
    if (result != -1)
        return result;

    result = 0;
    result += max(counsel[day].second + maxprofit(day + counsel[day].first), maxprofit(day + 1));
    return result;
}

void solution() {
    input();
    memset(money, -1, sizeof(money));
    cout << maxprofit(1) << endl;
    

}

int main()
{
    solution();
    return 0;
}