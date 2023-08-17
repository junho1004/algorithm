#include <iostream>
using namespace std;

int N, M;
int map[51][51];

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void solve() {

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	return 0;
}