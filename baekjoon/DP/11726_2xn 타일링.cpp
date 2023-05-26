#include <iostream>
#define mod 10007;
using namespace std;


int N;
int dp[1010];
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[N];
	

	return 0;
}