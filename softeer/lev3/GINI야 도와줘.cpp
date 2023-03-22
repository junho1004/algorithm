#include<iostream>
#include<queue>
#include<string>
using namespace std;

string map[55];
int used[55][55];

int R, C, ans;
int ditY[4] = { -1, 1, 0, 0 };
int ditX[4] = { 0, 0, -1, 1 };

struct Node {
	int y, x;
};

queue<Node> startQ;
queue<Node> rainQ;

void init() {
	for (int y = 0; y < 55; y++) {
		map[y] = "";
		for (int x = 0; x < 55; x++) {
			used[y][x] = 0;
		}
	}
	ans = 0;

	while (!startQ.empty()) {
		startQ.pop();
	}
	while (!rainQ.empty()) {
		rainQ.pop();
	}
}

void input() {
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		cin >> map[y];

		for (int x = 0; x < C; x++) {
			if (map[y][x] == '*') {
				rainQ.push({ y, x });
				used[y][x] = 2;
			}
			else if (map[y][x] == 'W') {
				startQ.push({ y, x });
				used[y][x] = 1;
			}

		}

	}
}

bool isOut(int ny, int nx) {
	return ny < 0 || nx < 0 || ny >= R || nx >= C;
}

bool solve() {
	int ansFlag = 0;

	while (1) {

		// 소나기 확장
		int limit = rainQ.size();

		for (int k = 0; k < limit; k++) {
			Node nowRain = rainQ.front();
			rainQ.pop();

			for (int i = 0; i < 4; i++) {
				int ny = nowRain.y + ditY[i];
				int nx = nowRain.x + ditX[i];
				if (isOut(ny, nx)) continue;
				if (map[ny][nx] == 'X' || map[ny][nx] == 'H') continue;
				if (used[ny][nx] == 2) continue;
				used[ny][nx] = 2;

				rainQ.push({ ny,nx });
			}
		}

		int limitS = startQ.size();

		for (int k = 0; k < limitS; k++) {
			Node now = startQ.front();
			startQ.pop();
			for (int i = 0; i < 4; i++) {
				int ny = now.y + ditY[i];
				int nx = now.x + ditX[i];
				if (isOut(ny, nx)) continue;
				if (map[ny][nx] == 'X') continue;
				if (used[ny][nx] >= 1) continue;
				used[ny][nx] = 1;

				if (map[ny][nx] == 'H') ansFlag = 1;
				startQ.push({ ny,nx });
			}
		}

		ans++;
		if (ansFlag == 1) return ans;
		if (startQ.empty()) break;
	}

	return 0;
}

int main(int argc, char** argv)
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	init();
	input();
	if (solve()) cout << ans;
	else cout << "FAIL";

	return 0;
}