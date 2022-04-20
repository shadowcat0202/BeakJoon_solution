#include <iostream>
#include <queue>
#include <cmath>
#define MAX 1000000

using namespace std;

int N, K;
int arr[7];
int BIG;

void input() {	
	cin >> N >> K; 
	int buf = 10000;
	for (int i = 0; i < 7; i++) {
		if (buf < 10) {
			arr[i] = buf;
			break;
		}			
		arr[i] = buf % 10;
		buf /= 10;
	}
}

void BFS() {
	queue<int> Q;
	while (!Q.empty()) {

	}
}

int main()
{
	cout << sizeof(arr) / sizeof(*arr);
}