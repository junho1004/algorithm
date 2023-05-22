#include<iostream>
#include<queue>
using namespace std;

bool map[1010][1010];
bool visit_Dfs[1010];
bool visit_Bfs[1010];
int N, M, V;
queue<int> q;

void input() {
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = true;
		map[b][a] = true;
	}
}

void dfs(int start) {
	visit_Dfs[start] = true;
	cout << start << " ";

	for (int i = 1; i <= N; i++) {
		if (map[start][i] == true && visit_Dfs[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	q.push(start);
	visit_Bfs[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 1; i <= N; i++) {
			if (map[now][i] == true && visit_Bfs[i] == false) {
				visit_Bfs[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	
	dfs(V); 
	cout << "\n";
	bfs(V);

	return 0;
}