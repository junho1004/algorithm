#include<iostream>
#include<vector>
using namespace std;

int N, M;
int weight[100010];
vector<int> v[100010];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void solve()
{
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		if (v[i].size() == 0)
		{
			ans++;
			continue;
		}

		int flag = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			//cout << v[i][j] << " ";
			if (weight[i] <= weight[v[i][j]])
			{
				flag = 0;
				break;
			}
			flag = 1;
		}
		//cout << "\n";
		if (flag) ans++;
	}
	cout << ans;
}

int main(int argc, char** argv)
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}