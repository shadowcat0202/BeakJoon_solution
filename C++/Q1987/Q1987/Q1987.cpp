#include <iostream>
#include <stack>
#include <vector>
#define endl "\n"
using namespace std;

const int MAX = 20 + 1;
int R, C, Rcount = 0;
int dx[4] = { 0,0,-1,1 },
    dy[4] = { -1,1,0,0 };   //상하좌우
char map[MAX][MAX];
bool visited[26];

int Bigger(int A, int B) { if (A > B) return A; return B; }

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
}


void DFS(int x,int y,int cnt) {
    Rcount = Bigger(Rcount, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C)
        {
            if (visited[map[nx][ny] - 'A'] == false)
            {
                visited[map[nx][ny] - 'A'] = true;
                DFS(nx, ny, cnt + 1);
                visited[map[nx][ny] - 'A'] = false;
            }
        }
    }    
}

void solution() {
    input();
    visited[map[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << Rcount << endl;
}
int main()
{
    solution();
    return 0;
}