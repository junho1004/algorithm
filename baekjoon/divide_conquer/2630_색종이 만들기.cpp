#include<iostream>
using namespace std;

int N;
int map[130][130];
int cnt_white, cnt_blue;

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	cnt_white = cnt_blue = 0;
}

void divide_conquer(int startY, int startX, int size) {
	int check_color = map[startY][startX];

	for (int y = startY; y < startY + size; y++) {
		for (int x = startX; x < startX + size; x++) {

			// 사이즈 만큼의 정사각형을 볼 때 다른 색깔이 있으면 check_color를 2로 만들어준다.
			if (check_color == 0 && map[y][x] == 1) check_color = 2;
			else if (check_color == 1 && map[y][x] == 0) check_color = 2;

			if (check_color == 2) {
				// 1 사분면 좌상
				divide_conquer(startY, startX, size / 2);
				// 2 사분면 우상
				divide_conquer(startY, startX + size / 2, size / 2);
				// 3 사분면 좌하
				divide_conquer(startY + size / 2, startX, size / 2);
				// 4 사분면 우하
				divide_conquer(startY + size / 2, startX + size / 2, size / 2);
				
				// return 문이 있어야 이전 사이즈 그대로 다음 사분면으로 넘어간다.
				// 없다면 이전 사이즈의 해당 사분면에서 그대로 탐색을 재개하기에 중복됨.
				return;
				 
			}

		}
	}
	// check_color가 2가 되면 return 되기 때문에 아래에서 2일리가 없다.
	if (check_color == 0) {
		cnt_white++;
	}
	else if(check_color == 1){
		cnt_blue++;
	}

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	divide_conquer(0, 0, N);
	cout << cnt_white << "\n" << cnt_blue;
	return 0;
}