#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 11
using namespace std;

// �� 10 x 10
// ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.

int N, M, K, ans;
vector<int> treeV[MAX_N][MAX_N]; // ������ ���̸� ������ ����. 2���� �ʿ� 3���� �������� �����͸� ���� ����
int AddEnergyMap[MAX_N][MAX_N]; // �ܿ￡ �߰��� �������� ������ ���� ��
int map[MAX_N][MAX_N]; // ����� ������ ��

int ditY[8] = { -1,-1,-1,0,0,1,1,1 };
int ditX[8] = { -1,0,1,-1,1,-1,0,1 };

struct Coord {
	int y, x;
};
queue<Coord> spreadQ;

void input() {
	cin >> N >> M >> K;
	// 1�� 1������ �����Ѵ�.
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> AddEnergyMap[y][x];
			map[y][x] = 5; // ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.
		}
	}
	int r, c, age;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> age;
		treeV[r][c].push_back(age);
	}
	ans = 0;
}


// ���� : ���� ���� ���� / 2 == ��� �߰�
void summer(int y, int x, int deadCnt) {
	for (int j = 0; j < deadCnt; j++) {
		map[y][x] += treeV[y][x].back() / 2;
		treeV[y][x].pop_back(); // ���� ������ ó��
	}
}

// �� : ���̸�ŭ ��� ����, ���� +1, �ϳ��� ĭ�� ���� ���� ������ �ִٸ� ������ � �������� ����� �Դ´�.
// ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���ٸ� ������ �״´�.
void spring() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int size = treeV[y][x].size();
			if (size == 0) continue;
			sort(treeV[y][x].begin(), treeV[y][x].end()); // � �������� �������� ����

			int deadFlag = 0;
			int now_energy = map[y][x];
			int deadCnt = 0;
			for (int k = 0; k < size; k++)
			{
				if (treeV[y][x][k] > now_energy) {
					deadFlag = 1;
					deadCnt = size - k; // ������ ���� ���� ���� ���� ����Ѵ�.
					//now_energy = 0; // ����� �ƿ� ���Դ´�. ����� �ǵ�� �ȵ�
					break;
				}
				else {
					now_energy -= treeV[y][x][k];
					treeV[y][x][k] += 1;
					if (treeV[y][x][k] % 5 == 0) spreadQ.push({ y,x }); // ������ ���� ���İ����� ������ q�� �־���´�.
				}
			}
			map[y][x] = now_energy;
			if (deadFlag) summer(y, x, deadCnt); // ��иʿ� ������������ / 2 ���� �߰��Ѵ�.
		}
	}
}

// ���� : ���̰� 5�� ����� ������ �����Ѵ�. ������ 8���� ĭ�� ���̰� 1�� ������ �����. �� ����� �Ȼ���
void autumn()
{
	while (!spreadQ.empty())
	{
		Coord now = spreadQ.front();
		spreadQ.pop();
		for (int i = 0; i < 8; i++) {
			int ny = now.y + ditY[i];
			int nx = now.x + ditX[i];
			if (ny < 1 || nx < 1 || ny >= N + 1 || nx >= N + 1) continue;
			treeV[ny][nx].push_back(1); // ���̰� 1�� ������ ����
		}

	}
}
// �ܿ� : ���� ����� �߰��Ѵ�. ����� ���� A[r][c]�̸� �Է����� �־�����.
void winter() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			map[y][x] += AddEnergyMap[y][x];
		}
	}
}

void solve() {
	while (K--) {
		spring();
		autumn();
		winter();
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			ans += treeV[y][x].size();
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << ans;
	return 0;
}