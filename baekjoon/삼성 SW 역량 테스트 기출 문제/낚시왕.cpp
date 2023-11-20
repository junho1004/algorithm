#include <iostream>
#include <cstring>
using namespace std;


// (H * W)마리 상어 이동 * H(낚시꾼 탐색) * W(마지막 열까지) == 1억
// 상어의 속력은 최대 1000, 1000번을 반복하는 것이 아니라
// 적절한 연산을 통해 반복을 줄여야한다.
// 각 상어마다 이동이 끝날 때 카피맵에 이미 상어가 있다면 크기 비교를 해줘야한다.
// 속력 % ((H - 1 또는 W - 1) x 2)[제자리] = 현 위치에서 움직여야하는 거리
// 맵(1부터 이용)을 두개 사용해서 복사하면서 진행.


int H, W, M;
int fish_cnt = 0;

struct Node {
	int speed, dir, weigh;
};
Node map[105][105];
Node CopyMap[105][105];

// 1,2,3,4 상 하 우 좌
int dit[] = { 0,-1,1,1,-1 };

void input() {
	cin >> H >> W >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		map[r][c] = { s,d,z };
	}
}

void move_eat_Shark() {
	for (int y = 1; y <= H; y++) {
		for (int x = 1; x <= W; x++) {
			if (map[y][x].weigh != 0) // 상어 있다면
			{
				int shark_speed = map[y][x].speed;
				int shark_weigh = map[y][x].weigh;
				int shark_dir = map[y][x].dir;
				int move_dist; // 움직여야하는 거리
				int now;

				if (shark_dir == 1 || shark_dir == 2) // 상하 방향
				{
					now = y;
					move_dist = shark_speed % ((H - 1) * 2);
					while (move_dist)
					{
						if (now == 1) shark_dir = 2;
						else if (now == H) shark_dir = 1;
						now = now + dit[shark_dir]; // 상 or 하						
						move_dist--;
					}

					if (CopyMap[now][x].weigh < shark_weigh) { // 잡아먹기 or 넘어가기
						CopyMap[now][x] = { shark_speed, shark_dir, shark_weigh };
					}
				}

				else // 좌우 방향 
				{
					now = x;
					move_dist = shark_speed % ((W - 1) * 2);
					while (move_dist)
					{
						if (now == 1) shark_dir = 3;
						else if (now == W) shark_dir = 4;
						now = now + dit[shark_dir]; // 우 or 좌
						move_dist--;
					}
					if (CopyMap[y][now].weigh < shark_weigh) { // 잡아먹기 or 넘어가기
						CopyMap[y][now] = { shark_speed, shark_dir, shark_weigh };
					}
				}

			}
		}
	}
}


void fishing(int tarCol) {
	for (int y = 1; y <= H; y++) {
		if (map[y][tarCol].weigh != 0) { // 상어 있다면
			fish_cnt += map[y][tarCol].weigh; // 상어 무게 추가
			map[y][tarCol] = { 0,0,0 }; // 상어 잡았으면 초기화
			return; // 한마리 잡았으면 빠져나와
		}
	}
}

void Copy() {
	for (int y = 1; y <= H; y++) {
		for (int x = 1; x <= W; x++) {
			map[y][x] = CopyMap[y][x];
		}
	}
}

void solve()
{
	for (int x = 1; x <= W; x++) {
		fishing(x);

		memset(CopyMap, 0, sizeof(CopyMap));

		move_eat_Shark();

		Copy();
	}
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << fish_cnt;
	return 0;
}