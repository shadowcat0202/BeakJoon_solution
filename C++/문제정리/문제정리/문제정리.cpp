#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <time.h>   //시간 측정
#include <string>   //문자열 합치기
#include "header/selftest1.h"  //해당 문제 헤더 필요(내가 쓰기 편할려고)



//typedef void (*FnPtr)();    //함수이름플 포인터로 사용
//std::map<std::string, FnPtr> FuntionMap;
//함수명을 mapping으로 사용하는 방법을 좀더 생각해보자()
/*
void Q_number_mapping_init() {
    std::ifstream fr;
    fr.open("D:\\mystudy\\BeakJoon\\C++\\문제번호.txt");
    if (fr.is_open()) {
        std::string line;
        while (!fr.eof()) {
            //한줄씩 찾음
            std::getline(fr, line);

            if (line.compare(Q_number)) {
                FuntionMap[line] = line;
            }

        }
    }
    else {
        printf("문제번호.txt file is not exist");
    }

}
*/

//void io_init() {
//    //입출력 방식 메모장
//    std::string input_txt_name = "input\\Q" + Q_number + ".txt";
//    freopen(input_txt_name.c_str(), "r", stdin);            //입력
//    //freopen("result.txt","w",stdout); //출력
//}

void test() {
    test_init();
    input();
}

//void solve() {
//    io_init();
//
//    //input.txt에 저장되어있는 예제 입력으로 확인
//    while (!feof(stdin)) {
//        //실직적 문제 번호 함수
//        time_t start = 0, end = 0;
//        start = clock();
//        //Q2206();   //변경해야함
//        end = clock();
//
//        //시간 측정
//        double Operating_time = (double)(end - start);
//        printf("\n실행시간 : %f\n", Operating_time);
//    }
//}

int main()
{
    test();
    return 0;

}