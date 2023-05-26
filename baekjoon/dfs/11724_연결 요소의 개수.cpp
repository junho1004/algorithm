#include <iostream>
using namespace std;

int N, M, ans;
bool map[1010][1010] = { 0, };
bool used[1010] = { 0, };

void input() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	ans = 0;
}

void dfs(int node) {
	for (int i = 1; i <= N; i++) {
		if (map[node][i] == 1 && used[i] == 0) {
			used[i] = 1;
			dfs(i);
		}
	}
}

void solve() {
	for (int y = 1; y <= N; y++) {
		if (used[y] == 0) {
			ans++;
			used[y] = 1;
			dfs(y);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	solve();
	cout << ans;
	
	return 0;
}