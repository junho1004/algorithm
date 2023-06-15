#include <iostream>
#include <queue>
#include <string>
#define MAX_N 1010
using namespace std;

int N, M;
string map[MAX_N];
int ditY[4] = { -1,1,0,0 };
int ditX[4] = { 0,0,-1,1 };

struct Coord {
	int y, x;
};

queue<Coord> q;
bool used[MAX_N][MAX_N];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

bool isOut(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= M;
}

void solve() {
	q.push({ 0,0 });

	while (!q.empty())
	{
		Coord now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (isOut(ny, nx)) continue;
		}

	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}