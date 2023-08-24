#include <iostream>
#include <vector>
#define MAX_N 11
using namespace std;

// 땅 10 x 10
// 가장 처음에 양분은 모든 칸에 5만큼 들어있다.

int N, M, K;
vector<int> treeV[MAX_N][MAX_N]; // 나무의 나이를 저장할 벡터. 2차원 맵에 3차원 느낌으로 데이터를 쌓을 벡터
int AddEnergyMap[MAX_N][MAX_N]; // 겨울에 추가할 에너지를 저장해 놓은 맵
int map[MAX_N][MAX_N]; // 양분을 저장할 맵

void input() {
	cin >> N >> M >> K;
	// 1행 1열부터 시작한다.
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> AddEnergyMap[y][x];
			map[y][x] = 5; // 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
		}
	}
	int r, c, age;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> age;
		treeV[r][c].push_back(age);
	}

}

// 봄 : 나이만큼 양분 섭취, 나이 +1, 하나의 칸에 여러 개의 나무가 있다면 나무가 어린 나무부터 양분을 먹는다.
// 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없다면 나무는 죽는다.
void spring() {

}
// 여름 : 죽은 나무 나이 / 2 == 양분 추가
void summer() {

}
// 가을 : 나이가 5의 배수인 나무가 번식한다. 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 땅 벗어나면 안생겨
void autumn() {

}
// 겨울 : 땅에 양분을 추가한다. 양분의 양은 A[r][c]이며 입력으로 주어진다.
void winter() {

}

void solve() {
	while (K--) {
		spring();
		summer();
		autumn();
		winter();
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}