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
//	Node<T>* head;	//�Ӹ�
//	Node<T>* tail;	//����
//	int size = 0;	//��ũ ����
//
//public:
//	SingleLinked_List() : head(nullptr), tail(nullptr) {}	//������ ����Ʈ
//	~SingleLinked_List() {}	//�Ҹ���
//
//	void AddNode(T _value) {
//		Node<T>* node = new Node<T>;
//
//		size++;
//		node->value = _value;
//		node->next = nullptr;
//
//		if (head == nullptr) {	//����(�Ӹ�)�� �������
//			head = node;
//			tail = node;
//		}
//		else {	//����(�Ӹ�)�� ������� �ڿ� ����
//			tail->next = node;
//			tail = tail->next;
//		}
//	}
//	
//	void RemoveNode(T _value) {	//ã�� �� ��� �����
//		Node<T>* ptr = head;
//		Node<T>* tmp = ptr;
//
//		while (ptr != nullptr) {
//			if (ptr->value == _value) {
//				break;
//			}
//			else {
//				tmp = ptr;	//��ǥ�� �� ���
//				ptr = ptr->next;
//			}
//		}
//		if (ptr == nullptr) {
//			printf("ã�� �� ���� ��� ��\n");
//		}
//		else {
//			size--;
//			printf("������ ����� ��: %d\n", ptr->value);
//			tmp->next = ptr->next;	//������ ��� ���� ����
//			delete ptr;
//		}
//	}
//
//	void show() {	//����Ʈ ���빰 �����ֱ�
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
//		printf("SingleLinked_List�� �����Ǿ����ϴ�.\n");
//	}
//
//
//};