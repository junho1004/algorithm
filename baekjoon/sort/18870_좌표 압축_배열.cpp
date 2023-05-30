// 배열 풀이 21,556KB, 440ms
#include <iostream>
#include<algorithm>
using namespace std;

int N;
struct Node {
	int val;
	int idx;
};
Node sorted[1000010];
Node counted[1000010];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sorted[i].val;
		sorted[i].idx = i;
	}
}
bool cmp(Node t, Node v) {
	return t.val < v.val;
}

bool cmp2(Node t, Node v) {
	return t.idx < v.idx;
}
void solve() {
	// 원본의 순서는 구조체의 idx가 저장함 
	sort(sorted, sorted + N, cmp);

	// 오름차순 정렬된 배열을 기준으로 끝까지 훑으며 count를 함
	// 카운트배열에도 출력을 위해 idx를 저장
	counted[0].idx = sorted[0].idx;
	for (int i = 1; i < N; i++) {
		if (sorted[i].val != sorted[i - 1].val) {
			counted[i].val = counted[i - 1].val + 1;
		}

		else counted[i].val = counted[i - 1].val;
		counted[i].idx = sorted[i].idx;
	}
	// idx를 오름차순으로 정렬 후 카운트 값만 출력하면 정답.
	sort(counted, counted + N, cmp2);
	for (int i = 0; i < N; i++) {
		cout << counted[i].val << " ";
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}