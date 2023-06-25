//#include <iostream>
//#include <cmath>
//using namespace std;
//int col[16];
//int n;
//int ans = 0;
//void queen(int x){
//    if(n == x){
//        ans++; // 카운트 +1
//    }else{
//        for (int i = 0; i < n;i++){
//            col[x] = i; // 퀸의 위치를 정함
//            bool can = true;
//            for (int j = 0; j < x;j++){
//                if(col[x] == col[j] || abs(col[x] - col[j]) == x - j){
//                    //정한 위치의 퀸이 위쪽 퀸과 충돌하는 지 확인
//                    // 1. 같은 행에 있는가
//                    // 2. 대각선에 있는가
//                    can = false; //충돌하면 다른 열의 위치로 놓아야함
//                    break;
//                }
//            }
//            if(can){ // 충돌하지 않는다면 다음 행으로 넘어감.
//                queen(x + 1);
//            }     
//        }
//    }
//} //백트래킹
// 
//int main(){
//    cin >> n;
//    queen(0);
//    cout << ans;
//    return 0;
//} // 1.5h 


#include <iostream>
using namespace std;

int N, cnt;
int chess[20];

void input() {
	cin >> N;
	cnt = 0;
}

void dfs(int lev)
{
	if (lev == N) {
		cnt++;
		return;
	}

	for (int point = 0; point < N; point++) {


		int flag = 0;
		// 현재 행의 퀸의 위치를 정할 때 위쪽에 만들어놓은 퀸의 위치와 비교
		for (int k = 1; k <= lev; k++) {
			//좌상단 대각
			if (chess[lev - k] == point - k) { flag = 1; break; }

			//위로 직선
			if (chess[lev - k] == point) { flag = 1; break; }

			//우상단 대각
			if (chess[lev - k] == point + k) { flag = 1; break; }
		}
		if (flag == 1) continue;

		chess[lev] = point;
		dfs(lev + 1);
		chess[lev] = 0;

	}
}

void solve() {
	dfs(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
	cout << cnt;
	return 0;
}