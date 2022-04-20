/*
https://www.acmicpc.net/blog/view/9
O(logN)
*/

#pragma once
#include <vector>


class Segment_Tree_classic {
	//arr : 배열 arr
	//tree : 세그먼트 트리
	//node : 세그먼트 트리 노드 번호
	//node가 담당하는 합의 범위(start ~ end)
	long long init(std::vector<long long>& arr, std::vector<long long>& tree, int node, int start, int end) {
		if (start == end) {
			return tree[node] = arr[start];	//node가 리프 노드 (해당 배열의 원소를 그대로 가져옴)
		}
		else {
			return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		}
	};

	//left 에서 right까지의 구간의 합
	long long sum(std::vector<long long>& tree, int node, int start, int end, int left, int right) {
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	};

	//수 변경하기
	void update(std::vector<long long>& tree, int node, int start, int end, int index, long long diff) {
		if (index < start || index >end)	return;
		tree[node] = tree[node] + diff;
		if (start != end) {
			update(tree, node * 2, start, (start + end) / 2, index, diff);
			update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		}
	};

};
