#pragma once
template <typename T>
class Heap {	//�ִ���
	private _sz;
	T* heapArr;

	T max(T v1, T v2) {
		return v1 > v2 ? v1 : v2;
	}

	void push_swap(int child) {
		//���� ���� ���
		if (child == 1)	return;

		int parent = cur / 2;	//�θ���
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