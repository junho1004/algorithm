#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int limit_kg, N;

struct Node{
	int kg, price;
};

vector<Node> bagpack;

void init(){
	bagpack.clear();
}

void input(){
	cin >> limit_kg >> N;
	int temp1, temp2;
	for(int y = 0; y < N; y++){
		cin >> temp1 >> temp2;
		bagpack.push_back({temp1, temp2}); 
	}
}

bool cmp(Node t, Node v){
	if(t.price > v.price) return 1;
	if(t.price < v.price) return 0;
	if(t.kg < v.kg) return 1;
	return 0;
}

int solve(){
	sort(bagpack.begin(), bagpack.end(), cmp);

	int money = 0;
	int remain_kg = limit_kg;

	for(int x = 0; x < bagpack.size(); x++){
		
		if(remain_kg - bagpack[x].kg < 0){
			money += (remain_kg * bagpack[x].price);
			break;
		}

		money += (bagpack[x].price * bagpack[x].kg);

		remain_kg -= bagpack[x].kg;
	}
	
	return money;
}

int main(int argc, char** argv)
{
	init();
	input();
	cout << solve();

	return 0;
}