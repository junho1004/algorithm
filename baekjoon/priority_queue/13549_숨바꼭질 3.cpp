#include <iostream>
#include <queue>
#include <vector>
#define MAX_P 100'010
using namespace std;

int N, K;
bool visited[MAX_P];
int ans;

void input() {
	cin >> N >> K;
}

void solve() {
	// ��ǥ��ġ�� ����ġ�� ������ �ִٸ� -1�� ���� �� �ۿ� ����.
	if (K <= N) {
		ans = N - K;
		return;
	}

	// �ҿ�ð�, ������ġ ����
	// ���� ��ġ���� �̵��� �ð��� 0�ΰͰ� 1�ΰ��� �ֱ⿡ 
	// ��, ����ġ�� �ٸ��⿡ pq�� ����ؼ� �ɸ��ð��� ª�� ��ġ���� Ž���Ѵ�.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,N });
	visited[N] = true;

	while (!pq.empty()) {
		int now = pq.top().second;
		int time = pq.top().first;
		pq.pop();

		if (now == K) {
			ans = time;
			break;
		}
		// 0�� �ɸ��� now*2�� ����Ǿ�� �Ѵ�.
		int dx[3] = { now * 2, now - 1, now + 1 };

		for (int i = 0; i < 3; i++) {
			if (dx[i] < 0 || dx[i] > 100000) continue;
			if (visited[dx[i]]) continue;

			if (i == 0) pq.push({ time, dx[i] });
			else pq.push({ time + 1, dx[i] });

			visited[dx[i]] = true;
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;
	return 0;
}