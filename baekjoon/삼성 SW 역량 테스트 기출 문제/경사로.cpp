#include <iostream>
#include <cstring>
using namespace std;

int N, L, ans;
int map[101][101];
int used[101];
void input() {
	cin >> N >> L;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}

// 다음이 같다면 넘어가
// 다음이 높다면 이전을봐
// 다음이 낮다면 이후를봐

bool canGoRow(int tar) {
	for (int x = 0; x < N - 1; x++) {
		int now = map[tar][x];
		int next = map[tar][x + 1];

		if (now == next) continue;
		else if (now == next + 1) { // 다음이 1 낮다.
			for (int k = x + 1; k < x + 1 + L; k++) {
				// 이후 것들이 맵밖 or 이미씀 or 높이가 일정하지 않음 경사로 불가
				if (k >= N || used[k]) return 0; 
				if (next != map[tar][k]) return 0;
				used[k] = 1;
			}
		}
		else if (now == next - 1) { // 다음이 1 높다.
			for (int k = x; k > x - L; k--) {
				// 이전 것들이 맵밖 or 이미씀 or 높이가 일정하지 않음 경사로 불가
				if (k < 0 || used[k]) return 0;
				if (now != map[tar][k]) return 0;
				used[k] = 1;
			}
		}
		else return 0; // 높이차가 1 초과
	}
	return 1;
}

bool canGoCol(int tar) {
	for (int y = 0; y < N - 1; y++) {
		int now = map[y][tar];
		int next = map[y + 1][tar];

		if (now == next) continue;
		else if (now == next + 1) { // 다음이 1 낮다.
			for (int k = y + 1; k < y + 1 + L; k++) {
				// 이후 것들이 맵밖 or 이미씀 or 높이가 일정하지 않음 경사로 불가
				if (k >= N || used[k]) return 0;
				if (next != map[k][tar]) return 0;
				used[k] = 1;
			}
		}
		else if (now == next - 1) { // 다음이 1 높다.
			for (int k = y; k > y - L; k--) {
				// 이전 것들이 맵밖 or 이미씀 or 높이가 일정하지 않음 경사로 불가
				if (k < 0 || used[k]) return 0;
				if (now != map[k][tar]) return 0;
				used[k] = 1;
			}
		}
		else return 0; // 높이차가 1 초과
	}
	return 1;
}

void solve() {
	// 가로
	for (int y = 0; y < N; y++) {
		if (canGoRow(y)) ans++;
		memset(used, 0, sizeof(used));
	}
	// 세로
	for (int x = 0; x < N; x++) {
		if (canGoCol(x)) ans++;
		memset(used, 0, sizeof(used));
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}