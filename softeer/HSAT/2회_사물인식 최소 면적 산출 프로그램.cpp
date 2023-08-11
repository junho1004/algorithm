#include<iostream>
#include<vector>
using namespace std;

int N, K, ans;
vector<pair<int, int>> v[21];

void input() {
	cin >> N >> K;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v[c - 1].push_back({ b,a });
	}
	ans = 1e8;
}

void dfs(int lev, int maxY, int minY, int maxX, int minX) {
	if (lev == K) {
		int square = (maxY - minY) * (maxX - minX);
		ans = min(ans, square);
		return;
	}

	for (int i = 0; i < v[lev].size(); i++) {
		int ny = v[lev][i].first;
		int nx = v[lev][i].second;
		int maxY2 = maxY; int minY2 = minY;
		int maxX2 = maxX; int minX2 = minX;
		maxY2 = max(maxY2, ny);
		minY2 = min(minY2, ny);
		maxX2 = max(maxX2, nx);
		minX2 = min(minX2, nx);
		int square = (maxY2 - minY2) * (maxX2 - minX2);
		if (ans <= square) continue;
		dfs(lev + 1, maxY2, minY2, maxX2, minX2);

	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	input();
	dfs(0, -1e8, 1e8, -1e8, 1e8);
	cout << ans;
	return 0;
}