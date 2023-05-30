// 벡터 풀이 10152KB 468ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> ori_v;

void input() {
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		ori_v.push_back(a);
	}
}

void solve() {
	vector<int> cpy_v = ori_v;
	// 기본 오름차순 정렬
	sort(cpy_v.begin(), cpy_v.end(), less<>());

	// 복사후 오름차순 정렬된 벡터에서 unique함수를 통해 중복을 제거해야한다.
	// unique함수는 벡터의 중복 원소를 제일 뒷 부분으로 보내고 앞에서부터 원소들을 채운다.
	// 주로 정렬된 벡터에서, erase(unique(begin,end), end)와 같이 사용하여 중복을 제거하는데 사용된다.
	// 맨뒤로 보내진 첫 번째 중복된 원소의 iterator를 반환한다.
	cpy_v.erase(unique(cpy_v.begin(), cpy_v.end()), cpy_v.end());
	
	// lower_bound(start, end, key)
	// key 값 보다 크거나 같은값이 제일 처음 등장하는 곳 위치를 리턴
	// 찾으려는 key값이 없으면 key값보다 큰 값 중 가장 작은 정수값을 찾는다.
	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(cpy_v.begin(), cpy_v.end(), ori_v[i]);
		// 원소의 iterator값에서 vector 시작 주소를 빼면 인덱스 값을 얻을 수 있음.
		//cout << iter - cpy_v.begin() << " ";
		cout << iter - cpy_v.begin() << " ";
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