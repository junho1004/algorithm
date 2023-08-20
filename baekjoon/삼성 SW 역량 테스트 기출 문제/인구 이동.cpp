#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, L, R, ans;
int map[51][51];
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };
int visited[51][51];
bool stopFlag;

struct Coord {
	int y, x;
};

queue<Coord> q;
queue<Coord> tmpQ;

void input() {
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void floodfill(int startY, int startX)
{
	q.push({ startY, startX }); // bfs구현할 큐
	tmpQ.push({ startY, startX }); // 맵을 바꾸는데 필요한 큐
	int sum = map[startY][startX];
	int cnt = 1;

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;
			int gap = abs(map[now.y][now.x] - map[ny][nx]);
			if (L <= gap && gap <= R)
			{
				stopFlag = 0; // 인구이동이 가능하다면 스탑플래그를 꺼야함
				visited[ny][nx] = 1;
				sum += map[ny][nx];
				cnt++;
				q.push({ ny,nx });
				tmpQ.push({ ny,nx });
			}
		}
	}


	int val = sum / cnt;
	while (!tmpQ.empty()) {
		Coord now_country = tmpQ.front();
		tmpQ.pop();
		map[now_country.y][now_country.x] = val;
	}
}

void solve()
{
	ans = 0;
	while (1)
	{
		stopFlag = 1;
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x]) continue;
				visited[y][x] = 1;
				floodfill(y, x);
			}
		}
		if (stopFlag) break; // 더이상 인구이동이 일어나지 않음.
		ans++;
	}
	cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	return 0;
}