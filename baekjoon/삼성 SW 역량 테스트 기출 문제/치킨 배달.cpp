#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 집의 개수는 최대 2N개 
// 치킨집 개수는 M~13개
// 치킨집의 좌표를 vector에 담고 M개를 조합으로 뽑는다. 13개에서 최대 6~7개를 뽑을때 1716개로 최대임.
// 최대 100개의 집에서 1716가지 경우(7개의 치킨집으로 이뤄진 조합) 100 * 13 * 1716 = 2,230,800 (13까지 봐야한다.)

int N, M, ans;
int map[51][51];
int cnt_home, cnt_chic;

struct Coord {
	int y, x;
};

vector<Coord> home;
vector<Coord> chic;
bool choice[14];

void input() {
	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) home.push_back({ y,x });
			else if (map[y][x] == 2) chic.push_back({ y,x });
		}
	}
	cnt_home = home.size();
	cnt_chic = chic.size();
	ans = 1e8;
}

void calc_min_dist()
{
	int sum = 0;
	for (int i = 0; i < cnt_home; i++)
	{
		int tmp = 1e8;
		for (int j = 0; j < cnt_chic; j++) {

			if (choice[j])
			{
				tmp = min(tmp, abs(home[i].y - chic[j].y) + abs(home[i].x - chic[j].x));
			}
		}
		sum += tmp;
	}
	ans = min(sum, ans);
}

void dfs(int lev, int start)
{
	if (lev == M)
	{
		calc_min_dist();
		/*for (int i = 0; i < cnt_chic; i++) {
			cout << choice[i] << " ";
		}
		cout << "\n";*/
		return;
	}

	for (int i = start; i < cnt_chic; i++)
	{
		if (choice[i]) continue;
		choice[i] = 1;
		dfs(lev + 1, i);
		choice[i] = 0;
	}

}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	dfs(0, 0);
	cout << ans;
	return 0;
}