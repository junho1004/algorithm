#include <iostream>
#include <queue>
using namespace std;


int n, k;

int p[100001]{};
int w = 0;

int min_w = 1000000;

void shortest() {
	queue<int> q;
	q.push(n); 
	p[n]=0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == k) {
			min_w = p[cur];
			return;
		}
		if (cur * 2 < 100001  && p[cur * 2] > p[cur]) {
			p[cur * 2] = p[cur];
			q.push(cur * 2);
		}
		 
		if (cur + 1 < 100001 && p[cur + 1] > p[cur] + 1) {
			p[cur + 1] = p[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && p[cur - 1] > p[cur] + 1) {
			p[cur - 1] = p[cur] + 1;
			q.push(cur - 1);
		}

		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < 100001; i++) {
		p[i] = 1000000;
	}

	shortest();

	cout << min_w << '\n';
	return 0;
}