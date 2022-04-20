#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

int spincount = 0;

int btWordDis(char a, char b) {
    int dis = abs(a - b);
    if (dis > 13) {
        return 26 - dis;
    }
    else {
        return dis;
    }}

void solution() {
    //글자를 만드는 원판을 돌렸을 때 최소로 걸리는 시간
    string word;
    cin >> word;

    spincount += btWordDis('A', word[0]);
    for (int i = 0; i < word.length()-1; i++) {
        spincount += (btWordDis(word[i], word[i + 1]));
    }
    cout << spincount << endl;
}

int main()
{
    solution();
    return 0;
}