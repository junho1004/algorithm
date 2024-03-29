#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int path[10];
int used[10];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void dfs(int lev)
{
	if (lev == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = num[i];
		dfs(lev + 1);
		used[i] = 0;

	}
}

void solve() {
	sort(num, num + N);

	dfs(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}