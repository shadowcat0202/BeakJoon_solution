/*
문제
오늘은 신승원의 생일이다.

박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 줬다.

공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.

공항에는 P개의 비행기가 순서대로 도착할 예정이며, 
당신은 i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다.
비행기가 어느 게이트에도 도킹할 수 없다면 공항이 폐쇄되고, 이후 어떤 비행기도 도착할 수 없다.

신승원은 가장 많은 비행기를 공항에 도킹시켜서 박승원을 행복하게 하고 싶어한다. 
승원이는 비행기를 최대 몇 대 도킹시킬 수 있는가?

입력
첫 번째 줄에는 게이트의 수 G (1 ≤ G ≤ 105)가 주어진다.
두 번째 줄에는 비행기의 수 P (1 ≤ P ≤ 105)가 주어진다.
이후 P개의 줄에 gi (1 ≤ gi ≤ G) 가 주어진다.

출력
승원이가 도킹시킬 수 있는 최대의 비행기 수를 출력한다.

예제 입력 1
4
3
4
1
1
예제 출력 1
2

예제 입력 2
4
6
2
2
3
3
4
4
예제 출력 2
3
*/

//분리집합 개념 필요
//find union 개념 사용해서 (이해완료)
#include <iostream>
#include <string.h>
int Q10775_G, Q10775_P;
int Q10775_parent[100001];	//이거 106으로 하면 틀림 이유는 out of bounds
/*
//처음 생각했던거(답은 도출 되는데 왜 틀리다고 하는지 모르겠다)

int Q10775_solution() {
	int G, P;
	bool dok[106];
	int result = 0;
	std::cin >> G >> P;
	for (int i = 0; i < P; i++) {
		int buf;
		std::cin >> buf;
		if (!dok[buf])	continue;
		dok[buf] = true;
		result++;
	}
	return result;

}
*/
int Q10775_find(int u) {
	if (Q10775_parent[u] == u)	return u;	//여기서 계속 예외가 발생했다고 하는데 무슨 시발 예외인지 알수가 없다(답은 잘나온다 통과했다)
	return Q10775_parent[u] = Q10775_find(Q10775_parent[u]);
}

void Q10775_Union(int u, int v) {
	u = Q10775_find(u);
	v = Q10775_find(v);
	Q10775_parent[u] = v;
}

int Q10775_solution() {
	//std::memset(Q10775_parent, 0, 100001 * sizeof(int));
	std::cin >> Q10775_G >> Q10775_P;

	for (int i = 1; i <= Q10775_G; i++) {
		Q10775_parent[i] = i;
	}

	int g, res = 0;

	while (Q10775_P--) {
		std::cin >> g;
		if (Q10775_find(g) == 0)	break;
		else {
			res++;
			Q10775_Union(Q10775_find(g), Q10775_find(g) - 1);

		}
	}
	return res;
}

void Q10775() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); //cin 실행속도 향상

	std::cout << Q10775_solution() << "\n";
}