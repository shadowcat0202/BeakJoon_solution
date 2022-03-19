//#pragma once
//
//template <typename T>
//struct Node {
//	Node* left;
//	Node* right;
//	T value;
//};
//
//template <typename T>
//class BinarySearchTree {
//public:
//	BinarySearchTree() :root(nullptr) {};
//	~BinarySearchTree() {};
//
//	void AddNode(T _value) {
//		Node<T>* node = new Node<T>();
//		Node<T>* tmpRoot = nullptr;
//
//		node->value = _value;
//
//		if (root == nullptr)
//			root = node;
//		else {
//			Node<T>* ptr = root;
//			while (ptr != nullptr) {
//				tmpRoot = ptr;
//				if (node->value < ptr->value)
//					ptr = ptr->left;
//				else
//					ptr = ptr->right;
//			}
//		}
//		if (node->value < tmpRoot->value)//������ ���ݵ�(tmpRoot = nulptr) ����?
//			tmpRoot->left = node;
//		else
//			tmpRoot->right = node;	
//	}
//	bool SearchValue(T _value) {
//		Node<T>* ptr = root;
//		Node<T>* tmpRoot = nullptr;
//
//		while (ptr != nullptr) {
//			if (ptr->value == _value) {
//				std::cout << _value << "���� ã�ҽ��ϴ�.\n";
//				return true;
//			}
//			else if (ptr->value > _value) {
//				ptr = ptr->left;
//			}
//			else
//				ptr = ptr->right;
//		}
//		std::cout << _value << "���� ã�� ���߽��ϴ�.\n";
//		return false;
//	}
//	void RemoveNode(T _value) {
//		Node<T>* ptr = root;
//		RemoveSequence(ptr, _value);
//	}
//	void Display() {
//		Inorder(root);
//	}
//
//private:
//	Node<T>* root;
//	Node<T>* tail;
//
//	void Inorder(Node<T>* current) {	//display �뵵
//		if (current != nullptr) {
//			Inorder(current->left);
//			std::cout << current->left << " ";
//			Inorder(current->right);
//		}
//	}
//	Node<T>* SearchMaxNode(Node<T>* node) {	//�ش� Ʈ������ ���� ū �� ã��
//		if (node == nullptr)	return nullptr;
//		while (node->right != nullptr) {
//			node = node->right;
//		}
//		return node;
//	}
//	Node<T>* SearchMinNode(Node<T>* node) {	//�ش� Ʈ������ ���� ���� �� ã��
//		if (node == nullptr)	return nullptr;
//		while (node->left != nullptr) {
//			node = node->left;
//		}
//		return node;
//	}
//	Node<T>* RemoveSequence(Node<T>* node, T _value) {
//		if (node == nullptr)	return node;
//		else if (node->value > _value)
//			node->left = RemoveSequence(node->left, _value);
//		else if (node->value < _value)
//			node->right = RemoveSequence(node->right, _value);
//		else {
//			Node<T>* ptr = node; //�ڽ��̾����� 
//			if (node->right == nullptr && node->left == nullptr) {
//				delete node; node = nullptr;
//			}
//			//�ڽ��� �ϳ��ϋ� 
//			else if (node->right == nullptr) {
//				node = node->left; delete ptr;
//			}
//			else if (node->left == nullptr) {
//				node = node->right; delete ptr;
//			}
//			//�ڽ��� �ΰ��ϋ� :: ���� ����� ����ū�� ã�� �θ���� �ٲٱ�
//			else {
//				ptr = SearchMaxNode(node->left);
//				node->value = ptr->value;
//				node->left = RemoveSequence(node->left, ptr->value);
//			}
//		}
//	}
//
//};