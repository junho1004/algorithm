#include<iostream>
using namespace std;
// 10*30 * 10 * 30 * 10 * 30
// 27,000,000
// 사다리 하나 놓기
// 사다리 두개 놓기
// 사다리 세개 놓기
// 2초 512MB
// 배열이 낫다 사다리의 위치만 기록 1,1 은 1~2연결
// 3,4는 4~5연결

int H, W, cnt_ladder;
bool map[31][11];
bool ansFlag;

void input() {
	cin >> W >> H >> cnt_ladder;
	int a, b;
	for (int i = 0; i < cnt_ladder; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}
	ansFlag = 0;
}
// 세로선 5개 가로선 6개면
// 6,4가 최대 주어질 수 있다
bool play() 
{
	for (int sero = 1; sero <= W; sero++) 
	{
		int now = sero;

		
		for (int garo = 1; garo <= H; garo++) 
		{
			map[now][garo] == 0;
		}
	}
}
// 1,1가다가 1,1사다리면 1,2로
// 1,2 -> 2,2  3,2사다리면 3,3으로
// 3,3 -> 4,3 4,2사다리면 4,2로
void dfs(int lev, int cnt) {
	if (ansFlag) return;

	if (lev == cnt) 
	{
		// 사다리타고 내려가
		if (play()) ansFlag = 1;
		return;
	}

	for (int y = 1; y <= H; y++) {
		for (int x = 1; x < W; x++) {
			if (map[y][x]) continue; // 사다리이미 있다면 설치 불가
			map[y][x] = true;
			dfs(lev + 1, cnt);
			map[y][x] = false;
		}
	}
}

void solve() {
	for (int i = 0; i <= 3; i++) 
	{
		// 사다리 개수가 i 개 일때 가능?
		dfs(0, i);

		if (ansFlag) 
		{
			cout << i;
			break;
		}
	}
	cout << -1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	
	return 0;
}