#include<iostream>
#include<algorithm>
using namespace std;

int N, M, K, ans;
int rail[11];
int path[11];
int used[11];

void input(){
	cin >> N >> M >> K;
	for(int i = 0 ; i < N; i++){
		cin >> rail[i];
	}
	ans = 987654321;
}

int getWei(){
	int ret = 0;
	int idx = 0;

	for(int i = 0; i < K; i++)
	{
		int now_sum = 0;

		while(1)
		{
			if(now_sum + path[idx] > M) // 다음거 더하면 박스한도 초과
			{
				ret += now_sum;
				//cout << ret << " ";
				break;
			}
			now_sum += path[idx];
			idx++;
			
			if(idx == N) idx = 0;
		}
	}

	return ret;
}

void dfs(int lev){
	if(lev == N){
		// for(int i = 0; i < N; i++){
		// 	cout << path[i] << " ";
		// }
		// cout << "\n";
		int wei = getWei();
		//cout << wei << " ";
		ans = min(ans, wei);
		return;
	}

	for(int i = 0; i < N; i++){
		if(used[i]) continue;
		used[i] = 1;
		path[lev] = rail[i];
		dfs(lev + 1);
		used[i] = 0;
	}

}

int main(int argc, char** argv)
{
	input();
	dfs(0);
	cout << ans;
	return 0;
}