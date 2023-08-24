#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_N 21
using namespace std;

int N, ans;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };
struct Node {
	int y, x, dist;
};
Node start;

// 먹을 수 있는 물고기X => 도움 요청
// 먹을 수 있는 물고기 1마리 => 먹으러감
// 먹을 수 있는 물고기 여러마리 => 가장 가까운 => 가장 위 >> 가장 왼쪽

// 자신의 크기만큼 물고기를 먹었을 때 크기 1증가

// 자신을 기준으로 플러드필을 해가며 1 ~ N*N 으로 범위를 넓혀가며 먹을 수 있는 물고기가 있는지 찾는다.
// 찾은 물고기 중 가장 위, 가장 왼쪽에 있는 물고기를 먹는다. lev 증가 고려


void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				start = { y,x,0 };
			}
		}
	}
	ans = 0;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

bool cmp(pair<int,int> t, pair<int,int> v) {
	if (t.first == v.first) return t.second < v.second;
	return t.first < v.first;
}

void solve()
{
	int eat_cnt = 0;
	int level = 2;

	while (1) {
		bool eatFlag = 0;
		int breakDist = 0;
		memset(visited, 0, sizeof(visited));

		vector<pair<int, int>> v;
		queue<Node> q;
		q.push(start);
		visited[start.y][start.x] = 1;

		while (!q.empty())
		{
			Node now = q.front();
			q.pop();

			if (eatFlag && breakDist < now.dist) break;

			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + ditY[i];
				int nx = now.x + ditX[i];
				if (isOut(ny, nx)) continue;
				if (visited[ny][nx]) continue;
				if (map[ny][nx] > level) continue; //  큼 =>  먹을 수 없고 못 지나가

				visited[ny][nx] = 1;

				if (map[ny][nx] == level || map[ny][nx] == 0) // 같거나 0 => 지나가기만 함
				{ 
					q.push({ ny,nx, now.dist + 1 });
					continue;
				}

				eatFlag = 1; // 먹을 수 있는게 있다. 굳이 q에 넣을 필요 없다. 
				breakDist = now.dist;
				v.push_back({ ny,nx }); // 작음 => 먹을 수 있고 지나가
			}
		}

		if (eatFlag) {
			// 벡터 정렬 후 먹어. y가 작고, 만약 y가 같다면 x가 작은 물고기로
			sort(v.begin(), v.end(), cmp);

			map[start.y][start.x] = 0; // 아기 상어 있던 곳 0으로 만들기
			start = { v[0].first, v[0].second, 0 }; // 아기 상어 시작점 갱신
			map[start.y][start.x] = 9; // 아기 상어 위치 바꿔주기. 0으로 해도 상관없음.

			ans += breakDist + 1; // 답에 이동한 거리 더하기
			eat_cnt++; // 먹은 물고기++
			if (eat_cnt == level) { // 레벨업 조건
				level++;
				eat_cnt = 0;
			}
		}
		else break; // 먹을 수 있는게 없다.
	}
	
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}