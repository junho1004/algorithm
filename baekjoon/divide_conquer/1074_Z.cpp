#include <iostream>
using namespace std;

int N, tarY, tarX, ans;
void input() {
	ans = 0;
	cin >> N >> tarY >> tarX;
}

void solve(int y, int x, int size) {
	if (y == tarY && x == tarX) {
		cout << ans;
		return;
	}

	// tarY, tarX가 현재 사분면에 존재한다면
	
	if (tarY < y + size && tarY >= y && tarX < x + size && tarX >= x) {

		// 1사분면 탐색
		solve(y, x, size / 2);
		// 2사분면 탐색
		solve(y, x + size / 2, size / 2);
		// 3사분면 탐색
		solve(y + size / 2, x, size / 2);
		// 4사분면 탐색
		solve(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}

	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve(0, 0, (1 << N));
	
	return 0;
}