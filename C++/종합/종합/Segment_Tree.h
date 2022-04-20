/*
https://www.acmicpc.net/blog/view/9
O(logN)
*/

#pragma once
#include <vector>


class Segment_Tree_classic {
	//arr : �迭 arr
	//tree : ���׸�Ʈ Ʈ��
	//node : ���׸�Ʈ Ʈ�� ��� ��ȣ
	//node�� ����ϴ� ���� ����(start ~ end)
	long long init(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) {
		if (start == end) {
			return tree[node] = arr[start];	//node�� ���� ��� (�ش� �迭�� ���Ҹ� �״�� ������)
		}
		else {
			return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		}
	};

	//left ���� right������ ������ ��
	long long sum(std::vector<long long>& tree, int node, int start, int end, int left, int right) {
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	};

	//�� �����ϱ�
	void update(std::vector<long long>& tree, int node, int start, int end, int index, long long diff) {
		if (index < start || index >end)	return;
		tree[node] = tree[node] + diff;
		if (start != end) {
			update(tree, node * 2, start, (start + end) / 2, index, diff);
			update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		}
	};

};
