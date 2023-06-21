#include <iostream>
using namespace std;

int N;
int arr[1010];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {

}

int main() 
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	return 0;
}