#include<iostream>
#include<queue>
#include<string>
#include<cmath>
using namespace std;

int N, K, ans;
string str;
queue<int> robotQ;
queue<int> compoQ;

void input(){
	cin >> N >> K;
	cin >> str;
	ans = 0;
}

void solve(){


	for(int i = 0; i < N; i++){
		if(str[i] == 'P') robotQ.push(i);
		else compoQ.push(i);
	}
	
	// 둘 다 비어있지 않을때까지
	while(!robotQ.empty() && !compoQ.empty())
	{

		// 로봇 기준 잡을 수 있으면 잡는다.
		int robot = robotQ.front();
		int compo = compoQ.front();

		// 잡을 수 있다.
		if(abs(robot - compo) <= K){
			ans++;
			robotQ.pop();
			compoQ.pop();
		} 
		else{
			if(robot < compo) robotQ.pop(); // 못 잡을 때 로봇이 더 왼쪽에 있다면 로봇지움
			else compoQ.pop(); // 로봇이 더 오른쪽이라면 부품지움
		}
	}
}


int main(int argc, char** argv)
{
	input();
	solve();
	cout << ans;
	return 0;
}