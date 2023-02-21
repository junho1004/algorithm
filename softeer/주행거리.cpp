#include<iostream>
#include<string>
using namespace std;

string ans_lists[5] = {"A", "B", "same"};
int num1, num2;

void init(){
	cin >> num1 >> num2;
}

void solve(){
	if(num1 > num2){
		cout << ans_lists[0];
	}
	else if(num1 < num2){
		cout << ans_lists[1];
	}
	else{
		cout << ans_lists[2];
	}
}

int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	init();
	solve();
	
	return 0;
}