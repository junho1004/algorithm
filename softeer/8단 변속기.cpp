#include<iostream>
using namespace std;


int gear[10];

void input(){
	for(int x = 1; x < 9; x++){
		cin >> gear[x];
	}
}

int solve(){
	if(gear[1] == 1){
		for(int x = 2; x <= 8; x++){
			if(gear[x] != gear[x-1] + 1) return 3;
		}
		return 1;
	}
	else if(gear[1] == 8){
		for(int x = 2; x <= 8; x++){
			if(gear[x] != gear[x-1] - 1) return 3;
		}
		return 2;
	}

	else return 3;
}

int main(int argc, char** argv)
{
	input();
	if(solve() == 1){
		cout << "ascending\n";
	}
	else if(solve() == 2){
		cout << "descending\n";
	}
	else cout << "mixed\n";

	return 0;
}