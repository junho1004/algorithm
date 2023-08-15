#include<iostream>
#include<vector>
#define MAX_N 101
using namespace std;

int N, x, y, d, g, ans;
int map[MAX_N][MAX_N];

// 우 상 좌 하
int ditX[4] = { 1,0,-1,0 };
int ditY[4] = { 0,-1,0,1 };

vector<int> v;

void input() {
	cin >> N;
	ans = 0;
}

// 2,7에 3방향 입력이면
// 첫 벡터 방향 3
// 0세대 2,8(3)
// 1세대 2,8(3)=>3,8(0)
// 2세대 2,8(3) 3,8(0)=>3,7(1) 4,7(0)
// 3세대 2,8(3) 3,8(0) 3,7(1) 4,7(0)=>4,6(1) 3,6(2) 3,5(1) 4,5(0)

// 3
// 3 0
// 3 0 1 0
// 3 0 1 0 1 2 1 0
void Dragon_Curve()
{
	int size = v.size();
	// 벡터의 끝에서부터(끝점) 회전한다기 보다는 이전 방향을 시계방향으로 바꿔가며 그려나간다고 보면 된다.
	for (int i = size - 1; i >= 0; i--)
	{
		int dir = (v[i] + 1) % 4;
		x += ditX[dir];
		y += ditY[dir];
		map[x][y] = 1;

		v.push_back(dir);
	}
}

// map[y][x]기준 자기자신, 오른쪽, 하단, 대각하단이 모두 1인경우 정사각형 하나가 있다고 표현할 수 있다.
void getAns() {
	for (int y = 0; y < MAX_N; y++) {
		for (int x = 0; x < MAX_N; x++) {
			if (map[y][x] && map[y + 1][x] && map[y][x + 1] && map[y + 1][x + 1]) ans++;
		}
	}
}

void solve() {
	// 맵 y,x를 바꾸면 입력한 드래곤 커브가 맵 밖을 벗어날 수 있다.
	// 이번 문제만큼은 map[x][y]로 가야한다.
	// 예제의 맵과 map은 행과 열이 바뀌어있어 그림대로 표현이 안된다.

	for (int i = 0; i < N; i++)
	{
		v.clear();

		// 하나의 커브에 대해 세대만큼 진행
		cin >> x >> y >> d >> g;
		map[x][y] = 1;

		// 0 세대 기록
		x += ditX[d];
		y += ditY[d];
		map[x][y] = 1;
		v.push_back(d);

		// 세대만큼 커브를 시켜야햔다.
		while (g--)
		{
			Dragon_Curve();
		}
	}

	getAns();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}