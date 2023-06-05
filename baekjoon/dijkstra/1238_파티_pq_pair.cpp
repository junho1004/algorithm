#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 1010
#define INF 1e9
using namespace std;
// 앞서 풀이했던 파티 문제를 메모리는 적게 쓰면서, pair를 사용해서 풀이해보겠다.

// 다익스트라의 가장 기본적인 방법은 가장 처음 시작 노드 하나에서 각 노드까지의 최단 거리를 구한다. (일 대 다)라고 생각
// 즉, 1번 노드에서 시작했다면 다익스트라 배열의 값들은 1번 노드에서 각 노드까지 갈 수 있는 최단 거리를 의미할 것 이다.
// 
// 이 문제는 각 간선은 방향이 있기에 가는 것과 오는 것의 가중치가 다르다.
// 각 노드에서 X라는 노드로의 최단 거리(다 대 일)를 구해야 하고, X라는 노드에서 각 노드까지의 최단거리(일 대 다)를 더해야한다.
// 각 노드에서 X노드로의 최단 거리를 구하려면 다익스트라를 노드마다(1000번) 돌려야한다.이는 비효율적이니 다른 방법을 생각해야한다.
// 
// (다 대 일)을 (일 대 다) 로 바꿔보자.
// 그래프를 입력 받을 때 역방향 그래프를 입력 받으면 각 노드에서 X까지의 최단 거리도 다익스트라 한 번 만에 알 수 있다. 
// 
// X라는 노드에서 각 노드까지의 최단거리는 기본 다익스트라처럼 한 번만 돌리면 된다.

// 우선순위 큐에서 pair를 이용하면 pair의 first값 기준으로 내림차순 정렬이 기본이다.
// greater 옵션을 사용해서 pair의 first값 기준으로 오름차순 정렬이 가능하다.

int N, M, X;
vector<pair<int, int>> v[2][MAX_N];
int dijk[2][MAX_N];

void input() {
	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		// v[0]은 정방향에 비용, 도착노드
		// v[1]은 역방향에 비용, 도착노드
		v[0][a].push_back({ c,b });
		v[1][b].push_back({ c,a });
	}
	fill(&dijk[0][0], &dijk[1][MAX_N], INF);
}

void dijkstra(int dir)
{
	//dir == 0 이면 X_to_Node (정방향)
	//dir == 1 이면 Node_to_X (역방향)
	dijk[dir][X] = 0; // 자기자신으로 오는거 0
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,X }); // 비용, 시작노드

	while (!pq.empty())
	{
		int now_cost = pq.top().first;
		int now_vertex = pq.top().second;
		pq.pop();

		// 이미 해당 노드까지 가는데 더 적은 비용으로 갈 수 있다.
		// 굳이 now_cost부터 현재 최단거리보다 더 큰 얘를 확인해봤자 소용없다.
		if (dijk[dir][now_vertex] < now_cost) continue;

		for (int i = 0; i < v[dir][now_vertex].size(); i++)
		{
			int next_cost = v[dir][now_vertex][i].first;
			int next_vertex = v[dir][now_vertex][i].second;

			if (dijk[dir][next_vertex] > now_cost + next_cost)
			{
				dijk[dir][next_vertex] = now_cost + next_cost;
				pq.push({ now_cost + next_cost, next_vertex });
			}
		}
	}

}

void solve() {

	dijkstra(0); // X에서 각 노드까지 최단거리
	dijkstra(1); // 각 노드에서 X까지 최단거리

	int ans = -1;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dijk[0][i] + dijk[1][i]);
	}
	cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}