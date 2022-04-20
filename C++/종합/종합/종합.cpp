#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
//#include "tree.h" //AddNode에서 엑세스 오류
//#include "header/init.h"    //입력예제 데이터 세팅
//#include "../BOJ_solution/탐색.h";
//#pragma comment (lib, "../Debug/BOJ_solution.lib")


//void BOJ() {
//    std::string Q_number = "1197";
//    init_input(Q_number);
//
//    while (!feof(stdin)) {
//        time_t start, end;
//        double during_time;
//
//        start = time(NULL);
//        //Q1197* solve = new Q1197();
//        //solve->start();
//        end = time(NULL);
//
//        //solve = NULL;
//
//        printf("실행 시간 = %f\n", (double)(end - start));
//    }   
//}

//void test() {
//    BinarySearchTree<int>* BST = new BinarySearchTree<int>();
//	BST->AddNode(1);
//	BST->AddNode(3); 
//    BST->AddNode(6); 
//    BST->AddNode(9);
//    BST->AddNode(13);
//    BST->AddNode(22); 
//    BST->AddNode(17); 
//    BST->AddNode(10); 
//    BST->AddNode(2); 
//
//    BST->Display(); 
//    std::cout << "\n"; 
//
//    BST->SearchValue(4); 
//    BST->SearchValue(17);
//
//    std::cout << "\n";
//    BST->RemoveNode(17); 
//    BST->RemoveNode(9); 
//    BST->RemoveNode(6); 
//    BST->RemoveNode(3);
//    BST->Display();
//    std::cout << "\n";
//}


//linkedList 기본


//template <typename T>
//struct Node {
//    T value;
//    Node* nextNode;
//};
//
//template <typename T>
//class LinkedList {
//private:
//    Node* head, *tail;  //시작 지점과 끝지점    //헤드로 움직인다
//    int LinkedList_size = 0;
//public:
//    LinkedList() { head = tail = nullptr; } //head, tail포인터 초기화
//
//    //링크드리스트 앞쪽에 데이터 추가
//    void addfrontNode(T _value) {
//        Node<T>* temp = new Node<T>;
//
//        temp->data = _value;
//
//        //링크드 리스트가 비어있다면(아무것도 없다면)
//        if (head == nullptr) {
//            head = temp;
//            tail = temp;
//        }
//        else {//링크드리스트에 데이터가 하나라도 있다면
//            temp->nextNode = head;
//            head = temp;
//        }
//    }
//    void addNode(T _value) {
//        Node<T>* temp = new Node<T>;    //새로운 노드 생성
//
//        //새로운 노드에 대한 정보 입력
//        temp->data = _value;    //data와
//        temp->nextNode = nullptr;   //포인터의 다음 노드(현재는 마지막 위치에 넣기 때문에 nullptr로 지정)
//
//        if (head == nullptr) {
//            head = temp;
//            tail = temp;    //tail을 왜 새로운 노드로 포인터를 가르키는지 모르겠다
//        }
//        else {
//            tail->nextNode = temp;
//            tail = temp;
//        }
//
//
//    }
//    void insertNode(Node* prevNode, T _value) {
//        Node<T>* temp = new Node<T>;
//
//        temp->data = _value;
//
//        temp->nextNode = prevNode->nextNode;
//
//        prevNode->nextNode = temp;
//    }
//    void deleteNode(Node* prevNode) {
//        Node<T>* temp = prevNode->nextNode;
//        prevNode->nextNode = temp->nextNode;
//        delete temp;
//    }
//    Node* getHead() {
//        return head;
//    }
//    void display(Node* head) {
//
//    }
//};



//iterator 기본
//void iterator_test() {
//    std::vector<int> v;
//    double sum = 0;
//    while (true) {
//        int temp;
//        printf("정수를 입력하세요(0 을 입력하면 종료) >>");
//        scanf("%d", &temp);
//        if (!temp)    break;
//        v.push_back(temp);
//        std::vector<int>::iterator iter;
//        for (iter = v.begin(); iter != v.end(); iter++) {
//            printf("%d ", *iter);
//        }
//        printf("\n");
//
//        sum += temp;
//        printf("평균 = %f\n", sum / v.size());
//    }
//
//    printf("반복자 개념을 포인터로 적용한 방법\n");
//    int ari[] = { 1,2,3,4,5 }; 
//    int* it; 
//    for (it = &ari[0]; it != &ari[5]; it++){ 
//        printf("%d ", *it); 
//    }
//
//
//}

//void 카잉달력() {
//    int test_case;
//    scanf("%d", &test_case);
//    
//    while (test_case--) {
//        int m, n, x, y;
//        scanf("%d %d %d %d", &m, &n, &x, &y);
//        bool okay = false;
//        x -= 1; y -= 1;
//        for (int k = x; k < m * n; k += m) {
//           //printf("k=%d k\%m=%d k\%n=%d \n", k, k % m, k % n);
//            if (k % m == x && k % n == y) {
//                printf("%d\n", k + 1);
//                okay = true;
//                break;
//            }
//        }
//        if (!okay)   printf("-1\n");
//    }
//
//}


//int 수_이어_쓰기() {
//    char a[9];
//    scanf("%s", &a); //scanf는 std::string으로 받지 못한다
//    std::string n = a;
//    int len = int(n.size());
//    
//    if (len == 1)    return stoi(n);
//    long answer = 0;
//    for (int i = 1; i < len; i++) {
//        answer += i * (9 * pow(10, i - 1));
//    }
//    answer += len *(stoi(n)-pow(10,len-1)+1);
//
//
//    return answer;
//}
int main()
{

    return 0;
}