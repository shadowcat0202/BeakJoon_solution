/*
����
�����̴� �� û�Ҹ� �ϸ鼭 �ʿ� ���� ���� ������ ����鿡�� �����ַ��� �Ѵ�.
������ å�� ��ƺ��� �� N���̾���. å�� �ʹ� ���� ������ �����̴� å�� �����ϱ� ���� ���� 1���� N������ ���� ��ȣ�� �ߺ����� �ʰ� �Ű� �ξ���.

���縦 �� ���� å�� ���ϴ� �������б� �кλ��� �� M���̾���. 
�����̴� �� M���� ��û���� �� ���� a, b (1 �� a �� b �� N)�� ���� ����� �ߴ�. 
�׷��� �����̴� å ��ȣ�� a �̻� b ������ å �� �����ִ� å �� ���� ��� �� �л����� �ش�. 
���� a������ b�������� ��� å�� �̹� �ٸ� �л����� �ְ� ���ٸ� �� �л����Դ� å�� ���� �ʴ´�.

�����̰� å�� �� �� �ִ� �ִ� �л� ���� ���Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����.

�� ���̽��� ù �ٿ� ���� N(1 �� N �� 1,000)�� M(1 �� M �� 1,000)�� �־�����.
���� �ٺ��� M���� �ٿ��� ���� ���� ai, bi�� �־�����. (1 �� ai �� bi �� N)

���
�� �׽�Ʈ ���̽����� �����̰� å�� �� �� �ִ� �ִ� �л� ���� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1
1
2 3
1 2
1 2
1 2
���� ��� 1
2
*/


/*
�̺и�Ī �˰���: A������ B������ �����ϴ� ��� �˰���
ȿ�������� ��Ī�����شٴ� ���� �ִ��Ī(Max Matching)�� �ǹ�
��� A(x)�� B(y)�� ���� ���� ��Ī�Ǵ°��
�ð� ���⵵�� ���� ª������ �ƴ����� DFS�� ���� �ذ��Ѵ�
*/
#include <iostream>
#include <vector>
#define Q9576_MAX 1010
int Q9576_work[Q9576_MAX];
bool Q9576_book[Q9576_MAX];
std::vector<std::pair<int, int>> Q9576_v(Q9576_MAX);

bool Q9576_DFS(int x) {
	int size = Q9576_v[x].second - Q9576_v[x].first+ 1;
	for (int i = 0; i < size; i++) {
		int t = Q9576_v[x].first + i;
		if (Q9576_book[t]) {
			continue;
		}
		Q9576_book[t] = true;
		
		if (Q9576_work[t] == 0 || Q9576_DFS(Q9576_work[t])) {
			Q9576_work[t] = x;
			return true;
		}
	}
	return false;

}

int Q9576_solution() {
	int result = 0;
	int N, M;
	Q9576_v.clear();
	Q9576_v.push_back({ 0,0 });
	std::cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int start, end;
		std::cin >> start >> end;
		Q9576_v.push_back({ start, end });
	}
	std::fill(Q9576_work, Q9576_work + Q9576_MAX, 0);
	for (int i = 1; i <= M; i++) {
		std::fill(Q9576_book, Q9576_book + Q9576_MAX, false);
		if (Q9576_DFS(i))	result++;
	}


	return result;
}

void Q9576() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	int testcase;
	std::cin >> testcase;
	while (testcase--) {
		std::cout << Q9576_solution() << "\n";
	}
}
