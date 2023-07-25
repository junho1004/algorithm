#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int cnt;
    queue<Node> q;
    int used[100][100] = {0};
    int ditY[4] = { -1,1,0,0 };
    int ditX[4] = { 0,0,-1,1 };
    
    for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (picture[y][x] == 0) continue;
            if(used[y][x] == 1) continue;
            
            q.push({ y,x });
            used[y][x] = 1;

            int tar = picture[y][x];
            cnt = 1;

            while (!q.empty()) {
                Node now = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int ny = now.y + ditY[i];
                    int nx = now.x + ditX[i];
                    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
                    if (picture[ny][nx] == 0) continue;
                    if (picture[ny][nx] != tar) continue;
                    if (used[ny][nx] == 1) continue;
                    used[ny][nx] = 1;
                    cnt++;
                    q.push({ ny,nx });
                }
            }

			if (max_size_of_one_area < cnt) max_size_of_one_area = cnt;
            
			number_of_area++;
		}
	}
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}