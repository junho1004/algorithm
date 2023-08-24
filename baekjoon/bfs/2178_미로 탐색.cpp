#include <iostream>
#include <queue>
#define MAX_N 101
using namespace std;

int H, W, ans;
string map[MAX_N];

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };
struct Coord {
	int y, x;
};
queue<Coord> q;
int visited[MAX_N][MAX_N];

void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		cin >> map[y];
	}
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void solve()
{
	q.push({ 0,0 });
	visited[0][0] = 1;
	bool ansFlag = 0;
	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == '0') continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;

			if (ny == H - 1 && nx == W - 1)
			{
				ans = visited[ny][nx]; // 경로
				ansFlag = 1;
				break;
			}
			q.push({ ny, nx });
		}

		if (ansFlag) break;
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