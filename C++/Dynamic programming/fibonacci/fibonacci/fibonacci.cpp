#include <iostream>
#define MAX 100
using namespace std;
int D[MAX];

void showdata(int x) {
    cout << "현재 x: " << x << "\n";
    for (int i = 0; i < x; i++) {
        cout << D[i] << " ";
        if (i % 10 == 0) {
            cout << "\n";
        }
    }
    cout << "\n";
}

int fibonacci(int x) {
    if (x <= 2) {
        return 1;
    }
    if (D[x] != 0) {
        return D[x];
    }
    else {
        D[x] = fibonacci(x - 1) + fibonacci(x - 2);
        showdata(x);
        return D[x];
    }
    
}



int main()
{
    printf("%d",fibonacci(30));
}
