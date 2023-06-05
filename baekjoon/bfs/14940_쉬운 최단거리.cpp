#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 1010
using namespace std;

int H, W;
int map[MAX_N][MAX_N];
int used[MAX_N][MAX_N];

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Coord {
	int y;
	int x;
};
queue<Coord> q;
Coord start;

void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				start.y = y;
				start.x = x;
				q.push({ start.y, start.x });
			}
		}
	}

}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void solve() {
	fill(&used[0][0], &used[MAX_N - 1][MAX_N], -1); // 출력할 모든 맵을 -1로 채우기
	used[start.y][start.x] = 0; // 시작점은 0

	while (!q.empty()) 
	{
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue; // 맵 밖
			if (map[ny][nx] == 0) continue; // 원래 갈 수 없는 땅
			if (used[ny][nx] != -1) continue; // 이미 간 땅 방문 처리
			
			used[ny][nx] = used[now.y][now.x] + 1; // 최종 거리맵에 표시
			q.push({ ny, nx });
		}
	}
	
	

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == 0) cout << 0 << " "; // 원래 갈 수 없는 땅은 0으로 출력
			else cout << used[y][x] << " "; 
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	return 0;
}