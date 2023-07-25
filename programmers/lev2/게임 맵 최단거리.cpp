#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Coord{
    int y,x;
    int lev;
};
queue<Coord> q;
int ditY[] = {-1,1,0,0};
int ditX[] = {0,0,-1,1};
int visited[110][110];
int H, W;
vector<vector<int>> v;

bool isOut(int y, int x){
    return y < 0 || x < 0 || y >= H || x >= W;
}

int bfs()
{
    q.push({0, 0, 1});
    visited[0][0] = 1;
    
    while(!q.empty())
    {
        Coord now = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = now.y + ditY[i];
            int nx = now.x + ditX[i];
            if(ny == H - 1 && nx == W - 1) return now.lev + 1;
            if(isOut(ny,nx)) continue;
            if(visited[ny][nx]) continue;
            if(v[ny][nx] == 0) continue; // 벽
            visited[ny][nx] = 1;
            q.push({ny, nx, now.lev + 1});
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    
    H = maps.size();
    W = maps[0].size();
    v = maps;
    
    // 도착지 근처가 모두 벽이라면 -1 리턴(효율)
    // int flag = 0;
    // for(int i = 0; i < 4; i++){
    //     int ny = H - 1 + ditY[i];
    //     int nx = W - 1 + ditX[i];
    //     if(isOut(ny,nx)) continue;
    //     if(v[ny][nx] == 0) flag = 1;
    //     else{
    //         flag = 0;
    //         break;
    //     }
    // }
    // int answer;
    // if(flag == 1) return -1;
    // else answer = bfs();

    int answer = bfs();
    return answer;
}