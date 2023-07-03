#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101];
int V[101];
int DP[101][100001];


void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
}

void solve() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= K; x++) {
			// y번째 물건을 넣을 수 있다면?
			if (W[y] <= x) {
				// 넣지 않았을 때, 넣었을 때, 둘 중 더 큰 것으로 갱신
				// max함수의 뒤에 비교식은 
				// 현재 들어가려는 물건의 무게(W[y])를 현재 최대 용량(x)에서 빼줬을 때 가치(DP[y - 1][x - W[y]])에 현재 물건의 가치(V[y])를 더한다.
				DP[y][x] = max(DP[y - 1][x], DP[y - 1][x - W[y]] + V[y]);
			}
			// y번째 물건을 넣을 수 없다면?
			else {
				DP[y][x] = DP[y - 1][x];
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << DP[N][K];

	return 0;
}