/*
����
���̰� N�� ������ �־����� ��, �� ������ ���� ���Ϸ��� �Ѵ�. 
������, �׳� �� ������ ���� ��� ���ؼ� ���ϴ� ���� �ƴ϶�, ������ �� ���� �������� �Ѵ�. 
� ���� �������� �� ��, ��ġ�� ������� ���� �� �ִ�. ������, ���� ��ġ�� �ִ� ��(�ڱ� �ڽ�)�� ���� ���� �Ұ����ϴ�. 
�׸��� � ���� ���� �Ǹ�, ������ ���� ���� �� ���� ���� ���� ���� �Ŀ� ���Ѵ�.

���� ���, � ������ {0, 1, 2, 4, 3, 5}�� ��, 
�׳� �� ������ ���� ���ϸ� 0+1+2+4+3+5 = 15�̴�. 
������, 2�� 3�� ����, 4�� 5�� ���� �Ǹ�, 0+1+(2*3)+(4*5) = 27�� �Ǿ� �ִ밡 �ȴ�.

������ ��� ���� �� �ѹ��� ���ų�, �ƴϸ� ���� �ʾƾ��Ѵ�.

������ �־����� ��, ������ �� ���� ������ ������ ��, �� ���� �ִ밡 �ǰ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. N�� 10,000���� ���� �ڿ����̴�. 
��° �ٺ��� N���� �ٿ�, ������ �� ���� �־�����. ������ ���� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.

���
���� ���� �ִ밡 ������ ������ �� ���� ����Ѵ�. ������ �׻� 231���� �۴�.

���� �Է� 1
4
-1
2
1
3
���� ��� 1
6

//��Ʈ
// (-1)+1+(2*3) = 6
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
std::priority_queue<int, std::vector<int>, std::greater<int>> Q1744_positive;
std::priority_queue<int, std::vector<int>> Q1744_negative;


int Q1744_solution() {
	int result = 0;
	int N;
	bool zero = false;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int buf;
		std::cin >> buf;
		if (buf == 1) {
			result += 1;
		}
		else if (buf == 0) {
			zero = true;
		}
		else {
			if (buf > 0) {
				Q1744_positive.push(buf);
			}
			else {
				Q1744_negative.push(buf);
			}			
		}		
	}	

	if (Q1744_positive.size() % 2) {
		Q1744_positive.push(1);
	}
	if (Q1744_negative.size() % 2) {
		zero == 0 ? Q1744_negative.push(1) : Q1744_negative.push(0);
	}
	

	while (!Q1744_positive.empty())	{
		int num1 = Q1744_positive.top();
		Q1744_positive.pop();
		int num2 = Q1744_positive.top();
		Q1744_positive.pop();

		result += (num1 * num2);
	}
	while (!Q1744_negative.empty()){
		int num1 = Q1744_negative.top();
		Q1744_negative.pop();
		int num2 = Q1744_negative.top();
		Q1744_negative.pop();
		result += (num1 * num2);
	}
	   
	return result;
}

void Q1744() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cout << Q1744_solution();


}