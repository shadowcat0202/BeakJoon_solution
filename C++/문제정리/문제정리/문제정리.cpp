#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <time.h>   //�ð� ����
#include <string>   //���ڿ� ��ġ��
#include "header/selftest1.h"  //�ش� ���� ��� �ʿ�(���� ���� ���ҷ���)



//typedef void (*FnPtr)();    //�Լ��̸��� �����ͷ� ���
//std::map<std::string, FnPtr> FuntionMap;
//�Լ����� mapping���� ����ϴ� ����� ���� �����غ���()
/*
void Q_number_mapping_init() {
    std::ifstream fr;
    fr.open("D:\\mystudy\\BeakJoon\\C++\\������ȣ.txt");
    if (fr.is_open()) {
        std::string line;
        while (!fr.eof()) {
            //���پ� ã��
            std::getline(fr, line);

            if (line.compare(Q_number)) {
                FuntionMap[line] = line;
            }

        }
    }
    else {
        printf("������ȣ.txt file is not exist");
    }

}
*/

//void io_init() {
//    //����� ��� �޸���
//    std::string input_txt_name = "input\\Q" + Q_number + ".txt";
//    freopen(input_txt_name.c_str(), "r", stdin);            //�Է�
//    //freopen("result.txt","w",stdout); //���
//}

void test() {
    test_init();
    input();
}

//void solve() {
//    io_init();
//
//    //input.txt�� ����Ǿ��ִ� ���� �Է����� Ȯ��
//    while (!feof(stdin)) {
//        //������ ���� ��ȣ �Լ�
//        time_t start = 0, end = 0;
//        start = clock();
//        //Q2206();   //�����ؾ���
//        end = clock();
//
//        //�ð� ����
//        double Operating_time = (double)(end - start);
//        printf("\n����ð� : %f\n", Operating_time);
//    }
//}

int main()
{
    test();
    return 0;

}