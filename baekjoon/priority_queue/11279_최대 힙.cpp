#include<iostream>
#include<queue>
using namespace std;

int N, num;
priority_queue<int> pq;

void input() {
	cin >> N;
}

void solve() {
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	input();
	solve();
	

	return 0;
}