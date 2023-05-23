#include<iostream>
#include<queue>
#define maxn 200010
using namespace std;

int N, K, ans;
int used[maxn] = { 0, };

void input() {
	cin >> N >> K;
}

void solve() {
	// 목표치가 내 위치보다 작거나 같을 경우 갈 수 있는 방법은 한 칸 씩 가는거
	if (K <= N) {
		cout << N - K;
		return;
	}

	queue<int> q;
	q.push(N);
	// used배열에 걸린 시간을 넣는다.
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) break;
		int dx[3] = { now - 1,now + 1,now * 2 };

		for (int i = 0; i < 3; i++) {
			if (used[dx[i]] == 0 && 0 <= dx[i] && dx[i] <= 100000) {
				q.push(dx[i]);
				used[dx[i]] = used[now] + 1;
			}
		}
	}
	cout << used[K];

}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	
	return 0;
}