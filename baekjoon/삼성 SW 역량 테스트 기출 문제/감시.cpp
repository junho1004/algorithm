#include <iostream>
#include <vector>
#include <algorithm>
#define looked 9
using namespace std;

// 1 ~ 5번 CCTV의 회전 경우의 수는
// 4 2 4 4 1
// dfs를 돌리면서 방향을 잡아야한다.
// 0의 개수를 세어놓고 감시 프로그램이 끝나고 바뀐 것의 개수를 뺌
// 원본맵과 카피맵을 따로 두어야함.

int H, W, cntZero, cntCCTV, ans;
int map[10][10];

struct Node {
	int y, x, num;
};
Node CCTVs[10];
// v의 인덱스는 CCTV의 종류가 아닌 번호이다.
vector<vector<int>> v(10);

// 상우하좌
int ditY[] = { -1,0,1,0 };
int ditX[] = { 0,1,0,-1 };

void input() {
	cntCCTV = 0;
	cntZero = 0;
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x] == 6) continue; 
			else if (map[y][x] == 0) cntZero++;
			else {
				CCTVs[cntCCTV] = { y,x,map[y][x] };
				cntCCTV++;
			}
		}
	}
	ans = cntZero;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void fillMap() {
	int copyMap[10][10];
	int cntLooked = 0;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			copyMap[y][x] = map[y][x];
		}
	}

	for (int k = 0; k < cntCCTV; k++) {
		int nowY = CCTVs[k].y;
		int nowX = CCTVs[k].x;

		for (int i = 0; i < v[k].size(); i++) 
		{
			int dir = v[k][i];

			for (int j = 1; j < 8; j++) {
				int ny = nowY + ditY[dir] * j;
				int nx = nowX + ditX[dir] * j;
				if (isOut(ny, nx)) break;
				if (copyMap[ny][nx] == 6) break;
				if (copyMap[ny][nx] == 0) {
					copyMap[ny][nx] = looked;
					cntLooked++;
				}
			}
		}
	}

	ans = min(ans, cntZero - cntLooked);
}

void dfs(int lev) {
	if (ans == 0) return;

	if (lev == cntCCTV) {
		fillMap();
		return;
	}

	if (CCTVs[lev].num == 1) {
		for (int i = 0; i < 4; i++) {
			v[lev].push_back(i);
			dfs(lev + 1);
			v[lev].clear();
		}
	}
	else if (CCTVs[lev].num == 2) {
		for (int i = 0; i < 2; i++) {
			v[lev].push_back(i); // 상하
			v[lev].push_back(i + 2); // 하좌
			dfs(lev + 1);
			v[lev].clear();
		}
	}
	else if (CCTVs[lev].num == 3) {
		for (int i = 0; i < 4; i++) {
			v[lev].push_back(i);
			v[lev].push_back((i + 1) % 4); //직각으로 넣기위함
			dfs(lev + 1);
			v[lev].clear();
		}
	}
	else if (CCTVs[lev].num == 4) {
		for (int i = 0; i < 4; i++) {
			for (int j = i; j < i + 3; j++) {
				v[lev].push_back(j % 4); // 3방향
			}
			dfs(lev + 1);
			v[lev].clear();
		}
	}
	else if (CCTVs[lev].num == 5) {
		for (int i = 0; i < 4; i++) {
			v[lev].push_back(i); // 4방향 모두 넣기
		}
		dfs(lev + 1);
		v[lev].clear();
	}

}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	dfs(0);
	cout << ans;
	return 0;
}