#include <iostream>
#include <vector>
#define MAX_N 100010
using namespace std;

int N;
vector<int> v[MAX_N];
int arr[MAX_N];

void input() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void dfs(int now, int before) {
	if (arr[now] == 0)
	{
		arr[now] = before;
	}

	before = now;

	for (int i = 0; i < v[now].size(); i++)
	{
		if (arr[v[now][i]] == 0)
		{
			dfs(v[now][i], before);
		}
	}

}

void solve() {
	arr[1] = 1;
	dfs(1, 0);
	for (int i = 2; i <= N; i++) {
		cout << arr[i] << "\n";
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