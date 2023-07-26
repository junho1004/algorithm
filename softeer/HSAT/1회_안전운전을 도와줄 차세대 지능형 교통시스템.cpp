#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 까다로운 조건이 많은 bfs 느낌
// 신호 1~12번의 갈 수 있는 방향을 나타내주는 정보가 필요
// 맵 1 ~ N^2 번까지 어떤 신호등의 정보를 따라야하는지 필요
// 교차로 갔더라도 또 밟을 수 있다. 다만 중복해서 카운트하지는 않는다.
// 답은 최소 1에서 N^2이다.
// 내가 보고있는 방향 필요
// 차량의 방향이랑 같은 방향의 신호가 켜져있어야한다.
// 따라서 신호등이 보고있는 방향도 필요하다.

int N, K, ans;
vector<int> trafV[10001];
// 우 상 좌 하
int ditY[] = {0, -1, 0, 1};
int ditX[] = {1, 0, -1, 0};
int trafInfo[13][5] = {
	0, 0, 0, 0, 0,
	1, 1, 0, 1, 0,// 신호 1번 상,하,우 오른쪽 보고있는 교차로
	1, 1, 1, 0, 1,
	0, 1, 1, 1, 2,
	1, 0, 1, 1, 3,
	1, 1, 0, 0, 0,// 신호 5번 상,우
	0, 1, 1, 0, 1,
	0, 0, 1, 1, 2,
	1, 0, 0, 1, 3,
	1, 0, 0, 1, 0,// 신호 9번 하,우
	1, 1, 0, 0, 1,
	0, 1, 1, 0, 2,
	0, 0, 1, 1, 3
};
struct Node{
	int y,x,dir;
	int T;
};
queue<Node> q;
int visited[101][101];

void input(){
	cin >> N >> K;
	int a;
	for(int i = 0; i < N * N; i++){
		for(int j = 0; j < 4; j++){
			cin >> a;
			trafV[i].push_back(a);
		}
	}
	ans = 0;
}

bool isOut(int y, int x){
	return y < 0 || x < 0 || y >= N || x >= N;
}

void solve()
{
	q.push({0,0,1,0}); // 0,0 출발에 차량은 위쪽(dir = 1)보고있음, T = 0

	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		if(now.T > K) break; // bfs니깐 주어진 시간을 넘어 주행하면 바로 종료
		if(ans == N*N) break; // 모두 다 돌았다면 멈춤.
		if(visited[now.y][now.x] == 0)
		{
			ans++; // 방문한 적이 없다면 ans++;
			visited[now.y][now.x] = 1;
		}

		int num = now.y * N + now.x; // 현재 교차로 번호
		int cir = now.T % 4; // 현재 시간에 따른 신호등 번호
		int light = trafV[num][cir]; // 현재 교차로의 시간에 따른 신호(1~12)중 하나.
		
		int trafDir = trafInfo[light][4];
		if(now.dir != trafDir) continue; // 차량의 방향과 신호등이 바라보는 방향이 다르면 진행불가.

		for(int i = 0; i < 4; i++)
		{
			if(trafInfo[light][i]) // 갈 수 있는 신호여야 진행
			{
				int ny = now.y + ditY[i];
				int nx = now.x + ditX[i];
				if(isOut(ny,nx)) continue;
				q.push({ny, nx, i, now.T + 1});
			}
		}

	}
}

int main(int argc, char** argv)
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	input();
	solve();
	cout << ans;
	return 0;
}