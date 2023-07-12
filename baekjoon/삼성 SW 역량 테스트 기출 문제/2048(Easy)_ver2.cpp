#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int map[21][21];
int tmp[21][21];
int path[5];

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	ans = 0;
}

void move(int dir)
{
	vector<int> v;
	// 상
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			// 0이 아닌 것들 벡터에 push_back
			for (int y = 0; y < N; y++) 
			{
				if (tmp[y][x]) v.push_back(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int idx = 0;
			for (int k = 0; k < v.size(); k++)
			{
				// 벡터 사이즈비교가 먼저 이뤄져야 index오류가 나지 않는다.
				// 만약 벡터의 현재값과 다음값이 같으면 합칠 수 있으니 2배 해준 값을 넣어준다. 이 경우엔 한번 더 j++를 해줘야한다.
				if (k + 1 < v.size() && v[k] == v[k + 1]) tmp[idx][x] = v[k++] * 2; 
				else tmp[idx][x] = v[k]; // 다르다면 그냥 현재 벡터값을 맵에 넣어준다.
				idx++;
			}
			v.clear();
		}
	}

	// 하
	else if (dir == 1) {
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y >= 0; y--) 
			{
				if (tmp[y][x]) v.push_back(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int idx = N - 1;
			for (int k = 0; k < v.size(); k++)
			{
				if (k + 1 < v.size() && v[k] == v[k + 1]) tmp[idx][x] = v[k++] * 2;
				else tmp[idx][x] = v[k];
				idx--;
			}
			v.clear();
		}
	}

	// 좌
	else if (dir == 2) {
		for (int y = 0; y < N; y++) 
		{

			for (int x = 0; x < N; x++) 
			{
				if (tmp[y][x]) v.push_back(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int idx = 0;
			for (int k = 0; k < v.size(); k++)
			{
				if (k + 1 < v.size() && v[k] == v[k + 1]) tmp[y][idx] = v[k++] * 2;
				else tmp[y][idx] = v[k];
				idx++;
			}
			v.clear();
		}

	}

	// 우
	else if (dir == 3) {
		for (int y = 0; y < N; y++) {

			for (int x = N - 1; x >= 0; x--) 
			{
				if (tmp[y][x]) v.push_back(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int idx = N - 1;
			for (int k = 0; k < v.size(); k++)
			{
				if (k + 1 < v.size() && v[k] == v[k + 1]) tmp[y][idx] = v[k++] * 2;
				else tmp[y][idx] = v[k];
				idx--;
			}
			v.clear();
		}
	}
}

void copyMap() 
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			tmp[y][x] = map[y][x];
		}
	}
}

void getAns() 
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			ans = max(ans, tmp[y][x]);
		}
	}
}

void play() 
{
	for (int i = 0; i < 5; i++) {
		int dir = path[i];
		move(dir);
	}
}

void dfs(int lev) {
	if (lev == 5) {
		// 중복조합이 완성되면 맵을 복사하고
		copyMap();
		// 5개의 방향 그대로 맵을 움직인다.
		play();
		// 매번 다 움직였을 때의 최댓값을 뽑아낸다.
		getAns();
		return;
	}

	// 상하좌우 움직이기
	for (int i = 0; i < 4; i++) 
	{
		path[lev] = i;
		dfs(lev + 1);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	dfs(0);

	cout << ans;
	return 0;
}