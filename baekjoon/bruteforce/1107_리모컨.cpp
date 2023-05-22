#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int channel;
int btn_cnt;
vector<char> broken_Btn;
int ans;

void input() {
	cin >> channel >> btn_cnt;
	char temp;
	for (int i = 0; i < btn_cnt; i++) {
		cin >> temp;
		broken_Btn.push_back(temp);
	}
	ans = 21e8;
}

bool isValid(int num) {
	string tar = to_string(num);

	for (int x = 0; x < tar.size(); x++) {
		for (int k = 0; k < broken_Btn.size(); k++) {
			if (tar[x] == broken_Btn[k]) return false;
		}
	}

	return true;
}

void getAns(int num, int offset) {
	int len = to_string(num).size();

	ans = min(ans, len + offset);
}

void solve() {
	// 현재 채널에서 목표채널까지 눌러야하는 + or - 개수
	int offset = 0;

	// 목표 채널이 100일 때
	if (channel == 100) {
		ans = 0;
		return;
	}
	// 일단 ans에 +,-만 눌렀을 때 값을 저장
	ans = abs(channel - 100);

	if (isValid(channel)) {
		getAns(channel, offset);
		return;
	};
	// 버튼을 아무리 눌러도 갈 수 없으면 +,-한 것만으로 답이 나와야하기에
	// 아래 무한루프를 들어가면 안된다.
	if (btn_cnt == 10) return;

	while (1) {
		offset++;

		int down = channel - offset;
		if (down >= 0) {
			if (isValid(down)) {
				getAns(down, offset);
				break;
			}
		}
		
		int up = channel + offset;
		if (up < 1000000) {
			if (isValid(up)) {
				getAns(up, offset);
				break;
			}
		}
		
	}

	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	solve();
	cout << ans;
	return 0;
}