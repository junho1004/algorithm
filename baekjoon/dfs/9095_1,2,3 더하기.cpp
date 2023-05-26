// dfs인데 lev이 정해져있지 않고 브랜치는 1,2,3 세개야
// return 절을 이때까지 나온게 합이 N일 때 진행하고
// N을 초과해도 return 해야해
// 인자로는 sum을 가져가야할 것 같아
// 그리고 중복 뽑기가 가능해
// 그리고 112 랑 121 211 이 모두다른 경우로 해석해
#include<iostream>
using namespace std;

int N, ans;

void input() {
	cin >> N;
	ans = 0;
}

void dfs(int sum) {
	if (sum == N) {
		ans++;
		return;
	}
	if (sum > N) return;

	for (int i = 1; i <= 3; i++) {
		dfs(sum + i);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		input();
		dfs(0);
		cout << ans << "\n";
	}

	return 0;
}