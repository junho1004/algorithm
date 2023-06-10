#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[10];
int path[10];
bool used[10];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
}

void dfs(int lev) {

	if (lev == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	int before = 0;

	for (int i = 0; i < N; i++) {
 		if (used[i] == true) continue;
		if (before == nums[i]) continue;

 		used[i] = true;
		before = nums[i];
		path[lev] = nums[i];
		dfs(lev + 1);
		used[i] = false;
	}

}

void solve() {
	sort(nums, nums + N);
	dfs(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	return 0;
}