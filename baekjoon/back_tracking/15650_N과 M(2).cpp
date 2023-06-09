#include <iostream>
using namespace std;

int N, M;
int path[10];

void input() {
	cin >> N >> M;
}

void dfs(int lev, int start)
{
	if (lev == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start + 1; i <= N; i++) {
		path[lev] = i;
		dfs(lev + 1, i);
		
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	dfs(0, 0);

	return 0;
}