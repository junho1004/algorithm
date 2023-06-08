#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v[30];

void input() {
	cin >> N;
	char a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v[a - 'A'].push_back({ b - 'A', c - 'A' });
	}
}


void preorder(int tar) {
	if (tar == '.' - 65) return;

	cout << char(tar + 'A');
	preorder(v[tar][0].first);
	preorder(v[tar][0].second);
}

void inorder(int tar) {
	if (tar == '.' - 65) return;

	inorder(v[tar][0].first);
	cout << char(tar + 'A');
	inorder(v[tar][0].second);
}

void postorder(int tar) {
	if (tar == '.' - 65) return;
	
	postorder(v[tar][0].first);
	postorder(v[tar][0].second);
	cout << char(tar + 'A');
}

void solve() {
	// 'A'부터 시작
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}