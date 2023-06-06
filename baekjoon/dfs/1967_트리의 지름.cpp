#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// Ʈ���� Ư�� �� �� �������� �ٸ� �������� ���� ��δ� �����ϴ�.
// ������ ���(���� ��ȣ 1���� ������ �����ϹǷ�)�� ���� �ִ� ����ġ�� ��带 ã��, �� ����ġ�� ����� ���´�.
// ������ ��� �������� dfs�� ������ ã�� max_node�� ����, �ٽ� �� �� dfs�� ���� ����ġ�� ã���� �� Ʈ���� ������ �ȴ�.
// �ð����⵵�� O(n)

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
		if (used[v[vertex][i].second] == 1) continue; // �湮�� ��� ó��
		dfs(v[vertex][i].second, cost + v[vertex][i].first);
	}
}

void solve() {
	dfs(1, 0);
	memset(used, 0, sizeof(used));
	// 1�� ��忡�� ���� ���� dfs�� �ִ� ����ġ�� ��带 ã�Ҵ�.
	// ã�� ��忡�� dfs�� ������(����ġ�� 0�̶�� �ΰ�) �ִ� ����ġ�� ��带 ã���� �״� �� Ʈ���� ������ �ȴ�.
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