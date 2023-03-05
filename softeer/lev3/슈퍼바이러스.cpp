#include<iostream>
#define ll long long
#define Mod 1000000007
using namespace std;

// 3의 10승이면 곱하기 연산 9번
// 3의 5승을 두번 곱하면 곱하기 연산 5번
// 분할정복 개념으로 다가가야한다.
ll K, P, N;

void input() {
    cin >> K >> P >> N;
}

ll solve(ll p, ll n) {
    if (n == 1) return p;

    ll ret = solve(p, n / 2);

    ret = ret * ret % Mod; // 짝수승
    if(n % 2 == 1) {
        // 홀수승
        ret = ret * p % Mod;
    }
    return ret;
}

int main(int argc, char** argv)
{
    input();
    ll ans = solve(P, 10 * N) * K % Mod;
    cout << ans;
    return 0;
}
