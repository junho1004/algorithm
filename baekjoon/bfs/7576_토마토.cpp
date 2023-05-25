#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int H, W;
int map[1010][1010] = { 0, };

enum {
	ripen = 1,
	unripen = 0,
	no_plant = -1
};

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

int cnt_ripen, cnt_no_plant, day;

struct Coord {
	int y, x;
};

queue<Coord> q;

void input() {
	cin >> W >> H;
	cnt_ripen = cnt_no_plant = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			// 익어있는 토마토 개수
			if (map[y][x] == ripen) {
				cnt_ripen++;
				q.push({ y, x});
			}
			// 안심어져있는 곳 개수
			else if (map[y][x] == no_plant) {
				cnt_no_plant++;
			}
		}
	}
	day = -1e9;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void solve() {
	// 이미 모두 익어있는 상태
	int size = H * W;
	if (size == cnt_ripen + cnt_no_plant) {
		cout << 0;
		return;
	}

	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		// 날짜 최댓값 갱신
		day = max(day, map[now.y][now.x]);

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			// 맵 밖
			if (isOut(ny, nx)) continue;
			// 심어지지 않은 곳
			if (map[ny][nx] == no_plant) continue;
			// 이미 간 곳
			if (map[ny][nx] >= 1) continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			cnt_ripen++;
			q.push({ ny,nx });
		}
	}

	// 모두 익을 때
	if (size == cnt_ripen + cnt_no_plant) {
		cout << day - 1;
	}
	// 안 익는거 있을 때
	else cout << -1;
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