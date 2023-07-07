// MST(최소 신장 트리) 를 구하기 위해 프림, 크루스칼 알고리즘을 사용해야한다.
// 크루스칼 알고리즘은 모든 간선에 대해 오름차순 정렬 후 가장 가중치가 작은 간선부터 이어가며
// Union Find를 이용해 연결여부를 파악한다.

// 프림 알고리즘은 임의의 한 정점에서 시작해 다익스트라 처럼 가장 작은 가중치 간선을 고르고
// 연결한 정점에 방문처리를 함으로써 이어나갈 때 마다 그를 하나의 집합으로 보고
// 그 집합과 연결되지 않은 정점중 가장 가중치가 작은 정점을 선택한다.
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_V 100'10
using namespace std;

int V, E;
vector<pair<int, int>> v[MAX_V];
bool visited[MAX_V];
long long ans;

void input() {
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	ans = 0;
}

void solve() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int now = pq.top().second;
		int now_cost = pq.top().first;
		pq.pop();


		if (visited[now]) continue;
		visited[now] = 1;

		ans += now_cost;

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].second;
			int next_cost = v[now][i].first;

			if (visited[next]) continue;

			pq.push({ next_cost, next });
		}
	}
}

int main() {
	cin.tie(0); cout.tie();
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;

	return 0;
}