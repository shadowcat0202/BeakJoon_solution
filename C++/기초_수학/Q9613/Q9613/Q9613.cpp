#include <iostream>
#define MAX 100

using namespace std;

int arr[MAX];

int GCD(int a, int b) {
    if (a % b == 0)    return b;
    return GCD(a, a % b);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for(int i = 0; i < N; i++)
            cin >> arr[i];

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                sum += GCD(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }
}
