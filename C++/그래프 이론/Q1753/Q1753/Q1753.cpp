#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAX_V 20001
#define MAX_E 30001

int start_node, V, E;

typedef struct NODE {
    int end;
    int val;
};

std::vector<NODE> EDGE_dis_arr[MAX_E];
int dis[MAX_V] = { 0 };

void dijkstra() {
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({ 0,start_node });

    while (!pq.empty()) {
        int nnode = pq.top().second;
        int cost = pq.top().first;

        pq.pop();

        for (int k = 0; k < EDGE_dis_arr[nnode].size(); k++) {
            int new_val = dis[nnode] + EDGE_dis_arr[nnode][k].val;
            int before_val = dis[EDGE_dis_arr[nnode][k].end];

            if (new_val < before_val) {
                dis[EDGE_dis_arr[nnode][k].end] = new_val;
                pq.push({ -1 * new_val, EDGE_dis_arr[nnode][k].end });
            }
        }
    }

}
;
int main()
{
    scanf("%d %d %d", &V, &E, &start_node);
    int from, to, val;

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &val);
        EDGE_dis_arr[from].push_back(NODE{ to,val });
    }

    for (int i = 1; i <= V; i++) {
        dis[i] = INF;
    }
    dis[start_node] = 0;

    dijkstra();

    for (int i = 1; i <= V; i++) {
        if (dis[i] != INF)  printf("%d\n", dis[i]);
        else printf("INF\n");
    }

    return 0;
}