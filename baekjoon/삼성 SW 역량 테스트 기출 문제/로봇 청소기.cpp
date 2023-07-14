#include <iostream>
#include <queue>
#define Cleaned 2
using namespace std;

int H, W, ans;
int startY, startX, T;
int map[51][51];

// 상 우 하 좌
int ditY[] = { -1,0,1,0 };
int ditX[] = { 0,1,0,-1 };

struct Coord {
	int y, x;
	int dir;
};

queue<Coord> q;

void input() {
	cin >> H >> W;
	cin >> startY >> startX >> T;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}

void solve() {
	// 맵의 테두리는 모두 벽이다. 나가는 거 처리할 필요없다.
	// 0 : 청소 안된 곳
	// 1 : 벽
	// 2 : 청소된 곳
	q.push({ startY, startX, T });
	
	int turn_flag = 0;
	int ny, nx;

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();
		int dir = now.dir;

		turn_flag = 0;
		if (map[now.y][now.x] == 0) {
			map[now.y][now.x] = Cleaned;
			ans++;
		}
		
		// 상 우 하 좌
		for (int i = 0; i < 4; i++) {
			ny = now.y + ditY[i];
			nx = now.x + ditX[i];
			if (map[ny][nx] == 0) {
				turn_flag = 1;
				break;
			}
		}

		// 빈 곳이 있다. 일단 반시계 회전
		if (turn_flag) {
			dir = (dir + 3) % 4;
			ny = now.y + ditY[dir];
			nx = now.x + ditX[dir];
			// 다음 갈 곳이 청소되지 않았다면 전진
			if (map[ny][nx] == 0) {
				q.push({ ny, nx, dir });
			}
			// 벽이거나 청소되었다면 제자리에서 반시계로 돌린 상태를 큐에 푸시
			else {
				q.push({ now.y, now.x, dir });
			}
		}
		// 후진 or 멈춤
		else {
			dir = (dir + 2) % 4;
			ny = now.y + ditY[dir];
			nx = now.x + ditX[dir];
			// 후진 불가
			if (map[ny][nx] == 1) return;
			// 벽만 아니라면 방향 유지한채로 후진
			else {
				q.push({ ny, nx, now.dir });
			}
		}

	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;
	return 0;
}