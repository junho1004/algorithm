#include<iostream>
#include<algorithm>
using namespace std;

int N;
int bridge[3010];
int dp[3010];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> bridge[i];
		dp[i] = 1;
	}
}

void solve() {
	
	for (int y = 0; y < N; y++) {
		for (int x = y + 1; x < N; x++) {
			if (bridge[y] < bridge[x] && dp[x] <= dp[y]) {
				dp[x] = dp[y] + 1;
			}

		}
	}

}

int main(int argc, char** argv) {

	input();
	solve();
	int ans = -1;
	for(int k = 0; k < N; k++){
		ans = max(ans, dp[k]);
	}
	cout << ans;
}