#include <iostream>
using namespace std;
typedef long long ll;

ll A, B, C, temp;

void input() {
	cin >> A >> B >> C;
}
// long long 타입을 사용해 for문을 돌려도 21억번 반복이므로 분할정복으로 다가가야한다.
// 아래식을 기억해두자.
//if(b % 2 == 0)
//a ^ b = a ^ (b / 2) * a ^ (b / 2)
//
//if(b % 2 == 1)
//a ^ b = a ^ (b / 2) * a ^ (b / 2 + 1)

ll solve(ll b) {
	if (b == 0) return 1;
	if (b == 1) return A % C;

	// temp를 사용함으로써 현재 함수에서 그 값을 기억할 수 있다.
	temp = solve(b / 2) % C;
	
	// 제곱수가 짝수일 때
	if (b % 2 == 0) return temp * temp % C;
	
	// 제곱수가 홀수일 때
	return temp * temp % C * A % C;
	// a^ b = a ^ (b / 2) * a ^ (b / 2 + 1)
	// ==> a ^ (b / 2) * a ^ (b / 2) * a ^ 1
	// 어떤수를 곱할때 마다 모듈러 연산을 해줘야함.
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	cout << solve(B);

	
	return 0;
}
