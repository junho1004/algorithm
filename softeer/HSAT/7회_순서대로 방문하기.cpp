#include<iostream>
using namespace std;

int N, M, ans;
int ditY[4] = {-1,1,0,0};
int ditX[4] = {0,0,-1,1};

int map[5][5];
struct Coord{
  int y, x;
};
Coord middle[18];

void input(){
  cin >> N >> M;
  for(int y = 1; y <= N; y++){
    for(int x = 1; x <= N; x++){
      cin >> map[y][x];
    }
  }
  for(int i = 0; i < M; i++){
    cin >> middle[i].y >> middle[i].x;
  }
  ans = 0;
}

void dfs(int nowY, int nowX, int idx)
{
  // idx가 M이란 것은 종착지에 무사히 도착했다는말이다.
  if(idx == M){
    ans++;
    return;
  }
  
  for(int i = 0; i < 4; i++){
    int ny = nowY + ditY[i];
    int nx = nowX + ditX[i];
    if(ny < 1 || nx < 1 || ny >= N + 1 || nx >= N + 1) continue; // 맵 나감
    if(map[ny][nx]) continue; // 벽(1)이나 이미 온 길(2)

    // 나중에 방문해야할 곳을 방문하려 한다면? 애초에 그 길을 가지않고 시간을 줄인다.
    int flag = 0;
    for(int k = idx + 1; k < M; k++){
      if(ny == middle[k].y && nx == middle[k].x){ 
        flag = 1;
        break;
      }
    }
    if(flag) continue;
    
    map[ny][nx] = 2; // 지나온 길 표시
    // 다음 갈 곳이 경유지라면
    if(ny == middle[idx].y && nx == middle[idx].x) dfs(ny, nx, idx + 1);
    else dfs(ny, nx, idx); // 경유지가 아니라면
    map[ny][nx] = 0; // 지나온 길 표시 해제
  }
}

void solve(){
  // 시작점 이미 지나온 길이라고 표시
  map[middle[0].y][middle[0].x] = 2;

  dfs(middle[0].y, middle[0].x, 1);
  
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