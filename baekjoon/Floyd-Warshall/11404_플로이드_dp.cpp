#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int a[104][104];
const int INF = 1e9;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int st, en, v;
		cin >> st >> en >> v;
		a[st][en] = min(a[st][en], v);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == INF) cout << "0 ";
			else cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}