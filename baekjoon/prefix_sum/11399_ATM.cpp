#include<iostream>
#include<algorithm>
using namespace std;

int N, ans;
int people[1010];
int prefix[1010];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
	ans = 0;
}

void solve() {
	sort(people, people + N);

	prefix[0] = people[0];
	ans = prefix[0];
	for (int i = 1; i < N; i++) {
		prefix[i] = prefix[i - 1] + people[i];
		ans += prefix[i];
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}