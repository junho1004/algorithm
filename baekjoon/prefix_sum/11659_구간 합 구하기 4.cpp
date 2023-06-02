#include <iostream>
#define MAX_N 100010
using namespace std;


int N, M;

int arr[MAX_N];
int prefix[MAX_N];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	prefix[1] = arr[1];

	for (int i = 2; i <= N; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	int start, end;

	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << prefix[end] - prefix[start - 1] << "\n";
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	return 0;
}