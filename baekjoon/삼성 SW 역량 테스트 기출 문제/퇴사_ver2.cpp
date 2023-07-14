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


void solve(int day, int profit) {
	
	if (day > N + 1) return;
	if (day == N + 1) {
		ans = max(ans, profit);
		return;
	}

	// 포함하면 시간과 돈을 더 해줌
	solve(day + v[day].first, profit + v[day].second);

	// 포함하지 않으면 그다음으로 넘어감
	solve(day + 1, profit);

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve(1,0);
	cout << ans;
	return 0;
}