// MST(�ּ� ���� Ʈ��) �� ���ϱ� ���� ����, ũ�罺Į �˰����� ����ؾ��Ѵ�.
// ũ�罺Į �˰����� ��� ������ ���� �������� ���� �� ���� ����ġ�� ���� �������� �̾��
// Union Find�� �̿��� ���Ῡ�θ� �ľ��Ѵ�.

// ���� �˰����� ������ �� �������� ������ ���ͽ�Ʈ�� ó�� ���� ���� ����ġ ������ ����
// ������ ������ �湮ó���� �����ν� �̾�� �� ���� �׸� �ϳ��� �������� ����
// �� ���հ� ������� ���� ������ ���� ����ġ�� ���� ������ �����Ѵ�.
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