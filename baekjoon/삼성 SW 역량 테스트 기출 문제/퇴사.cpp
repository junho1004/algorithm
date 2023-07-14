#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<pair<int, int>> v;
int dp[20];

void input() {
	cin >> N;
	int a, b;

	v.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	ans = 0;
}


void solve() {
	int deadline;
	for (int day = N; day >= 1; day--)
	{
		deadline = day + v[day].first;
		if (deadline > N + 1) {
			// 상담 불가
			dp[day] = dp[day + 1];
		}
		else {
			// 상담 가능, 이때까지 찾아온 최댓값과 새로운 최댓값 비교
			dp[day] = max(dp[day + 1], dp[deadline] + v[day].second);
		}
	}
	
	cout << dp[1];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}