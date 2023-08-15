#include<iostream>
#include<vector>
#define MAX_N 101
using namespace std;

int N, x, y, d, g;
int map[MAX_N][MAX_N];

// 우 상 좌 하
int ditX[4] = { 1,0,-1,0 };
int ditY[4] = { 0,-1,0,1 };


vector<int> v;

void input() {
	cin >> N;
}

void Dragon_Curve()
{

}

void solve() {
	// 맵 y,x를 바꾸면 입력한 드래곤 커브가 맵 밖을 벗어날 수 있다.
	// 이번 문제만큼은 map[x][y]로 가야한다.

	for (int i = 0; i < N; i++) 
	{
		v.clear();
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
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	return 0;
}