#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int ditY[] = { -1,1,0,0 };
int ditX[] = { 0,0,-1,1 };
struct Coord {
	int y, x;
};
int N;
int map[15][15];
vector<vector<int>> v(15);
Coord path[3];
int ans;

void input() {
	cin >> N;
	int a;
	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			v[j].push_back(a);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

int floodfill(Coord tar, int tmp[15][15]) {
	bool used[15][15] = { 0, };
	queue<Coord> q;
	q.push(tar);
	used[tar.y][tar.x] = 1;
	int num = tmp[tar.y][tar.x];
	tmp[tar.y][tar.x] = 0; // 터친곳 0으로

	// 자동차 개수와, 직사각형 면적 계산을 위함.
	int carCnt = 1;
	Coord Maxi = { -1,1 };
	Coord Mini = { 20,20 };

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		Maxi.y = max(Maxi.y, now.y);
		Maxi.x = max(Maxi.x, now.x);

		Mini.y = min(Mini.y, now.y);
		Mini.x = min(Mini.x, now.x);

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
			if (used[ny][nx]) continue;
			if (tmp[ny][nx] != num) continue;
			used[ny][nx] = 1;
			tmp[ny][nx] = 0; // 터진 곳은 0으로 표현
			carCnt++;
	
			q.push({ ny,nx });
		}
	}

	int ret = carCnt + ((Maxi.y - Mini.y) + 1) * ((Maxi.x - Mini.x) + 1);

	return ret;
}

void copy_the_map(int tmp[15][15]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			tmp[y][x] = map[y][x];
		}
	}
}

void drop(vector<vector<int>> &cpyV, int cpyMap[15][15])
{
	for (int x = 0; x < N; x++) {
		queue<int> dropQ;
		int spare = 0;

		for (int y = N - 1; y >= 0; y--) {
			if (cpyMap[y][x] != 0) dropQ.push(cpyMap[y][x]);
			else spare++;
		}
		// 위에 차 가져오기
		while (spare--) {
			dropQ.push(cpyV[x].back());
			cpyV[x].pop_back();
		}

		for (int y = N - 1; y >= 0; y--) {
			cpyMap[y][x] = dropQ.front();
			dropQ.pop();
		}

	}
}

int solve() {
	vector<vector<int>> cpyV;
	cpyV = v;
	int cpyMap[15][15];
	copy_the_map(cpyMap);

	int ret = 0;
	for (int k = 0; k < 3; k++)
	{
		ret += floodfill(path[k], cpyMap);
		if(k < 2) drop(cpyV, cpyMap);
	}

	return ret;
}

void dfs(int lev) {
	if (lev == 3) {
		int score = solve();
		ans = max(ans, score);
		return;
	}

	// 점 3개를 모두 뽑고 터친다.
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			path[lev] = { y,x };
			dfs(lev + 1);
		}
	}
}

int main(int argc, char** argv)
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	dfs(0);
	//solve();
	cout << ans;

	return 0;
}