#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1010

int N, M, X;
struct Node {
	int vertex;
	int cost;
};

vector<Node> v[MAX_N];
int dijk[MAX_N][MAX_N];


void input() {
	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
}

int main() {

	return 0;
}