#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 11
using namespace std;

// 땅 10 x 10
// 가장 처음에 양분은 모든 칸에 5만큼 들어있다.

int N, M, K, ans;
vector<int> treeV[MAX_N][MAX_N]; // 나무의 나이를 저장할 벡터. 2차원 맵에 3차원 느낌으로 데이터를 쌓을 벡터
int AddEnergyMap[MAX_N][MAX_N]; // 겨울에 추가할 에너지를 저장해 놓은 맵
int map[MAX_N][MAX_N]; // 양분을 저장할 맵

int ditY[8] = { -1,-1,-1,0,0,1,1,1 };
int ditX[8] = { -1,0,1,-1,1,-1,0,1 };

struct Coord {
	int y, x;
};
queue<Coord> spreadQ;

void input() {
	cin >> N >> M >> K;
	// 1행 1열부터 시작한다.
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> AddEnergyMap[y][x];
			map[y][x] = 5; // 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
		}
	}
	int r, c, age;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> age;
		treeV[r][c].push_back(age);
	}
	ans = 0;
}


// 여름 : 죽은 나무 나이 / 2 == 양분 추가
void summer(int y, int x, int deadCnt) {
	for (int j = 0; j < deadCnt; j++) {
		map[y][x] += treeV[y][x].back() / 2;
		treeV[y][x].pop_back(); // 나무 죽은거 처리
	}
}

// 봄 : 나이만큼 양분 섭취, 나이 +1, 하나의 칸에 여러 개의 나무가 있다면 나무가 어린 나무부터 양분을 먹는다.
// 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없다면 나무는 죽는다.
void spring() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int size = treeV[y][x].size();
			if (size == 0) continue;
			sort(treeV[y][x].begin(), treeV[y][x].end()); // 어린 나무부터 오름차순 정렬

			int deadFlag = 0;
			int now_energy = map[y][x];
			int deadCnt = 0;
			for (int k = 0; k < size; k++)
			{
				if (treeV[y][x][k] > now_energy) {
					deadFlag = 1;
					deadCnt = size - k; // 여름을 위해 죽은 나무 수를 기록한다.
					//now_energy = 0; // 양분을 아예 못먹는다. 양분을 건들면 안돼
					break;
				}
				else {
					now_energy -= treeV[y][x][k];
					treeV[y][x][k] += 1;
					if (treeV[y][x][k] % 5 == 0) spreadQ.push({ y,x }); // 가을을 위해 번식가능한 나무를 q에 넣어놓는다.
				}
			}
			map[y][x] = now_energy;
			if (deadFlag) summer(y, x, deadCnt); // 양분맵에 죽은나무나이 / 2 값을 추가한다.
		}
	}
}

// 가을 : 나이가 5의 배수인 나무가 번식한다. 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 땅 벗어나면 안생겨
void autumn()
{
	while (!spreadQ.empty())
	{
		Coord now = spreadQ.front();
		spreadQ.pop();
		for (int i = 0; i < 8; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (ny < 1 || nx < 1 || ny >= N + 1 || nx >= N + 1) continue;
			treeV[ny][nx].push_back(1); // 나이가 1인 나무가 생김
		}

	}
}
// 겨울 : 땅에 양분을 추가한다. 양분의 양은 A[r][c]이며 입력으로 주어진다.
void winter() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			map[y][x] += AddEnergyMap[y][x];
		}
	}
}

void solve() {
	while (K--) {
		spring();
		autumn();
		winter();
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			ans += treeV[y][x].size();
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}