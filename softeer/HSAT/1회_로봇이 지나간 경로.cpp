#includeiostream
#includevector
#includequeue
#includestring
using namespace std;

int H, W;
vectorstring map;

struct Node{
	int y,x,dir;
};
Node start;

 상 우 하 좌
int ditY[] = {-1,0,1,0};
int ditX[] = {0,1,0,-1};
char op[] = {'^', '', 'v', ''};
queueNode q;
int used[30][30];
string ans;

void input()
{
	cin  H  W;
	string str;
	for(int i = 0; i  H; i++){
		cin  str;
		map.push_back(str);
	}
	ans = ;
}

bool isOut(int y, int x){
	return y  0  x  0  y = H  x = W;
}

bool isStart(int y, int x){
	int sharpCnt = 0;
	int dir;
	for(int i = 0; i  4; i++){
		int ny = y + ditY[i];
		int nx = x + ditX[i];
		if(isOut(ny,nx)) continue;
		if(map[ny][nx] == '#') {
			sharpCnt++;
			dir = i;
		}
		if(sharpCnt  1) return 0;
	}
	if(sharpCnt == 1)
	{
		start = {y,x,dir};
		return 1;
	}
	return 0;
}

void findStart()
{
	for(int y = 0; y  H; y++){
		for(int x = 0; x  W; x++){
			if(map[y][x] == '#'){
				 사실상 꼭짓점 둘 중 하나의 점에서 출발하면 명령어의 개수는 똑같다.
				if(isStart(y,x)) return; 
			}
		}
	}
}

void findPath(){
	q.push({start.y, start.x, start.dir});
	used[start.y][start.x] = 1;

	while(!q.empty())
	{
		Node now = q.front();
		q.pop();

		for(int i = 0; i  4; i++){
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if(isOut(ny,nx)) continue;
			if(used[ny][nx]) continue;
			if(map[ny][nx] == '.') continue;
			 현재 바라보는 방향과 갈 곳이 같다.
			if(now.dir == i){
				used[ny][nx] = 1;
				q.push({ny+ditY[i], nx+ditX[i], i});  2칸 앞을 푸시
				ans += A;
			}
			else
			{
				if(i == (now.dir + 1) % 4) ans += R;  우로 돌아야함
				else if(i == (now.dir + 3) % 4) ans += L;  좌로 돌아야함
				q.push({now.y, now.x, i});  제자리를 푸시하되 방향만 바꿈
			}
		}
	}
	
}

void solve(){
	findStart();
	findPath();
}

int main(int argc, char argv)
{
	input();
	solve();
	cout  start.y + 1     start.x + 1  n;
	cout  op[start.dir]  n;
	cout  ans;
	return 0;
}