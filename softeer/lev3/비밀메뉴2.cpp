#include <iostream>
#include <algorithm>
using namespace std;


int A[3010] = { 0 };
int B[3010] = { 0 };
int C[3010][3010] = { 0 };

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int longest = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i] == B[j]) {
				if (i == 0 || j == 0) {
					C[i][j] = 1;
				}
				else {
					C[i][j] = C[i - 1][j - 1] + 1;
				}
				longest = max(longest, C[i][j]);
			}
		}
	}
	cout << longest;
	return 0;
}