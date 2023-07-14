#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 0인 부분의 좌표와 0의 개수를 저장한다.
// dfs로 벽3개를 지정한다.
// copy맵도 있어야한다.
// 방향 배열도 있어야한다.
// bfs를 돌릴 큐도 있어야한다.
// 매번 ans의 최댓값을 갱신해줘야한다.

int H, W, zeroCnt, ans;
int map[10][10];
int map_cp[10][10];
int choice[3];

struct Coord {
	int y, x;
};

vector<Coord> zeroV;
queue<Coord> twoQ;
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

void input() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) {
				zeroV.push_back({ y,x });
			}
			else if (map[y][x] == 2) {
				twoQ.push({ y,x });
			}
		}
	}
	zeroCnt = zeroV.size();
	ans = 0;
}

void copyMap() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			map_cp[y][x] = map[y][x];
		}
	}
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void floodfill() {
	int visited[10][10] = { 0, };
	int infectedCnt = 0;

	// 기존 맵의 2의 좌표가 들어있는 twoQ를 복사해서 쓴다.
	queue<Coord> q;
	q = twoQ;

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (map_cp[ny][nx] == 1 || map_cp[ny][nx] == 2) continue;

			visited[ny][nx] = 1;
			map_cp[ny][nx] = 2; // 감염
			infectedCnt++;
			q.push({ ny,nx });
		}
	}

	// 원래 0의 개수에서 감염된거(2) 빼고, 생성한 벽개수(3개) 뺀다.
	ans = max(ans, zeroCnt - infectedCnt - 3);
}

void setWall(int lev, int start) 
{
	if (lev == 3) {
		// 0,1,2 ~ zeroCnt-2,zeroCnt-1,zeroCnt <-- choice 배열 조합
		// 벽 3개 다 골랐으니 복사한 맵에 표기해야함
		copyMap();
		// 복사한 맵에 벽3개 표시
		for (int i = 0; i < 3; i++) {
			map_cp[zeroV[choice[i]].y][zeroV[choice[i]].x] = 1;
		}
		// 감염 진행
		floodfill();
		return;
	}

	for (int i = start; i < zeroCnt; i++) 
	{
		choice[lev] = i;
		setWall(lev + 1, i + 1);
	}
}

void solve() 
{
	// 벽 세우기 dfs
	setWall(0, 0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}