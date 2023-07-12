#include <iostream>
#include <queue>
#define MAX_N 101
using namespace std;

int N, K, L;
int map[MAX_N][MAX_N];
int snake[MAX_N][MAX_N];

struct Node {
	int time;
	char dir;
};

queue<Node> dirQ;

// 우 하 좌 상
int ditY[4] = { 0,1,0,-1 };
int ditX[4] = { 1,0,-1,0 };

void input() {
	cin >> N >> K;
	int y, x;
	while (K--) {
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> L;
	int t;
	char ch;
	while (L--) {
		cin >> t >> ch;
		dirQ.push({ t,ch });
	}
	
}

bool isOut(int y, int x) {
	return y <= 0 || x <= 0 || y > N || x > N;
}

bool crush(int y, int x) {
	return snake[y][x] != 0;
}

int solve() 
{
	// 현재 위치 0초;
	snake[1][1] = 0;

	// 초기 위치와 방향
	int nowY = 1;
	int nowX = 1;
	int way = 0;

	// 꼬리를 저장하기 위한 큐
	queue<pair<int,int>> tailQ;

	// dir 0,1,2,3 우하좌상
	while (1) 
	{
		int ny = nowY + ditY[way];
		int nx = nowX + ditX[way];

		// 꼬리를 줄이기 이전에 뱀이 부딪힐 수 있다.
		// 나갔거나 몸통과 부딪히면
		if (isOut(ny, nx) || crush(ny, nx)) return snake[nowY][nowX] + 1;
		
		// snake배열은 곧 움직인 시간초이며 뱀의 형상을 나타낸다.
		snake[ny][nx] = snake[nowY][nowX] + 1;
	
		tailQ.push({ nowY, nowX }); 	// 꼬리를 Q에 넣으며 진행

		// 사과가 아닐 땐 가장 끝 꼬리(가장 먼저 푸시된 좌표)를 잘라야함
		if (map[ny][nx] == 0) 
		{
			int tailY = tailQ.front().first;
			int tailX = tailQ.front().second;
			tailQ.pop();

			snake[tailY][tailX] = 0;
		}
		// 사과일 때 꼬리만 자르지 않으면 되고, 있던 사과를 없애준다.
		else map[ny][nx] = 0;

		// X초가 끝난 뒤 방향이 바뀌나?
		if (!dirQ.empty() && snake[ny][nx] == dirQ.front().time)
		{
			
			if (dirQ.front().dir == 'D') { // 우회전일 때 다음방향
				way = (way + 1) % 4;
			}
			else {						// 좌회전일 때 다음방향
				way = (way + 3) % 4;
			}
			dirQ.pop();
		}

		// 현재 머리 위치 변경
		nowY = ny;
		nowX = nx;
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	cout << solve();

	return 0;
}