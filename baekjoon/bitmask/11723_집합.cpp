#include<iostream>
using namespace std;

int N, num, bit;
string str;

void solve() {
	bit = 0;
	cin >> N;
	while (N--) {
		cin >> str;
		// 시간을 줄이려 2번째 글자 따기
		if (str[1] == 'd') { // 추가
			cin >> num;
			bit = bit | (1 << num);
		}
		else if (str[1] == 'e') { // 삭제
			cin >> num;
			bit = bit & ~(1 << num);
		}
		else if (str[1] == 'h') { // 체크
			cin >> num;
			if (bit & (1 << num)) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (str[1] == 'o') { // 토글
			cin >> num;
			bit = bit ^ (1 << num);
		}
		else if (str[1] == 'l') { // 전체
			//bit = bit | ~0;
			bit = (1 << 21) - 1;
		}
		else if (str[1] == 'm') { // 비우기
			bit = 0;
		}

	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();

	return 0;
}