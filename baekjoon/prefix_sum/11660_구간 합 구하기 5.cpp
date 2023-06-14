#include <iostream>
#define MAX_N 1030
using namespace std;

int N, M;
int map[MAX_N][MAX_N];
int prefix[MAX_N][MAX_N];

void input() {
	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			prefix[y][x] = map[y][x] + prefix[y - 1][x] + prefix[y][x - 1] - prefix[y - 1][x - 1];
		}
	}
}

void solve() {
	int start_x, start_y, end_x, end_y;
	int ans;
	while (M--)
	{
		cin >> start_x >> start_y >> end_x >> end_y;
		ans = prefix[end_x][end_y] - prefix[end_x][start_y - 1] - prefix[start_x - 1][end_y] + prefix[start_x - 1][start_y - 1];
		cout << ans << "\n";
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	return 0;
}