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


	// �������� �˰���� N-1���� Ȯ���ϸ� �ִܰ�ΰ� �������µ�
	// N��° �ݺ� �� �ִܰ�ΰ� ���ŵȴٸ� �̴� ���� ����Ŭ�� ������ �׷�����.
	for (int i = 0; i < N; i++)
	{
		// ��� ��带 �� �� �� �� ���ػ�Ƽ� �ִܰŸ��� ���ҰŴ�.
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				// ���� ����ġ�� �ֱ� ������ pq�� ������� �ʰ� ��� ��带 N���� ������.
				int next_node = v[j][k].first;
				int next_cost = v[j][k].second;
				if (dist[next_node] > dist[j] + next_cost)
				{
					dist[next_node] = dist[j] + next_cost;
					// �������� �˰���� N-1���� Ȯ���ϸ� �ִܰ�ΰ� �������µ�
					// i==N-1(N��°)���� �ִܰ�ΰ� ���ŵȴٸ� �̴� ���� ����Ŭ�� ������ �׷�����.
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