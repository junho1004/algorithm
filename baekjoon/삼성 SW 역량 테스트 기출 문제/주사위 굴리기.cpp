#include <iostream>
#include <vector>
#define R 1
#define L 2
#define N 3
#define S 4
using namespace std;

int H, W, K;
int startY, startX;

int map[21][21];
vector<int> v;

// bottom, right, front, top, left, back
int dice[6];

// 우좌상하
int ditY[] = {0, 0,0,-1,1 };
int ditX[] = {0, 1,-1,0,0 };

void input() {
	cin >> H >> W >> startY >> startX >> K;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
	int t;
	for (int i = 0; i < K; i++) {
		cin >> t;
		v.push_back(t);
	}
}

void rollDice(int dir) {
	// 바닥, 오른쪽, 앞, 탑, 왼쪽, 뒤
	// 주사위 각 면에 쓰여진 숫자를 의미하는 배열
	// int dice[6];

	int bottom = dice[0]; // 현재의 바닥면의 숫자.
	switch (dir)
	{
		case R: // 우로 굴려
			dice[0] = dice[1]; // 이제 바닥은 기존의 오른쪽
			dice[1] = dice[3]; // 오른쪽은 기존의 탑
			dice[3] = dice[4]; // 탑은 기존의 왼쪽
			dice[4] = bottom; // 왼쪽은 기존의 바닥
			break;

		case L: // 좌로 굴려
			dice[0] = dice[4]; // 이제 바닥은 기존의 왼쪽
			dice[4] = dice[3]; // 왼쪽은 기존의 탑
			dice[3] = dice[1]; // 탑은 기존의 오른쪽
			dice[1] = bottom; // 오른쪽은 기존의 바닥
			break;
		case N: // 위로 굴려
			dice[0] = dice[2]; // 이제 바닥은 기존의 앞면
			dice[2] = dice[3]; // 앞면은 기존의 탑
			dice[3] = dice[5]; // 탑은 기존의 뒷면
			dice[5] = bottom; // 뒷면은 기존의 바닥
			break;
		case S: // 아래로 굴려
			dice[0] = dice[5]; // 이제 바닥은 기존의 뒷면
			dice[5] = dice[3]; // 뒷면은 기존의 탑
			dice[3] = dice[2]; // 탑은 기존의 앞면
			dice[2] = bottom; // 앞면은 기존의 바닥
			break;
	}
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

void solve() 
{
	int now = 0;
	int ny, nx;

	int nowY = startY;
	int nowX = startX;
	
	
	for (int i = 0; i < K; i++) 
	{
		int dir = v[i];
		int ny = nowY + ditY[dir];
		int nx = nowX + ditX[dir];

		// 다음 갈 곳이 맵을 나가면 넘어감
		if (isOut(ny, nx)) continue;

		rollDice(dir);

		// 다음 위치에 맵이 0이면 주사위 바닥면의 숫자가 맵에 복사된다.
		if (map[ny][nx] == 0) {
			map[ny][nx] = dice[0];
		}
		// 그렇지 않으면 맵의 숫자가 주사위 바닥면에 복사되고, 맵은 0 이된다.
		else {
			dice[0] = map[ny][nx];
			map[ny][nx] = 0;
		}

		// 매 번 주사위의 탑을 출력한다.
		cout << dice[3] << "\n";

		// 현재위치 조정
		nowY = ny;
		nowX = nx;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}