// 원본을 건드리고 풀었음.
// 조금 더 깔끔하게 풀 필요성이 있음
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

// 12시부터 시계방향으로 번호매김
// 12시가 0번, 가운데가 6번
// 켜져있으면 1, 아니면 0
// 마지막열은 켜진 전구의 개수

int digit_Nums[10][8] = {
	1,1,1,1,1,1,0,6,
	0,1,1,0,0,0,0,2,
	1,1,0,1,1,0,1,5,
	1,1,1,1,0,0,1,5,
	0,1,1,0,0,1,1,4,
	1,0,1,1,0,1,1,5,
	1,0,1,1,1,1,1,6,
	1,1,1,0,0,1,0,4,
	1,1,1,1,1,1,1,7,
	1,1,1,1,0,1,1,6
};

int ans;
string A, B;

void init(){
	ans = 0;
	cin >> A >> B;
}

void cntAns(int idx){
	for(int x = 0; x < 7; x++){
		if(digit_Nums[A[idx] - 48][x] + digit_Nums[B[idx] - 48][x] == 1) ans++;
	}
}

void solve(){
	int len_A = A.size();
	int len_B = B.size();
	
	if(len_A == len_B){
		for(int x = 0; x < len_A; x++){
			cntAns(x);
		}
	}
	else if(len_A > len_B){
		int cutIdx = len_A - len_B;

		for(int x = 0; x < cutIdx; x++){
			ans += digit_Nums[A[0] - 48][7];
			A.erase(0,1);
		}

		for(int x = 0; x < len_B; x++){
			cntAns(x);
		}
	}
	else{
		int cutIdx = len_B - len_A;

		for(int x = 0; x < cutIdx; x++){
			ans += digit_Nums[B[0] - 48][7];
			B.erase(0,1);
		}

		for(int x = 0; x < len_A; x++){
			cntAns(x);
		}
	}

}

int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int tcCnt;
	cin >> tcCnt;

	for(int tc = 1; tc <= tcCnt; tc++){
		init();
		solve();
		cout << ans << "\n";
	}
	return 0;
}