/*
����
������û�� ������ ������ �����Կ��� ���ο� ������ �־�����.

������ ���������״� Si�� �����ؼ� Ti�� ������ N���� ������ �־����µ�, 
�ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ؾ� �Ѵ�.

�����, ������ ���� ���Ŀ� ���� ������ ������ �� �ִ�.
(��, Ti �� Sj �� ��� i ������ j ������ ���� ���� �� �ִ�.)

������û ������ �� �񸮸�, �������� ���͵帮��!

�Է�
ù ��° �ٿ� N�� �־�����. (1 �� N �� 200,000)

���� N���� �ٿ� Si, Ti�� �־�����. (1 �� Si < Ti �� 109)

���
���ǽ��� ������ ����϶�.

���� �Է� 1
3
1 3
2 4
3 5
���� ��� 1
2
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int Q11000_solution() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> in_pq;	//��������
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq_r;	//��������
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::pair<int, int> buf;
		std::cin >> buf.first >> buf.second;
		in_pq.push(buf);
	}
	//ó�� �Ѱ� pq_r�� ����
	pq_r.push(in_pq.top().second);
	in_pq.pop();

	while (!in_pq.empty()) {
		std::pair<int, int> now = in_pq.top();
		in_pq.pop();

		if (pq_r.top() <= now.first) {
			pq_r.pop();
			pq_r.push(now.second);
		}
		else {
			pq_r.push(now.second);
		}
	}
	
	return pq_r.size();
}

void Q11000() {
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << Q11000_solution();
}