#include <iostream>
#include <algorithm>
#define MAX_N 1010
using namespace std;

int N, ans;
int arr[MAX_N];
int dp[MAX_N];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	ans = -1;
}

void solve() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}