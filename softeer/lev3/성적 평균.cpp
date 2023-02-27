#include<iostream>
#include<cstring>
using namespace std;

int N, K, score;
int prefix[1000010];

void init(){
	memset(prefix, 0, sizeof(prefix));
}

void input(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> score;
		prefix[i] = prefix[i-1] + score;
	}
}

void solve(){
	int first, last;

	for(int x = 0; x < K; x++){
		cin >> first >> last;
		int divide = last - first + 1;
		double hap = prefix[last] - prefix[first-1];
		double ans = hap / divide;
		printf("%.2f", ans);
		cout << "\n";
	}
}

int main(int argc, char** argv)
{
	init();
	input();
	solve();
	return 0;
}