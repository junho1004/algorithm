#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// bfs, 5 <= N <= 25 정사각형 맵
// 단지 수 세기, 단지별 집 수 세기
// 단지 수 출력 후, 단지별 집의 수 오름차순 출력

int N, danji_cnt;
string map[26];
int visited[26][26];
int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };

struct Coord {
	int y, x;
};
queue<Coord> q;
priority_queue<int, vector<int>, greater<>> pq;

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
	}
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

int bfs(int startY, int startX)
{
	q.push({ startY, startX });
	int cnt = 1;

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == '0') continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
			cnt++;
		}
	}
	return cnt;
}

void solve() {
	

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1' && visited[y][x] == 0)
			{
				visited[y][x] = 1;
				int house_cnt = bfs(y,x);
				pq.push(house_cnt);
				danji_cnt++;
			}
		}
	}

}

int main() 
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	cout << danji_cnt << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}