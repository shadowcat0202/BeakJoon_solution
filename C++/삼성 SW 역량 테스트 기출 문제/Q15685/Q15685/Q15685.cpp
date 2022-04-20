#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int MAX = 100 + 1;

int N;  //커브의 개수
typedef struct {
    int y, x;
}Dir;
Dir moveDir[4] = { {0,1},{-1,0},{0,-1},{1,0} };
bool visited[MAX][MAX];
void input() {

}
int main()
{

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> curve;

        curve.push_back(d);
    }
}
