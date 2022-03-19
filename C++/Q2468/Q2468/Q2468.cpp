#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 100

using namespace std;
typedef pair<int, int> P;

int map[MAX][MAX];
int N;
vector <int> V;
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			V.push_back(map[i][j]);
		}
	}
	//벡터 중복 제거
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
}

int BFS(int h) {
	queue<P> Q;
	bool visited[MAX][MAX] = { 0 };
	int nY, nX, cY, cX, land = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > h && visited[i][j] == false) {
				visited[i][j] = true;
				Q.push(P(i,j));				
				
				while (!Q.empty()) {
					cY = Q.front().first;
					cX = Q.front().second;
					Q.pop();
					for (int r = 0; r < 4; r++) {
						nY = cY + dirY[r];
						nX = cX + dirX[r];

						if (visited[nY][nX] == true)	continue;
						if (nY < 0 || nY >= N || nX < 0 || nX >= N)	continue;
						if (map[nY][nX] > h) {
							Q.push(P(nY, nX));
							visited[nY][nX] = true;
						}
					}					
				}
				land++;				
			}
		}
	}	
	return land;
}



int main(){
	int R = 0;
	input();
	for (int w = 0; w < V.size(); w++) {
		R = max(R,BFS(V[w]));
	}
	cout << R;
	return 0;
}
