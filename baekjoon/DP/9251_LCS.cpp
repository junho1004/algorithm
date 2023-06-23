#include <iostream>
#define MAX_N 1010
using namespace std;

string str1, str2;
int dp[MAX_N][MAX_N];

void input() {
	cin >> str1 >> str2;
}

void solve() {
	for (int x = 1; x <= str1.size(); x++) {
		for (int y = 1; y <= str2.size(); y++) {
			if (str1[x - 1] == str2[y - 1]) {
				dp[y][x] = dp[y - 1][x - 1] + 1;
			}
			else {
				dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]);
			}
		}
	}
	cout << dp[str2.size()][str1.size()];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	int de = 1;
	return 0;
}