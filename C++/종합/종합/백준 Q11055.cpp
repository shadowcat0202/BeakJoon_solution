/*
����
���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.

���� �Է� 1
10
1 100 2 50 60 3 5 6 7 8
���� ��� 1
113
*/

#include <iostream>
#include <algorithm>
#define endl "\n"
#define Q11055_MAX 1001

int Q11055_arr[Q11055_MAX];
int Q11055_dp[Q11055_MAX];

int Q11055_solution() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> Q11055_arr[i];
		Q11055_dp[i] = Q11055_arr[i];
	}

	int result = 0;
	int big = Q11055_arr[0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (Q11055_arr[i] > Q11055_arr[j]) {
				Q11055_dp[i] = std::max(Q11055_dp[j] + Q11055_arr[i], Q11055_dp[i]);
			}
		}
		result = (Q11055_dp[i] > result) ? Q11055_dp[i] : result;

	}

	return result;

}

void Q11055() {
	std::cout << Q11055_solution() << endl;
}