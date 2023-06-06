#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 트리의 특성 상 한 정점에서 다른 정점으로 가는 경로는 유일하다.
// 임의의 노드(정점 번호 1번은 무조건 존재하므로)로 부터 최대 가중치인 노드를 찾고, 그 가중치를 기록해 놓는다.
// 임의의 노드 기준으로 dfs를 돌려서 찾은 max_node로 부터, 다시 한 번 dfs를 돌려 가중치를 찾으면 곧 트리의 지름이 된다.
// 시간복잡도는 O(n)

int N;
vector<pair<int, int>> v[10010];
int used[10010];
int max_vertex, max_cost;


void input() {
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}
	max_cost = 0;
}

void dfs(int vertex, int cost)
{
	used[vertex] = 1;

	if (max_cost < cost) {
		max_cost = cost;
		max_vertex = vertex;
	}

	for (int i = 0; i < v[vertex].size(); i++)
	{
		if (used[v[vertex][i].second] == 1) continue; // 방문한 노드 처리
		dfs(v[vertex][i].second, cost + v[vertex][i].first);
	}
}

void solve() {
	dfs(1, 0);
	memset(used, 0, sizeof(used));
	// 1번 노드에서 부터 돌린 dfs로 최대 가중치인 노드를 찾았다.
	// 찾은 노드에서 dfs를 돌려서(가중치를 0이라고 두고) 최대 가중치인 노드를 찾으면 그는 곧 트리의 지름이 된다.
	dfs(max_vertex, 0);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	cout << max_cost;

	return 0;
}