#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<string> v;
int N, ans;
queue<pair<int, int>> cmdQ;
queue<pair<int, int>> q;

void input() {

	string str;
	v.push_back("1");
	for (int i = 1; i <= 4; i++) {
		cin >> str;
		v.push_back(str);
	}
	cin >> N;
	int a, b;
	while (N--) {
		cin >> a >> b;
		cmdQ.push({ a,b });
	}
	ans = 0;
}

void getTurn(int tar, int bang) {
	// 어떤 톱니바퀴를 어느 방향으로 돌릴지 기록하는 배열
	int flag[5] = { 0,0,0,0,0 };
	flag[tar] = bang;
	
	for (int i = tar; i > 1; i--) {
		if (v[i][6] != v[i - 1][2]) {
			flag[i - 1] = flag[i] * (-1);
		}
		else break;
	}
	for (int i = tar; i < 4; i++) {
		if (v[i][2] != v[i + 1][6]) {
			flag[i + 1] = flag[i] * (-1);
		}
		else break;
	}

	for (int i = 1; i <= 4; i++) {
		if (flag[i] != 0) q.push({ i, flag[i] });
	}
}

//10101111
//// 시계 : 끝에숫자 앞으로
//11010111
//// 반시계 : 앞에숫자 끝으로
//01011111

void Turning() {

	while (!q.empty()) {
		int now = q.front().first;
		int op = q.front().second;
		q.pop();

		if (op == 1) {
			v[now] = v[now][7] + v[now].substr(0, 7);
		}
		else {
			v[now] = v[now].substr(1, 7) + v[now][0];
		}
	}
}

void solve() {
	while (!cmdQ.empty())
	{
		int now = cmdQ.front().first;
		int op = cmdQ.front().second;
		cmdQ.pop();
		getTurn(now, op);
		Turning();
	}
	for (int i = 1; i <= 4; i++) {
		if (v[i][0] == '1') ans += pow(2, i - 1);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}