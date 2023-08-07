#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int N;
int K;
int ans;

struct Coord {
	int x;
	int y;
	int k;
};

struct Rect {
	int l;
	int r;
	int t;
	int b;
};


int min(int a, int b) {
	return a > b ? b : a;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int area(int x1, int y1, int x2, int y2) {
	if (x1 > x2) {
		int t = x1;
		x1 = x2;
		x2 = t;
	}
	if (y1 > y2) {
		int t = y1;
		y1 = y2;
		y2 = t;
	}

	return (x2 - x1) * (y2 - y1);
}

int area(Rect r) {
	return area(r.l, r.t, r.r, r.b);
}

int f(vector<vector<pair<int, int>>>& colors, int cur, Rect rect) {
	if (cur > K) return area(rect);

	for (int i = 0; i < colors[cur].size(); ++i) {
		Rect r = rect;
		if (cur == 1) {
			r.l = colors[cur][i].first;
			r.r = colors[cur][i].first;
			r.t = colors[cur][i].second;
			r.b = colors[cur][i].second;
		}
		else {
			r.l = min(r.l, colors[cur][i].first);
			r.r = max(r.r, colors[cur][i].first);
			r.t = min(r.t, colors[cur][i].second);
			r.b = max(r.b, colors[cur][i].second);

			if (ans <= area(r)) continue;
		}

		ans = min(ans, f(colors, cur + 1, r));
	}

	return ans;
}


int main() {
	cin >> N;
	cin >> K;

	vector<Coord> points(N);
	vector<vector<pair<int, int>>> colors(K + 1);
	for (int i = 0; i < N; ++i) {
		int x, y, k;
		cin >> x >> y >> k;

		points[i].x = x;
		points[i].y = y;
		points[i].k = k;
		colors[k].push_back({ x, y });
	}

	ans = 987654321;
	f(colors, 1, Rect());

	cout << ans;
	return 0;
}