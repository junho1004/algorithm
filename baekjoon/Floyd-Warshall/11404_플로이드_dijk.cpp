#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100'000'000
using namespace std;

int N, M;
int dijk[110][110];

vector<pair<int, int>> v[110];


void input() {
	cin >> N >> M;
	int a, b, c;

	fill(&dijk[0][0], &dijk[109][110], INF);

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}


}

void solve() {

	for (int point = 1; point <= N; point++) 
	{

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, point });

		while (!pq.empty())
		{
			int now_cost = pq.top().first;
			int now_node = pq.top().second;
			pq.pop();

			for (int i = 0; i < v[now_node].size(); i++) 
			{
				int next_cost = v[now_node][i].first;
				int next_node = v[now_node][i].second;

				if (dijk[point][next_node] > now_cost + next_cost) 
				{
					dijk[point][next_node] = now_cost + next_cost;
					pq.push({ now_cost + next_cost, next_node });
				}
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (y == x || dijk[y][x] == INF) 
				cout << 0 << " ";
			else 
				cout << dijk[y][x] << " ";
		}
		cout << "\n";
	}
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}