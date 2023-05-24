#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
unordered_map<string, int> um;
vector<string> v;

void input() {
	cin >> N >> M;
	string temp;
	while (N--) {
		cin >> temp;
		um[temp] = 1;
	}
	while (M--) {
		cin >> temp;
		if (um.count(temp)) {
			v.push_back(temp);
		}
	}
}

void solve() {
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto i : v) {
		cout << i << "\n";
	}
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