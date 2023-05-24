#include <iostream>
#include <queue>
using namespace std;

int N, Edge, ans;
bool map[110][110] = { 0, };
bool used[110] = { 0 };
queue<int> q;


void input() {
	cin >> N >> Edge;
	int a, b;
	for(int i = 0; i < Edge; i++) {
		cin >> a >> b;
		map[a][b] = true;
		map[b][a] = true;
	}
	ans = 0;
}

void solve() {
	q.push(1);
	used[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 1; i <= N; i++) {
			if (map[now][i] == true && used[i] == false) {
				ans++;
				used[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}