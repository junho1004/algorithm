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
	// 목표위치가 현위치의 좌측에 있다면 -1로 가는 수 밖에 없다.
	if (K <= N) {
		ans = N - K;
		return;
	}

	// 소요시간, 현재위치 순서
	// 다음 위치로의 이동이 시간이 0인것과 1인것이 있기에 
	// 즉, 가중치가 다르기에 pq를 사용해서 걸린시간이 짧은 위치부터 탐색한다.
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
		// 0초 걸리는 now*2가 선행되어야 한다.
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