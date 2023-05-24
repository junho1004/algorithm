#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

struct Node {
	int start;
	int end;
};
vector<Node> v;

void input() {
	int tmp1, tmp2;
	cin >> N;
	while (N--) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1, tmp2 });
	}
}
// 끝나는 시간이 같다면 먼저 시작하는 회의부터 진행해야한다.
// 반례
// 3
// 3 3
// 3 4
// 1 3
bool cmp(Node t, Node v) {
	if (t.end == v.end) return t.start < v.start;
	return t.end < v.end;
}

void solve() {
	sort(v.begin(), v.end(), cmp);

	int now_time = v[0].end;
	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].start >= now_time) {
			now_time = v[i].end;
			cnt++;
		}
	}
	cout << cnt;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}