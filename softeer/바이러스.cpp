// int를 벗어나고 long long범위를 벗어난 숫자의 연산
#include<iostream>
using namespace std;

long long K;
int P, N;

void init(){
	K = P = N = 0;
	cin >> K >> P >> N;
}

void solve(){
	for(int x = 0; x < N; x++){
		K *= P;
		if(K > 1000000007) K %= 1000000007; 
	}
}

int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	init();
	solve();
	cout << K;
	return 0;
}