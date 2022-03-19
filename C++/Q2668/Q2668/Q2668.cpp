#include <iostream>
#define endl "\n"
using namespace std;

const int MAX = 100 + 1;

int N,cnt;
int node[MAX];
bool visited[MAX], cycle[MAX];

void input() {

}

bool DFS(int startNum, int nodeNum) {
    if (visited[nodeNum])    return false;

    visited[nodeNum] = true;

    if (startNum == nodeNum || DFS(startNum, node[nodeNum])) {
        cnt++;
        cycle[nodeNum] = true;
        return true;
    }
    return false;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> node[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[j] = cycle[j];
        }
        DFS(i, node[i]);
    }

    cout << cnt << endl;
    for (int i = 1; i <= N; i++) {
        if (cycle[i]) {
            cout << i << endl;
        }   
    }
    return 0;
}