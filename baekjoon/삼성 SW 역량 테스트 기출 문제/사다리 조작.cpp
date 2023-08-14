#include<iostream>
using namespace std;
// 조합을 이용해서 중복 없이 사다리를 놓을 2차원 좌표를 뽑는다.
// (10 * 30) C0 + (10 * 30) C1 + (10 * 30) C2 + (10 * 30) C3
// 1 + 300 + 44,850 + 4,455,100
// 사다리 안 놓기
// 사다리 하나 놓기
// 사다리 두개 놓기
// 사다리 세개 놓기
// 2초 512MB
// 배열이 낫다 사다리의 위치만 기록
// 1,1 은 1~2연결
// 3,4는 4~5연결

int H, W, cnt_ladder;
bool map[32][12];
bool ansFlag;
int now_ladder_cnt;

void input() {
	cin >> W >> cnt_ladder >> H;
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
	for (int line = 1; line <= W; line++)
	{
		int flag = 0;
		int sero = line;
		int garo = 0;

		for (int garo = 0; garo < H; garo++) {
			// 오른쪽
			if (map[garo + 1][sero]) sero++;
			// 왼쪽
			else if (map[garo + 1][sero - 1]) sero--;

		}

		// 시작라인과 끝라인이 같지 않으면 즉시 종료.
		if (line != sero) return 0;
	}
	// 모두 다 통과하면 합격
	return 1;
}


void dfs(int lev, int startY, int startX) {
	if (ansFlag) return;

	if (now_ladder_cnt == lev)
	{
		// 사다리타고 내려가
		if (play()) ansFlag = 1;
		return;
	}

	// 조합(used + start)
	for (int y = startY; y <= H; y++) {
		for (int x = startX; x < W; x++) {
			// 사다리가 이미 있다면(자리 양옆 포함) 설치 불가
			if (map[y][x] || map[y][x - 1] || map[y][x + 1]) continue;
			map[y][x] = true;
			dfs(lev + 1, y, x);
			map[y][x] = false;
		}
		startX = 0; // 중요!!!
	}
}

void solve() {
	for (int i = 0; i <= 3; i++)
	{
		now_ladder_cnt = i;
		// 사다리 개수가 i 개 일때 가능?
		dfs(0, 1, 1);

		if (ansFlag)
		{
			cout << now_ladder_cnt;
			return;
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