#include <iostream>
#include <vector>
//#include <Windows.h>
#define endl "\n"

using namespace std;
const int MAX = 1000 + 1;
vector<int> arr[MAX];
bool visited[MAX];
int N, M;
int dfs_count = 0;

//void tabcount(int t) {
//	for (int n = 0; n < t; n++) {
//		cout << "\t";
//	}
//}

void DFS(int node) {
	dfs_count++;
	//tabcount(dfs_count);
	//printf("#%d번 째 DFS 진행중\n",dfs_count);
	visited[node] = true;
	//tabcount(dfs_count);
	//printf("%d번 노드 방문 체크\n",node);
	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		//tabcount(dfs_count);
		//printf("%d벡터(상위노드)의 %d번째 배열(노드) 검색중\n", node, i+1);
		//Sleep(50);
		if (visited[next] == false) {
			//tabcount(dfs_count);
			//printf("<SYSTEM: 방문한적 없음 DFS재귀를 실행합니다.>\n");
			//Sleep(100);
			DFS(next);
		}
			
	}
	//tabcount(dfs_count);
	//printf("#%d번 째 DFS 종료\n",dfs_count);
	dfs_count--;

}

int main() {
	//읽기 쓰기 방식을 파일 형식으로 전환
	/*freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);*/

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {	//사실상 여기서 사이클을 판단하는 부분
		//printf("%d번 노드 방문 검색중...",i);
		if (!visited[i]) {
			//printf("\n<SYSTEM: %d번 노드 방문 한적 없음 DFS를 실행합니다.>\n",i);
			DFS(i);
			cnt++;
		}
		/*else {
			printf(" 방문했었음\n");
		}*/
	}
	cout << cnt << endl;
	return 0;
}

