#include<iostream>
#include<queue>
using namespace std;

int N;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void input(){
	cin >> N;
	int st, fin;
	for(int i = 0; i < N; i++)
	{
		cin >> st >> fin;
		pq.push({fin, st});
	}
}

void solve(){
	int lec_cnt = 1;
	int now_fin = pq.top().first;

	while(!pq.empty())
	{
		int next_st = pq.top().second;
		int next_fin = pq.top().first;
		pq.pop();

		if(now_fin <= next_st)
		{
			lec_cnt++;
			now_fin = next_fin;
		}
	}
	cout << lec_cnt;
}

int main(int argc, char** argv)
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	input();
	solve();
	
	return 0;
}