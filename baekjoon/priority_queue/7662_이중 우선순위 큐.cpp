#include <iostream>
#include <set>
using namespace std;

int N, num;
char cmd;

void input() {
	cin >> N;
}

void solve() {
	multiset<int> ms;

	while (N--) {
		cin >> cmd >> num;
		if (cmd == 'I') {
			ms.insert(num);
			continue;
		}

		if (ms.empty()) continue;
		// ms.begin() 과 ms.end()가 참조하는 부분이 다름
		// end값을 가져오려면 auto iter를 사용해야함
		else {
			// 최댓값 삭제
			if (num == 1) {
				auto iter = ms.end(); //맨 끝값 + 1
				iter--; // 맨 끝값으로 이동
				ms.erase(iter);
			}
			// 최솟값 삭제
			else if (num == -1) {
				ms.erase(ms.begin());
			}
		}
	}
	if (ms.empty())
	{
		cout << "EMPTY" << '\n';
	}
	else
	{
		auto end_iter = ms.end();
		end_iter--;
		cout << *end_iter << ' ' << *ms.begin() << '\n';
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int tcCnt;
	cin >> tcCnt;
	for (int tc = 1; tc <= tcCnt; tc++) {
		input();
		solve();
	}
	return 0;
}




/// deque 시간초과
//#include <iostream>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//int N, num;
//char cmd;
//
//void input() {
//	cin >> N;
//}
//
//void solve() {
//	deque<int> dq;
//
//	while (N--) {
//		cin >> cmd >> num;
//		// 삽입
//		if (cmd == 'I') {
//			dq.push_back(num);
//		}
//		// 삭제
//		else {
//			// 삭제할 것이 없다면 넘어감
//			if (dq.empty()) continue;
//
//			// 삭제하기 전에 오름차순 정렬
//			sort(dq.begin(), dq.end());
//
//			// 최솟값 삭제
//			if (num == -1) {
//				dq.pop_front();
//			}
//			// 최댓값 삭제
//			else if (num == 1) {
//				dq.pop_back();
//			}
//		}
//	}
//
//	if (dq.empty()) cout << "EMPTY" << "\n";
//	else {
//		sort(dq.begin(), dq.end());
//		cout << dq.back() << " " << dq.front() << "\n";
//	}
//}
//
//int main() {
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(0);
//	freopen_s(new FILE*, "input.txt", "r", stdin);
//	
//	int tcCnt;
//	cin >> tcCnt;
//	for (int tc = 1; tc <= tcCnt; tc++) {
//		input();
//		solve();
//	}
//	return 0;
//}