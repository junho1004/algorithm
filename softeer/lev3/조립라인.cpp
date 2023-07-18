#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 1010
using namespace std;

int N;
struct Node{
	int A,B;
	int AtoB, BtoA;
};
vector<Node> v;
int AN, BN;

int dp[2][MAX_N];

void input(){
	cin >> N;
	int a,b,c,d;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b >> c >> d;
		v.push_back({a,b,c,d});
	}
	cin >> AN >> BN;
	v.push_back({AN,BN,0,0});
}

void solve(){
	// for(int i = 0; i < v.size(); i++){
	// 	cout << v[i].A << " " << v[i].B << " " << v[i].AtoB << " " << v[i].BtoA << "\n";
	// }

	dp[0][0] = v[0].A;
	dp[1][0] = v[0].B;
	
	for(int i = 1; i <= N - 1; i++)
	{
		int tmpA = min(dp[0][i-1] + v[i].A, dp[1][i-1] + v[i-1].BtoA + v[i].A);
		dp[0][i] = tmpA;

		int tmpB = min(dp[1][i-1] + v[i].B, dp[0][i-1] + v[i-1].AtoB + v[i].B);
		dp[1][i] = tmpB;
	}

	// for(int line = 0; line <= 1; line++){
	// 	for(int i = 0; i <= N - 1; i++){
	// 		cout << dp[line][i] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	int ans = min(dp[0][N-1], dp[1][N-1]);
	cout << ans;
}


int main(int argc, char** argv)
{
	input();
	solve();
	return 0;
}