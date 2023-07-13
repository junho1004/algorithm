#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int N, B, C;
vector<int> v;
ll ans;

void input() {
	cin >> N;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		v.push_back(t);
	}
	cin >> B >> C;
	ans = 0;
}

// 최대 1,000,000,000,000

void solve() {

	for (int i = 0; i < N; i++) {
		int cnt = 1; // 감독관 1명
		
		int tmp = v[i] - B;

		//감독관 한명으로 충당가능하다면
		if (tmp <= 0) { ans++; continue; }

		cnt += (tmp / C);

		//나눠 떨어지지 않으면 한 명 추가
		if (tmp % C != 0) cnt += 1;

		ans += cnt;
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;

	return 0;
}