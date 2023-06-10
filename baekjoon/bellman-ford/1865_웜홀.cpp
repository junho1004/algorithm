#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 510
#define INF 1e9
using namespace std;

int N, M, W;

vector<pair<int, int>> v[MAX_N];
int dist[MAX_N];

void init() {
	for (int i = 0; i <= N; i++) {
		v[i].clear();
	}
}

void input() {
	cin >> N >> M >> W;
	int From, To, Cost;
	for (int i = 0; i < M; i++) {
		cin >> From >> To >> Cost;
		v[From].push_back({ To, Cost });
		v[To].push_back({ From, Cost });
	}
	for (int i = 0; i < W; i++) {
		cin >> From >> To >> Cost;
		v[From].push_back({ To, -Cost });
	}
}

void bellman() {
	fill(dist, dist + MAX_N, INF);
	dist[1] = 0;


	// 벨만포드 알고리즘상 N-1번만 확인하면 최단경로가 구해지는데
	// N번째 반복 때 최단경로가 갱신된다면 이는 음의 싸이클을 가지는 그래프다.
	for (int i = 0; i < N; i++)
	{
		// 모든 노드를 각 한 번 씩 기준삼아서 최단거리를 구할거다.
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				// 음의 가중치가 있기 때문에 pq를 사용하지 않고 모든 노드를 N번을 돌릴것.
				int next_node = v[j][k].first;
				int next_cost = v[j][k].second;
				if (dist[next_node] > dist[j] + next_cost)
				{
					dist[next_node] = dist[j] + next_cost;
					// 벨만포드 알고리즘상 N-1번만 확인하면 최단경로가 구해지는데
					// i==N-1(N번째)에도 최단경로가 갱신된다면 이는 음의 싸이클을 가지는 그래프다.
					if (i == N - 1) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tcCnt;
	cin >> tcCnt;
	while (tcCnt--) {
		input();
		bellman();
		init();
	}

	return 0;
}