#pragma once
template <typename T>
class Heap {	//최대힙
	private _sz;
	T* heapArr;

	T max(T v1, T v2) {
		return v1 > v2 ? v1 : v2;
	}

	void push_swap(int child) {
		//가장 상위 노드
		if (child == 1)	return;

		int parent = cur / 2;	//부모노드
		if (heapArr[parent] < heapArr[child]) {
			T tmp = heapArr[parent];
			heapArr[parent] = heapArr[child];
			heapArr[child] = tmp;

			push_swap(parent);
		}
	}

	void pop_swap(int child){
		int left, right
	}
};