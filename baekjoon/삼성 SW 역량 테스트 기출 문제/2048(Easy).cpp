#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
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
	queue<int> q;
	stack<int> st;
	stack<int> st2;
	// 상
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			
			for (int y = 0; y < N; y++) 
			{
				if (tmp[y][x] == 0) continue;
				q.push(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int hapFlag = 0;

			while (!q.empty())
			{
				int now = q.front();
				q.pop();

				//스택이 비어있지 않으면
				if (!st.empty())
				{
					// 큐에서 꺼낸것과 스택의 탑이 같고, 합친 이력이 없으면.
					if (now == st.top() && hapFlag == 0)
					{
						st.pop();
						st.push(now * 2);
						hapFlag = 1; // 합쳤다는 플래그
					}
					else {
						st.push(now);
						hapFlag = 0;
					}

					continue;
				}
				// 비어있다면.
				st.push(now);
				hapFlag = 0;
			}

			while (!st.empty()) {
				st2.push(st.top());
				st.pop();
			}

			int idx = 0;
			while (!st2.empty()) {
				tmp[idx][x] = st2.top();
				st2.pop();
				idx++;
			}
		}
	}

	// 하
	else if (dir == 1) {
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y >= 0; y--) 
			{
				if (tmp[y][x] == 0) continue;
				q.push(tmp[y][x]);
				tmp[y][x] = 0;
			}
			int hapFlag = 0;

			while (!q.empty())
			{
				int now = q.front();
				q.pop();

				//스택이 비어있지 않으면
				if (!st.empty())
				{
					// 큐에서 꺼낸것과 스택의 탑이 같고, 합친 이력이 없으면.
					if (now == st.top() && hapFlag == 0)
					{
						st.pop();
						st.push(now * 2);
						hapFlag = 1; // 합쳤다는 플래그
					}
					else {
						st.push(now);
						hapFlag = 0;
					}

					continue;
				}
				// 비어있다면.
				st.push(now);
				hapFlag = 0;
			}

			while (!st.empty()) {
				st2.push(st.top());
				st.pop();
			}

			int idx = 0;
			while (!st2.empty()) {
				tmp[idx][x] = st2.top();
				st2.pop();
				idx++;
			}
		}
	}

	// 좌
	else if (dir == 2) {
		for (int y = 0; y < N; y++) 
		{

			for (int x = 0; x < N; x++) 
			{
				if (tmp[y][x] == 0) continue;
				q.push(tmp[y][x]);
				tmp[y][x] = 0;
			}

			int hapFlag = 0;

			while (!q.empty()) 
			{
				int now = q.front();
				q.pop();

				//스택이 비어있지 않으면
				if (!st.empty()) 
				{
					// 큐에서 꺼낸것과 스택의 탑이 같고, 합친 이력이 없으면.
					if (now == st.top() && hapFlag == 0)
					{
						st.pop();
						st.push(now * 2);
						hapFlag = 1; // 합쳤다는 플래그
					}
					else {
						st.push(now);
						hapFlag = 0;
					}		

					continue;
				}
				// 비어있다면.
				st.push(now);
				hapFlag = 0;
			}

			while (!st.empty()) {
				st2.push(st.top());
				st.pop();
			}

			int idx = 0;
			while (!st2.empty()) {
				tmp[y][idx] = st2.top();
				st2.pop();
				idx++;
			}

		}

	}

	// 우
	else if (dir == 3) {
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) 
			{
				if (tmp[y][x] == 0) continue;
				q.push(tmp[y][x]);
				tmp[y][x] = 0;
			}

			int hapFlag = 0;

			while (!q.empty())
			{
				int now = q.front();
				q.pop();

				//스택이 비어있지 않으면
				if (!st.empty())
				{
					// 큐에서 꺼낸것과 스택의 탑이 같고, 합친 이력이 없으면.
					if (now == st.top() && hapFlag == 0)
					{
						st.pop();
						st.push(now * 2);
						hapFlag = 1; // 합쳤다는 플래그
					}
					else {
						st.push(now);
						hapFlag = 0;
					}

					continue;
				}
				// 비어있다면.
				st.push(now);
				hapFlag = 0;
			}

			while (!st.empty()) {
				st2.push(st.top());
				st.pop();
			}

			int idx = 0;
			while (!st2.empty()) {
				tmp[y][idx] = st2.top();
				st2.pop();
				idx++;
			}
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

	getAns();
}

void dfs(int lev) {
	if (lev == 5) {
		copyMap();
		play();
		return;
	}

	// 상하좌우 움직이기
	for (int i = 0; i < 4; i++) 
	{
		path[lev] = i;
		dfs(lev + 1);
	}
}

void solve() {
	dfs(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();

	cout << ans;
	return 0;
}