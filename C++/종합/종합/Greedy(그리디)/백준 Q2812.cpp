/*
����
N�ڸ� ���ڰ� �־����� ��, ���⼭ ���� K���� ������ ���� �� �ִ� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� K < N �� 500,000)

��° �ٿ� N�ڸ� ���ڰ� �־�����. �� ���� 0���� �������� �ʴ´�.

���
�Է����� �־��� ���ڿ��� K���� ������ �� ���� �� �ִ� ���� ū ���� ����Ѵ�.

���� �Է� 1
4 2
1924
���� ��� 1
94
*/
#include <iostream>
#include <vector>
#include <queue>

void Q2812_solution(){
	int result = 0;
	int N, K;
	std::deque<char> dq;

	std::cin >> N >> K;

	std::string S;
	std::cin >> S;



	for (int i = 0; i < N; i++) {
		while (K && !dq.empty() && dq.back() < S[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(S[i]);
	}	

	for (int i = 0; i < dq.size() - K; i++) {
		std::cout << dq[i];
	}
	
}

void Q2812() {
	Q2812_solution();
}