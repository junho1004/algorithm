#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M, ans;
int startRy, startRx, startBy, startBx;
string map[11];

struct Coord {
	int Ry, Rx;
	int By, Bx;
	int dir;
	int lev;
};

// 1234 상하좌우
int ditY[] = { 0,-1,1,0,0 };
int ditX[] = { 0,0,0,-1,1 };

queue<Coord> q;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int y = 1; y < N - 1; y++) {
		for (int x = 1; x < M - 1; x++) {

			if (map[y][x] == 'R') {startRy = y; startRx = x;}
			else if (map[y][x] == 'B') { startBy = y; startBx = x; }
		}
	}

}

int move(int ry, int rx, int by, int bx, int dir, int lev) {

	int Rdist, Bdist, Rflag, Bflag;
	Rdist = Bdist = Rflag = Bflag = 0;

	while(1)
	{
		ry += ditY[dir];
		rx += ditX[dir];
		Rdist++;

		if (map[ry][rx] == '#') {
			ry -= ditY[dir];
			rx -= ditX[dir];
			Rdist--;
			break;
		}
		if (map[ry][rx] == 'O') {
			Rflag = 1;
			break;
		}
	}

	while(1)
	{
		by += ditY[dir];
		bx += ditX[dir];
		Bdist++;

		if (map[by][bx] == '#') {
			by -= ditY[dir];
			bx -= ditX[dir];
			Bdist--;
			break;
		}
		if (map[by][bx] == 'O') {
			Bflag = 1;
			break;
		}
	}

	// 같은 위치라면
	if (ry == by && rx == bx) 
	{
		// 빨간공의 움직인 거리가 파란공보다 크다면
		if (Rdist > Bdist) 
		{
			ry -= ditY[dir];
			rx -= ditX[dir];
		}
		else
		{
			by -= ditY[dir];
			bx -= ditX[dir];
		}
	}



	// 빨간공만 빠지면 바로 정답
	if (Rflag == 1 && Bflag == 0) return 1;
	
	// 파란공만 빠지면 q에 넣지않고 넘어감
	if (Rflag == 0 && Bflag == 1) return 0;

	// 둘 다 빠졌을때 q에 넣지않고 넘어감
	if (Rflag == 1 && Bflag == 1) return 0;

	// 둘 다 안빠졌을때
	q.push({ ry,rx,by,bx,dir,lev + 1 });
	return 0;


}

int solve() 
{
	// q에 이전방향이 좌or우, 상or하 일 때를 집어넣고 시작한다.
	for (int i = 1; i <= 3; i += 2) {
		q.push({ startRy, startRx, startBy, startBx, i, 0 });
	}
	

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		if (now.lev > 10) return -1;

		int before_dir = now.dir;


		// 좌우로 굴릴것이냐
		if (before_dir == 1 || before_dir == 2) {
			for (int i = 3; i <= 4; i++) {
				if (move(now.Ry, now.Rx, now.By, now.Bx, i, now.lev)) return now.lev + 1;
			}
		}
		// 상하로 굴릴것이냐
		else if (before_dir == 3 || before_dir == 4) {
			for (int i = 1; i <= 2; i++) {
				if (move(now.Ry, now.Rx, now.By, now.Bx, i, now.lev)) return now.lev + 1;
			}
		}
	}

	// q가 모두 비었는데 return문 실행이 되지않았다면 구슬이 구멍에 도달하지 못한 것이다.
	return -1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	int ans = solve();


	// return now.lev + 1 문장에서 11로 return되는 경우가 있기에 아래와 같이 처리해줘야한다.
	if (ans > 10) cout << -1;
	else cout << ans;


	return 0;
}