#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, M;

// (H * W)마리 상어 이동 * H(낚시꾼 탐색) * W(마지막 열까지) == 1억
// 상어의 속력은 최대 1000, 1000번을 반복하는 것이 아니라
// 적절한 연산을 통해 반복을 줄여야한다.
// 모든 이동이 끝나고 위치가 같은 상어에 대해 연산을 해준다.
// 맵을 사용하지 않고 벡터로만(정렬) 관리해도 될 것 같다.

struct Node {
	int y, x, speed, dir, weigh;
};
vector<Node> v;

void input() {
	cin >> H >> W >> M;
	int a, b, c, d, e;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d >> e;
		v.push_back({ a,b,c,d,e });
	}
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	return 0;
}