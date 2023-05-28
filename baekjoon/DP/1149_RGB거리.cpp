#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1010

int N, ans;
int map[MAX_N][3];
int dp[MAX_N][3];

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
	ans = 21e8;
}

void solve() {
	for (int x = 0; x < 3; x++) {
		dp[0][x] = map[0][x];
	}

	for (int x = 1; x < N; x++) {
		dp[x][0] = min(dp[x - 1][1], dp[x - 1][2]) + map[x][0];
		dp[x][1] = min(dp[x - 1][0], dp[x - 1][2]) + map[x][1];
		dp[x][2] = min(dp[x - 1][0], dp[x - 1][1]) + map[x][2];
	}


	int de = 1;
	for (int x = 0; x < 3; x++) {
		ans = min(ans, dp[N - 1][x]);
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
