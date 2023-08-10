#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };
struct Coord {
	int y, x;
};
int N, ans;
int map[45][15];

void input() {
	cin >> N;
	for (int y = 0; y < 3 * N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}




void dfs(int lev, int sum)
{
	bool visited[15][15] = { 0, };
	int tmp[45][15];
	memcpy(tmp, map, sizeof(map)); // tmp에 현재 map상태 복사

	for (int y = 2 * N; y < 3 * N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int now_car = tmp[y][x];
			//빈 경우, 이미 검사한 곳
			if (now_car == 0 || visited[y - 2 * N][x]) continue;
			memcpy(map, tmp, sizeof(map));
			int maxY = y;
			int minY = y;
			int maxX = x;
			int minX = x;

			queue<Coord> q;
			int same = 1;
			q.push({ y,x });
			visited[y - 2 * N][x] = true;

			while (!q.empty()) {
				Coord now = q.front();
				q.pop();
				map[now.y][now.x] = 0; // 빈 처리

				maxY = max(maxY, now.y);
				minY = min(minY, now.y);
				maxX = max(maxX, now.x);
				minX = min(minX, now.x);
				for (int i = 0; i < 4; i++) {
					int ny = now.y + ditY[i];
					int nx = now.x + ditX[i];
					if (nx >= 0 && ny >= 2 * N && nx < N && ny < 3 * N && !visited[ny - 2 * N][nx] && tmp[ny][nx] == now_car) {
						visited[ny - 2 * N][nx] = true;
						q.push({ ny,nx });
						same++;
					}
				}
			}
			// 중력
			if (lev < 2)
			{
				for (int k = minX;k <= maxX;k++) {
					for (int m = maxY;m >= minY;m--) {
						if (map[m][k] != 0) continue;
						int jump = 0;
						//jump칸씩 내림
						for (int l = m - 1;l >= 0;l--) {
							if (map[l][k]) {
								jump = m - l;
								break;
							}
						}
						if (jump) {
							for (int l = m;l >= jump;l--) {
								map[l][k] = map[l - jump][k];
								map[l - jump][k] = 0;
							}
						}
					}
				}

				dfs(lev + 1, sum + same + (maxX - minX + 1) * (maxY - minY + 1));
			}

			else
			{
				ans = max(ans, sum + same + (maxX - minX + 1) * (maxY - minY + 1));
				continue;
			}

		}
	}
}

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	input();
	dfs(0, 0);
	cout << ans;

	return 0;
}
