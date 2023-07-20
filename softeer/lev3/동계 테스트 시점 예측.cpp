#include<iostream>
#include<queue>
using namespace std;

int H, W, ans;
int map[101][101];
struct Coord {
	int y, x;
};
queue<Coord> q;
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

void input()
{
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x]) q.push({ y,x });
		}
	}
	ans = 0;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= H || x >= W;
}

bool canRemove(Coord tar) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = tar.y + ditY[i];
		int nx = tar.x + ditX[i];
		if (map[ny][nx] == 2) cnt++;
		if (cnt >= 2) return 1;
	}
	return 0;
}

queue<Coord> outQ;

void makeOutAir()
{
	outQ.push({ 0,0 });
	int used[101][101] = { 0, };
	used[0][0] = 1;
	map[0][0] = 2;

	while (!outQ.empty())
	{
		Coord now = outQ.front();
		outQ.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
			if (used[ny][nx]) continue;
			if (map[ny][nx] == 1) continue;
			
			outQ.push({ ny,nx });
			used[ny][nx] = 1;
			map[ny][nx] = 2;
			
		}
	}
}

void solve()
{
	int now_size;

	queue<Coord> rmQ;

	while (!q.empty())
	{
		now_size = q.size();
		makeOutAir();

		for (int i = 0; i < now_size; i++)
		{
			if (canRemove(q.front())) {
				rmQ.push({ q.front() }); // 녹는 블럭은 지우는 rmQ에 푸시
			}
			else {
				q.push(q.front()); // 안녹는 블럭은 다시 q에 푸시
			}
			q.pop();
		}

		while (!rmQ.empty())
		{
			map[rmQ.front().y][rmQ.front().x] = 2; // 맵에서 녹이고 외부공기로 만들기
			
			rmQ.pop();
		}

		ans++;
	}
}

int main(int argc, char** argv)
{
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}