//#include <iostream>
//
//template <typename T>
//struct Node {
//public:
//	T value;
//	struct Node<T>* next = nullptr;
//};
//
//template <typename T>
//class SingleLinked_List {
//private:
//	Node<T>* head;	//머리
//	Node<T>* tail;	//꼬리
//	int size = 0;	//링크 길이
//
//public:
//	SingleLinked_List() : head(nullptr), tail(nullptr) {}	//생성자 리스트
//	~SingleLinked_List() {}	//소멸자
//
//	void AddNode(T _value) {
//		Node<T>* node = new Node<T>;
//
//		size++;
//		node->value = _value;
//		node->next = nullptr;
//
//		if (head == nullptr) {	//시작(머리)이 없을경우
//			head = node;
//			tail = node;
//		}
//		else {	//시작(머리)이 있을경우 뒤에 연결
//			tail->next = node;
//			tail = tail->next;
//		}
//	}
//	
//	void RemoveNode(T _value) {	//찾는 값 노드 지우기
//		Node<T>* ptr = head;
//		Node<T>* tmp = ptr;
//
//		while (ptr != nullptr) {
//			if (ptr->value == _value) {
//				break;
//			}
//			else {
//				tmp = ptr;	//목표의 전 노드
//				ptr = ptr->next;
//			}
//		}
//		if (ptr == nullptr) {
//			printf("찾을 수 없는 노드 값\n");
//		}
//		else {
//			size--;
//			printf("삭제된 노드의 값: %d\n", ptr->value);
//			tmp->next = ptr->next;	//삭제할 노드 제외 연결
//			delete ptr;
//		}
//	}
//
//	void show() {	//리스트 내용물 보여주기
//		Node<T>* node = head;
//		while (node != nullptr) {
//			printf("%d->", node->vale);
//			node = node->next;
//		}
//		printf("\n");
//	}
//
//	void DeleteList() {
//		Node<T>* ptr = head;
//		while (ptr != nullptr) {
//			head = ptr->next;
//			delete ptr;
//			ptr = head;
//		}
//		delete head;
//		size = 0;
//		printf("SingleLinked_List가 삭제되었습니다.\n");
//	}
//
//
//};