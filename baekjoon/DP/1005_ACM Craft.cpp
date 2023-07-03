#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, W, ans;
int BT[1001];
int memo[1001];
vector<int> v[1001];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> BT[i];
	}

	int first, second;
	// 최종 건설하고자하는 건물에서 가장 선행의 건물까지 역으로 탐색해야한다.
	for (int y = 0; y < K; y++) {
		cin >> first >> second;
		v[second].push_back(first);
	}
	cin >> W;

	ans = 0;
}

void init() {
	memset(BT, 0, sizeof(BT));
	memset(v, 0, sizeof(v));
	memset(memo, -1, sizeof(memo));
}

int dfs(int now) {
	int size = v[now].size();

	// 끝까지 왔다면 return
	if (size == 0) return BT[now];

	// memo
	if (memo[now] != -1) return memo[now];

	int maxTime = 0;
	for (int i = 0; i < v[now].size(); i++) 
	{
		int next = v[now][i];

		maxTime = max(maxTime, BT[now] + dfs(next));
	}

	// memo[now] = maxTime;
	// return memo[now];
	// dfs 끝지점에서 다시 돌아가며 memo를 해준다.
	return memo[now] = maxTime;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tcCnt;
	cin >> tcCnt;
	while(tcCnt--)
	{
		init();
		input();
		cout << dfs(W) << "\n";
	}

	return 0;
}