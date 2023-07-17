#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, ans;
int map[21][21];
int team[21];

void input() {
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}
	ans = 987654321;
}


int getSum_startV(vector<int> v) 
{
	int sum = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			sum += map[v[i]][v[j]] + map[v[j]][v[i]];
		}
	}

	return sum;
}

int getSum_linkV(vector<int> v)
{
	int sum = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			sum += map[v[i]][v[j]] + map[v[j]][v[i]];
		}
	}

	return sum;
}

void divide_team(int lev, int start)
{
	if (lev == N / 2) {

		vector<int> startV;
		vector<int> linkV;
		for (int i = 1; i <= N; i++) {
			if (team[i] == 1) startV.push_back(i);
			else linkV.push_back(i);
		}

		int start = getSum_startV(startV);
		int link = getSum_linkV(linkV);
		
		int tmp = abs(start - link);
		if (ans > tmp) ans = tmp;

		
		return;
	}

	// N까지 설정할 경우 팀 배정에서 중복이 일어난다.
	// 따라서 N-1까지만 반복문을 돌려 중복을 방지한다. 팀 배정의 모든 경우는 충분히 뽑아낼 수 있다.
	for(int i = start; i < N; i++){
		team[i] = 1;
		divide_team(lev + 1, i + 1);
		team[i] = 0;
	}
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	divide_team(0, 1);
	cout << ans;

	return 0;
}