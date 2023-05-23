#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int N, M;
unordered_map<int, string> um;
unordered_map<string, int> um2;

void input() {
	cin >> N >> M;
	string temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		um[i] = temp;
		um2[temp] = i;
	}
}

void solve() {
	string quest;

	while (M--) {
		cin >> quest;
		// 숫자일 때
		if (quest[0] >= '0' && quest[0] <= '9') {
			int tar = stoi(quest);
			cout << um[tar] << "\n";
		}
		// 문자일 때
		else {
			cout << um2[quest] << "\n";
		}
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