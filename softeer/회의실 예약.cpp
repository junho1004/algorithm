#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

int N, M;
struct Node {
	int start, fin;
};
vector<string> vec_room;
unordered_map<string, vector<Node>> um;

void init() {
	um.clear();
	vec_room.clear();
}

void input() {
	cin >> N >> M;
	string temp;
	for (int x = 0; x < N; x++) {
		cin >> temp;
		vec_room.push_back(temp);
	}

	int num1, num2;

	for (int x = 0; x < M; x++) {
		cin >> temp >> num1 >> num2;
		um[temp].push_back({ num1, num2 });
	}
}


int find_finish(int time_arr[20][2], int one_point) {
	while (1) {
		if (one_point == 18) return 18;

		if (time_arr[one_point][0] == 1) {
			return one_point;
		}
		one_point++;
	}
}

void part_avail(int time_arr[20][2]) {
	int zero_point = 9;
	queue<Node> q;

	// 투포인트로 예약 가능 시간의 시작과 끝을 q에 집어넣을 생각
	while (1) {
		if (zero_point >= 18) break;

		// 예약 가능 시간의 시작 포인트를 찾기 위함.
		if (time_arr[zero_point][1] == 0) {
			
			// 예약 가능 시간의 끝 포인트를 찾기 위함.
			int one_point = find_finish(time_arr, zero_point + 1);

			q.push({ zero_point, one_point });

			zero_point = one_point;
		}

		zero_point++;
	}

	// 출력
	if (q.size() == 0) {
		cout << "Not available\n";
	}
	else {
		cout << q.size() << " available:\n";

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			if (now.start == 9) {
				cout << "09-" << now.fin << "\n";
			}
			else {
				cout << now.start << "-" << now.fin << "\n";
			}
		}
	}
	
}


void solve() {
	// 회의실 오름차순 정렬
	sort(vec_room.begin(), vec_room.end());

	// 정렬된 회의실 끝까지 for문
	for (int y = 0; y < N; y++) {

		// 예약된 회의가 없으면 
		if (um.count(vec_room[y]) == 0) {
			cout << "Room " << vec_room[y] << ":\n";
			cout << "1 available:\n";
			cout << "09-18\n";
		}

		else {
			int book_cnt = um[vec_room[y]].size(); // 예약된 회의 수
			int time_arr[20][2] = { 0 }; // 해당 회의실에 예약된 타임테이블

			// 타임테이블 채우기
			for (int k = 0; k < book_cnt; k++) {
				for (int z = um[vec_room[y]][k].start; z < um[vec_room[y]][k].fin; z++) {
					for (int x = 0; x < 2; x++) {
						time_arr[z][x] = 1;
					}
				}
				time_arr[um[vec_room[y]][k].fin][0] = 1;
			}

			// 해당 회의실 가능 시간 출력
			cout << "Room " << vec_room[y] << ":\n";
			part_avail(time_arr);
		}

		if (y != N - 1) cout << "-----\n"; // 마지막 회의실 이후 구분선 출력 안함
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
	
	return 0;
}