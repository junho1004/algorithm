#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100'010
using namespace std;

int N, ans;
int map[2][MAX_N];
int dp[2][MAX_N];

void init() {
	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));
	ans = 0;
}

void input() {
	cin >> N;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void solve() {
	dp[0][0] = map[0][0];
	dp[1][0] = map[1][0];
	dp[0][1] = map[0][1] + dp[1][0];
	dp[1][1] = map[1][1] + dp[0][0];

	//50 10 100
	//30 50 70
	//
	//1  2  3
	//4  5  6
	//총 4가지 경우의 수
	//1->5->3 // 1->6 // 4->2->6 // 4-> 3 

	//dp배열
	//50 40 200
	//30 100 110

	for (int i = 2; i < N; i++) {
		dp[0][i] = map[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = map[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	ans = max(dp[0][N - 1], dp[1][N - 1]);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		init();
		input();
		solve();
		cout << ans << "\n";
	}

	return 0;
}