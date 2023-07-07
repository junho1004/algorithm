#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 300'010
typedef long long ll;
using namespace std;

int N, K;
ll ans;

pair<int,int> jew[MAX_N];
int bag[MAX_N];

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> jew[i].first >> jew[i].second;
	}

	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	ans = 0;
}


void solve() {
	// 보석과 가방 모두 무게 오름차순 정렬
	// 구조체 배열과 cmp를 이용해 정렬하면 시간초과걸림
	// 그냥 pair쓰는게 가장 좋은듯
	sort(jew, jew + N);
	sort(bag, bag + K);

	priority_queue<int> pq;

	// 하나의 가방에 여러개의 보석이 들어갈 수 있음
	// 보석을 idx를 증가시켜가며 pq에 push
	int idx = 0;

	for (int i = 0; i < K; i++) 
	{
		// 보석의 개수가 N보다 적고, 가방에 들어갈 수 있는 보석이면
		while (idx < N && jew[idx].first <= bag[i]) 
		{
			// 현재 가방에 들어갈 수 있는 보석들 가격 내림차순
			pq.push(jew[idx].second);
			idx++;
		}
		// pq가 비어있을 수도 있다.(현재 가방에 들어갈 수 없는 보석 존재 가능)
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
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