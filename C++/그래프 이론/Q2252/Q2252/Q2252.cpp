// Q2252.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <queue>
#include <vector>
const int MAX = 32000 + 1;

int N, M;
int inDegree[MAX];  //우선순위
std::vector<int> graph[MAX];    //그래프

void BFS(void) {
    std::queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        printf("%d ", cur);

        for (int i = 0; i < graph[cur].size(); i++) {
            inDegree[graph[cur][i]]--;  //현재 노드와 연결되어있는 노드 전부 우선순위 낮춤
            if (!inDegree[graph[cur][i]]) { //우선순위가 0 일경우 push
                q.push(graph[cur][i]);
            }
        }
    }

}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        inDegree[b]++;
    }
    BFS();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
