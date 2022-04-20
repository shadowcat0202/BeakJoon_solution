#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 25
using namespace std;

int D[MAX];
int array[MAX];

int ApartMent[MAX][MAX];
int N, room;

// 위쪽부터 시계방향
pair<int, int> dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };


void DFS(int f, int h) {
    pair <int, int> npos;
    ApartMent[f][h] = -1;
    room++;
    for (int i = 0; i < 4; i++) {
        npos.first = f + dir[i].first;  //층
        npos.second = h + dir[i].second;    //호
        if (ApartMent[npos.first][npos.second] == 1) {
            DFS(npos.first, npos.second);
        }
    }

}

void findDnagi() {
    int d = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ApartMent[i][j] == 1) {
                room = 0;
                DFS(i, j);
                D[d] = room;
                d++;
            }
        }
    }

    cout << d << "\n";
    sort(D, D + d);
    for (int k = 0; k < d; k++) {
        cout << D[k] << "\n";
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf_s("%1d", &ApartMent[i][j]);
        }
    }
}
int main()
{
    input();
    findDnagi();
}

