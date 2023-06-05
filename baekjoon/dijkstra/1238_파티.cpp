#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 1010
#define INF 1e9
using namespace std;

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

int N, M, X;
struct Node {
	int vertex;
	int cost;
};

vector<Node> v[MAX_N]; // 정방향
int dijk[MAX_N];

vector<Node> v_r[MAX_N]; // 역방향
int dijk_r[MAX_N];


void input()
{
	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v_r[b].push_back({ a,c });
	}

	fill(dijk, dijk + MAX_N, INF);
	fill(dijk_r, dijk_r + MAX_N, INF);

}

bool operator<(Node v, Node t) {
	if (v.cost == t.cost) return v.vertex > t.vertex;
	return v.cost > t.cost;
}


void go_dijk()
{
	dijk[X] = 0;
	priority_queue<Node> pq;
	pq.push({ X,0 });

	while (!pq.empty())
	{
		int now_vertex = pq.top().vertex;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v[now_vertex].size(); i++)
		{
			int next_vertex = v[now_vertex][i].vertex;
			int next_cost = v[now_vertex][i].cost;

			if (dijk[next_vertex] > now_cost + next_cost)
			{
				dijk[next_vertex] = now_cost + next_cost;
				pq.push({ next_vertex, now_cost + next_cost });
			}

		}
	}
}

void go_dijk_r()
{
	dijk_r[X] = 0;

	priority_queue<Node> pq;
	pq.push({ X,0 });

	while (!pq.empty())
	{
		int now_vertex = pq.top().vertex;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v_r[now_vertex].size(); i++)
		{
			int next_vertex = v_r[now_vertex][i].vertex;
			int next_cost = v_r[now_vertex][i].cost;

			if (dijk_r[next_vertex] > now_cost + next_cost)
			{
				dijk_r[next_vertex] = now_cost + next_cost;
				pq.push({ next_vertex, now_cost + next_cost });
			}
		}
	}

}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();


	go_dijk(); 	// X에서 각 노드로의 최단거리
	go_dijk_r(); // 각 노드에서 X로의 최단거리(역방향 그래프를 써서 시작점은 똑같이 X로 보인다)

	int ans = -1;

	for (int i = 1; i <= N; i++) {
		ans = max(ans, dijk[i] + dijk_r[i]);
	}
	cout << ans;

	return 0;
}