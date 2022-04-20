#include <iostream>
#include <vector>
#define MAX 1000000
#define MIN 6
using namespace std;

bool prime[MAX + 1];
void isprime() {
    for (int i = 2; i * i <= MAX; i++) {    //절반만 찾을 거임
        if (!prime[i]) {
            for (int j = (i * i) % MAX; j <= MAX; j += i) {
                prime[j] = true;
            }
        }
    }
}

int Goldbach(int a) {
    while (true) {
        int n;
        if (a == 0) break;
        for (int i = 2; i <= MAX; i++) {
            if (!prime[i]) {
                int  j = n - i;
                if (!prime[j]) {
                    printf("%d = %d + %d",n,i,j);
                    break;
                }
            }
        }
        //입력된 수 보다 작은 바로 다음의 소수 찾는 방법?
    }   
}


int main()
{
    int N;
    cin >> N;
    isprime();
    Goldbach(N);
}
