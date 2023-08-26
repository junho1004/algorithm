#include <iostream>
#include <cstring>
#define MAX_N 51
using namespace std;

int H, W, T, ans;
int map[MAX_N][MAX_N];
int cpymap[MAX_N][MAX_N];
// 상 우 하 좌
int ditY[] = { -1,0,1,0 };
int ditX[] = { 0,1,0,-1 };
int startY;
void input()
{
	cin >> H >> W >> T;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
}

void spreadDirt() 
{
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++){
			int spread_cnt = 0;
			if (map[y][x] > 0) 
			{
				for (int i = 0; i < 4; i++) {
					int ny = y + ditY[i];
					int nx = x + ditX[i];
					if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] == -1) continue;
					spread_cnt++;
					cpymap[ny][nx] += map[y][x] / 5;
				}
			}
			cpymap[y][x] += map[y][x] - (map[y][x] / 5) * spread_cnt;
		}
	}
}


void cleanAir() 
{
	int y = startY - 1;
	int x = 0;
	int dir = 0;
	int ny, nx;
	while (1) // 위쪽 반시계, 시계방향으로 돌아야지 값 갱신이 편하다.
	{
		ny = y + ditY[dir];
		nx = x + ditX[dir];
		if(ny < 0 || nx < 0 || ny > startY || nx >= W )
		{
			dir = (dir + 1) % 4; // 0 1 2 3, 0 1 2 3
			continue;
		}
		cpymap[y][x] = cpymap[ny][nx];
		y = ny;
		x = nx;
		if (y == startY && x == 1) {
			cpymap[y][x] = 0;
			break;
		}
	}

	
	y = startY + 2;
	x = 0;
	dir = 2;
	while (1) // 아래쪽 시계, 반시계방향으로 돌아야지 값 갱신이 편하다.
	{
		ny = y + ditY[dir];
		nx = x + ditX[dir];
		if (ny < 0 || nx < 0 || ny >= H || nx >= W || ny <= startY)
		{
			dir = (dir + 3) % 4; // 2 1 0 3, 2 1 0 3 
			continue;
		}
		cpymap[y][x] = cpymap[ny][nx];
		y = ny;
		x = nx;
		if (y == startY + 1 && x == 1) {
			cpymap[y][x] = 0;
			break;
		}
	}
}

void copyMap() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			map[y][x] = cpymap[y][x];
		}
	}
}

void solve()
{
	for (int y = 0; y < H; y++) {
		if (map[y][0] == -1) {
			startY = y;
			break;
		}
	}

	while (T--)
	{
		memset(cpymap, 0, sizeof(cpymap));
		spreadDirt();
		cleanAir();
		copyMap();
	}
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			ans += map[y][x];
		}
	}
	ans += 2; // -2가 더해짐

}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	
	return 0;
}