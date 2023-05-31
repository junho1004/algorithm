// 20,000 x 20,000 int 배열 => 메모리초과
// 벡터와 우선순위 큐를 이용해 다익스트라 알고리즘을 구현한다.

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 20010
#define INF 21e8
using namespace std;

int V_cnt, E_cnt, start_node;

struct Node {
	int vertex;
	int weight;
};

vector<Node> v[MAX_N];
int dijk[MAX_N];

void input() {
	cin >> V_cnt >> E_cnt >> start_node;
	int a, b, c;
	for (int i = 0; i < E_cnt; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	fill(dijk, dijk + MAX_N, INF);
}

bool operator<(Node v, Node t) {
	if (v.weight == t.weight) return v.vertex > t.vertex;
	return v.weight > t.weight;
}

void solve() {
	priority_queue<Node> pq;
	// 자기 자신에서는 가중치 0
	pq.push({ start_node, 0 });
	dijk[start_node] = 0;

	while (!pq.empty()) { 
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < v[now.vertex].size(); i++) 
		{
			int next_node = v[now.vertex][i].vertex;
			int next_weight = v[now.vertex][i].weight;

			// 다음 노드로 가는 링크의 가중치가 더 작은 새로운 것이 들어온다면
			// 최솟값으로 갱신하고 우선순위큐에 push
			if (dijk[next_node] > now.weight + next_weight) 
			{
				dijk[next_node] = now.weight + next_weight;
				pq.push({ next_node, now.weight + next_weight });
			}
		}
	}

	for (int i = 1; i <= V_cnt; i++) {
		if (dijk[i] == INF) cout << "INF\n";
		else cout << dijk[i] << "\n";
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	solve();

	return 0;
}