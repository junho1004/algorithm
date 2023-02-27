#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N, block_cnt;
string map[30];
int used[30][30];
int ditY[4] = {-1,1,0,0};
int ditX[4] = {0,0,-1,1};

struct Node{
	int y, x;
};

vector<int> obstacle;

void init(){
	N = 0;
	block_cnt = 0;
	for(int y = 0; y < 30; y++){
		map[y] = "";
		for(int x = 0; x < 30; x++){
			used[y][x] = 0;
		}
	}
}

void input(){
	cin >> N;
	for(int y = 0; y < N; y++){
		cin >> map[y];
	}
}

bool isOut(int ny, int nx){
	return ny < 0 || nx < 0 || ny >= N || nx >= N;
}

void floodfill(int nowY, int nowX){
	if(used[nowY][nowX] == 1) return;
	block_cnt++;

	int cnt = 0;

	queue<Node> q;
	q.push({nowY, nowX});
	used[nowY][nowX] = 1;

	while(!q.empty()){
		cnt++;
		Node now = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if(isOut(ny,nx)) continue;
			if(map[ny][nx] == '0') continue;
			if(used[ny][nx] == 1) continue;
			used[ny][nx] = 1;

			q.push({ny,nx});
		}
	}

	obstacle.push_back(cnt);
}

void solve(){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(map[y][x] == '1') floodfill(y,x);
		}
	}

	sort(obstacle.begin(), obstacle.end());
}

int main(int argc, char** argv)
{
	init();
	input();
	solve();

	cout << block_cnt << "\n";
	for(int y = 0; y < obstacle.size(); y++){
		cout << obstacle[y] << "\n";
	}
	return 0;
}