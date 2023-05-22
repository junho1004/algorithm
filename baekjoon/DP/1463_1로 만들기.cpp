#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int N, pivot;

int solve() {
	pivot = 0;
	if (N == 1) return pivot;
	v.push_back({ N });

	while (1) {
		vector<int> temp;

		int limit = v[pivot].size();

		for (int i = 0; i < limit; i++) {
			if (v[pivot][i] % 3 == 0) {
				if (v[pivot][i] / 3 == 1) return pivot + 1;
				temp.push_back({ v[pivot][i] / 3 });
			}
			if (v[pivot][i] % 2 == 0) {
				if (v[pivot][i] / 2 == 1) return pivot + 1;
				temp.push_back({ v[pivot][i] / 2 });
			}
			if (v[pivot][i] - 1 == 1) return pivot + 1;
			temp.push_back({ v[pivot][i] - 1 });
		}
		v.push_back(temp);
		
		pivot++;
	}

}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	cout << solve();
	
	return 0;
}