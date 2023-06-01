#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> input_v[510];
vector<int> ans_v[510];


// 벡터 초기화면서 입력받기
// 벡터에 푸시

void solve() {

	cin >> N;

	int num;
	for (int i = 1; i <= N; i++)
	{
		for (int k = 0; k < i; k++) 
		{
			cin >> num;
			input_v[i].push_back(num);
		}
	}

	ans_v[1] = input_v[1];

	for (int i = 2; i <= N; i++)
	{
		int first = input_v[i].front() + ans_v[i - 1].front();
		ans_v[i].push_back(first);

		
		for (int k = 0; k < ans_v[i - 1].size() - 1; k++) {
			int maxi = max(ans_v[i - 1][k], ans_v[i - 1][k + 1]);
			int tmp = input_v[i][k + 1] + maxi;
			ans_v[i].push_back(tmp);
		}
		

		int last = input_v[i].back() + ans_v[i - 1].back();
		ans_v[i].push_back(last);
	}

	sort(ans_v[N].begin(), ans_v[N].end());
	cout << ans_v[N].back();
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solve();

	return 0;
}