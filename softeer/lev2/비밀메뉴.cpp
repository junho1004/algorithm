#include<iostream>
#include<string>
using namespace std;

int M, N, K;

string tar, btn_line;

void init(){
	tar = btn_line = "";
}

void input(){
	cin >> M >> N >> K;
	char num;
	for(int x = 0; x < M; x++){
		cin >> num;
		tar += num;
	}
	for(int x = 0; x < N; x++){
		cin >> num;
		btn_line += num;
	}
}

bool solve(){
	// 0은 정상
	if(M > N) return 0;

	if(btn_line.find(tar) == -1) return 0;
	else return 1;
}

int main(int argc, char** argv)
{
	init();
	input();
	if(solve() == 0){
		cout << "normal";
	}
	else cout << "secret";
	return 0;
}