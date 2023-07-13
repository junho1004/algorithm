#include <iostream>
#include <algorithm>
using namespace std;

int H, W, ans;
int map[501][501];
int visited[501][501];

// 상하좌우
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void dfs(int lev, int sum, int nowY, int nowX) {
	if (lev == 3) {
		ans = max(ans, sum);
		return;
	}

	// 상하좌우
	for (int i = 0; i < 4; i++) {
		int ny = nowY + ditY[i];
		int nx = nowX + ditX[i];
		if (visited[ny][nx] == 1) continue;
		if (isOut(ny, nx)) continue;

		visited[ny][nx] = 1;
		dfs(lev + 1, sum + map[ny][nx], ny, nx);
		visited[ny][nx] = 0;

	}
}

void findException(int y, int x) {
	int cnt = 0;
	int sum = map[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + ditY[i];
		int nx = x + ditX[i];
		if (isOut(ny, nx)) continue;

		sum += map[ny][nx];
		cnt++;
	}

	// ㅓㅏㅗㅜ 도형을 하나도 못만든다.
	if (cnt < 3) return;

	// 딱 하나 만들 수 있다.
	else if (cnt == 3) {
		ans = max(ans, sum);
	}

	// 4개 다 만들 수 있다.
	// 십자모양으로 더해놓은 모양에서 하나씩 빼주면서 최댓값 확인
	else if (cnt == 4) {
		for (int i = 0; i < 4; i++) {
			int ny = y + ditY[i];
			int nx = x + ditX[i];
			ans = max(ans, sum - map[ny][nx]);
		}
	}

}

void solve() {

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {

			visited[y][x] = 1;
			dfs(0, map[y][x], y, x);
			visited[y][x] = 0;

			// ㅓㅏㅗㅜ 모양 찾기
			findException(y, x);

		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;
	return 0;
}