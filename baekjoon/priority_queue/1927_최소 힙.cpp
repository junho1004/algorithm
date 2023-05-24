#include<iostream>
#include<queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
	cin >> N;
}

void solve() {
	while (N--) {
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
			cout << 0 << "\n"; continue;
			}

			cout << pq.top() << "\n";
			pq.pop();
		}

		else {
			pq.push(x);
		}
	}
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}