#include <iostream>
using namespace std;

int N;
char arr[30][2];

void input() {
	cin >> N;
	// root는 순서대로 입력되기 때문에 A == 0 이라고 가정
	char root, left, right;
	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		arr[root - 'A'][0] = left;
		arr[root - 'A'][1] = right;
	}
}

void pre(char tar) {
	if (tar == '.') return;

	cout << tar;
	pre(arr[tar - 'A'][0]); // 왼쪽 자식
	pre(arr[tar - 'A'][1]); // 오른쪽 자식
}

void in(char tar) {
	if (tar == '.') return;

	in(arr[tar - 'A'][0]);
	cout << tar;
	in(arr[tar - 'A'][1]);
}

void post(char tar) {
	if (tar == '.') return;

	post(arr[tar - 'A'][0]);
	post(arr[tar - 'A'][1]);
	cout << tar;
}

void solve() {
	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	solve();
	return 0;
}