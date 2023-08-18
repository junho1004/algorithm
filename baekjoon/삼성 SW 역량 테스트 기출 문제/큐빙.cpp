#include <iostream>
using namespace std;

// 0,1,2 윗면 white == 1
// 3,4,5 앞면 red == 2
// 6,7,8 왼쪽 green == 3
// 9,10,11 아랫면 yellow == 4
// 12,13,14 뒷면 orange == 5
// 15,16,17 오른쪽 blue == 6
int n;
string cmd;
int cube[18][3];
int tmp[18][3];
void make_init_cube() {
	int color = 1;
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 3; x++) {
			cube[y][x] = color;
		}
		if ((y + 1) % 3 == 0) color++;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd[1] == '-') {
			if (cmd[0] == 'U') { // 윗면

			}
			else if (cmd[0] == 'F') { // 앞면

			}
			else if (cmd[0] == 'L') { // 왼쪽

			}
			else if (cmd[0] == 'D') { // 아래

			}
			else if (cmd[0] == 'B') { // 뒤

			}
			else if (cmd[0] == 'R') { // 오른쪽

			}
		}
		else if (cmd[1] == '+') {

		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tcCnt;
	cin >> tcCnt;

	make_init_cube();

	for (int tc = 1; tc <= tcCnt; tc++) {
		memcpy(tmp, cube, sizeof(cube));
		solve();
	}

	return 0;
}