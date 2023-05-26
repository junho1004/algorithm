#include<iostream>
#include<unordered_map>
using namespace std;

int N, num;
string str;

unordered_map<int, bool> um;

void solve() {

	cin >> N;
	while (N--) {
		cin >> str;
		

		if (str == "add") {
			cin >> num;
			um[num] = true;
		}
		else if (str == "remove") {
			cin >> num;
			um.erase(num);
		}
		else if (str == "check") {
			cin >> num;
			if (um.count(num)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "toggle") {
			cin >> num;
			if (um.count(num)) um.erase(num);
			else um[num] = true;
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				um[i] = true;
			}
		}
		else if (str == "empty") {
			um.clear();
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