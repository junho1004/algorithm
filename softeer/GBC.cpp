//투 포인터인데 원본을 건들지 않기엔 벡터가 두배로 필요할 것 같다.
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

int N, M, ans;

struct Node{
	int dist;
	int speed;
};

vector<Node> v_origin;
vector<Node> v_test;

void init(){
	ans = 0;
	N = M = 0;
	v_origin.clear();
	v_test.clear();
}

void input(){
	cin >> N >> M;
	int tmp1, tmp2;
	for(int x = 0; x < N; x++){
		cin >> tmp1 >> tmp2;
		v_origin.push_back({tmp1, tmp2});
	}

	for(int x = 0; x < N; x++){
		cin >> tmp1 >> tmp2;
		v_test.push_back({tmp1, tmp2});
	}
}


void solve(){
	int point1, point2;
	point1 = point2 = 0;

	int tmp_dist, tmp_speed;

	while(1){
		if(point1 == N || point2 == M) break;

		tmp_speed = v_test[point2].speed - v_origin[point1].speed;
		ans = max(ans, tmp_speed);

		if(v_origin[point1].dist > v_test[point2].dist){
			tmp_dist = v_origin[point1].dist - v_test[point2].dist;
			v_origin[point1].dist = tmp_dist;

			point2++;
		}
		else if(v_origin[point1].dist < v_test[point2].dist){	
			tmp_dist = v_test[point2].dist - v_origin[point1].dist;
			v_test[point2].dist = tmp_dist;

			point1++;
		}
		else{
			point1++;
			point2++;
		}
	}

}

int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	init();
	input();
	solve();
	cout << ans;
	return 0;
}