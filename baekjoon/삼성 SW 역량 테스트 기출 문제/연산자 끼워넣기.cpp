#include <iostream>
#include <algorithm>
using namespace std;

int N;
int nums[12];
int op[4];
int maxi, mini;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	maxi = -1'000'000'001;
	mini = 1'000'000'001;
}

void dfs(int lev, int res) 
{
	if (lev == N - 1) {
		maxi = max(res, maxi);
		mini = min(res, mini);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] == 0) continue;
		op[i]--;

		if (i == 0) {
			dfs(lev + 1, res + nums[lev + 1]);
		}
		else if (i == 1) {
			dfs(lev + 1, res - nums[lev + 1]);
		}
		else if (i == 2) {
			dfs(lev + 1, res * nums[lev + 1]);
		}
		else {
			dfs(lev + 1, res / nums[lev + 1]);
		}
		op[i]++;

	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	dfs(0, nums[0]);
	cout << maxi << "\n" << mini;

	return 0;
}