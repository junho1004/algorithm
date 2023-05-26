#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
vector<int> v[1010];
bool used[1010] = { 0, };

void input() {
	cin >> N >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void dfs(int node) {
	
	for (int i = 0; i < v[node].size(); i++) {
		if (used[v[node][i]] == 0) {
			used[v[node][i]] = 1;
			dfs(v[node][i]);
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (used[i] == 0) {
			ans++;
			used[i] = 1;
			dfs(i);
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