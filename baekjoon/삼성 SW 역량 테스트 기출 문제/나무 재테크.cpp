#include <iostream>
#include <vector>
#define MAX_N 11
using namespace std;

// �� 10 x 10
// ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.

int N, M, K;
vector<int> treeV[MAX_N][MAX_N]; // ������ ���̸� ������ ����. 2���� �ʿ� 3���� �������� �����͸� ���� ����
int AddEnergyMap[MAX_N][MAX_N]; // �ܿ￡ �߰��� �������� ������ ���� ��
int map[MAX_N][MAX_N]; // ����� ������ ��

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

}

// �� : ���̸�ŭ ��� ����, ���� +1, �ϳ��� ĭ�� ���� ���� ������ �ִٸ� ������ � �������� ����� �Դ´�.
// ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���ٸ� ������ �״´�.
void spring() {

}
// ���� : ���� ���� ���� / 2 == ��� �߰�
void summer() {

}
// ���� : ���̰� 5�� ����� ������ �����Ѵ�. ������ 8���� ĭ�� ���̰� 1�� ������ �����. �� ����� �Ȼ���
void autumn() {

}
// �ܿ� : ���� ����� �߰��Ѵ�. ����� ���� A[r][c]�̸� �Է����� �־�����.
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