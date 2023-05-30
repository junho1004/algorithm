#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 100010

// 트리의 특성 상 한 정점에서 다른 정점으로 가는 경로는 유일하다.
// 임의의 노드(정점 번호 1번은 무조건 존재하므로)로 부터 최대 가중치인 노드를 찾고, 그 가중치를 기록해 놓는다.
// 임의의 노드 기준으로 dfs를 돌려서 찾은 max_node로 부터 다시 한 번 dfs를 돌린다.
// 시간복잡도는 O(n)

int N;
struct Node {
	int vertex;
	int cost;
};
vector<Node> v[MAX_N];
bool used[MAX_N] = { false, };

int max_node, max_cost;

// 구조체 벡터에 담기
void input() {
	cin >> N;
	int tmp_vertex, tmp_to_node, tmp_cost;
	for (int i = 0; i < N; i++) {
		cin >> tmp_vertex;

		while (1) {
			cin >> tmp_to_node;
			if (tmp_to_node == -1) break;
			cin >> tmp_cost;

			v[tmp_vertex].push_back({ tmp_to_node, tmp_cost });
		}
	}
	max_cost = 0;
}

void dfs(int now, int dist) {
	used[now] = true;

	if (max_cost < dist) {
		max_cost = dist;
		max_node = now;
	}

	for (int i = 0; i < v[now].size(); i++) {
		// 방문한 노드면 continue
		if (used[v[now][i].vertex] == true) continue;
		dfs(v[now][i].vertex, dist + v[now][i].cost);
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	// 임의의 노드 1번으로 부터 dfs를 돌려 max_node와 max_cost를 갱신한다.
	dfs(1, 0);

	// used배열을 초기화 해줌.
	memset(used, false, sizeof(used));

	// 첫번째 dfs로 찾은 노드로부터 dfs를 돌려 max_cost를 갱신한다.
	dfs(max_node, 0);

	cout << max_cost;
	return 0;
}