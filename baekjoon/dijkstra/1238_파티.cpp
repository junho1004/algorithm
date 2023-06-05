#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 1010
#define INF 1e9
using namespace std;

// ���ͽ�Ʈ���� ���� �⺻���� ����� ���� ó�� ���� ��� �ϳ����� �� �������� �ִ� �Ÿ��� ���Ѵ�. (�� �� ��)��� ����
// ��, 1�� ��忡�� �����ߴٸ� ���ͽ�Ʈ�� �迭�� ������ 1�� ��忡�� �� ������ �� �� �ִ� �ִ� �Ÿ��� �ǹ��� �� �̴�.
// 
// �� ������ �� ������ ������ �ֱ⿡ ���� �Ͱ� ���� ���� ����ġ�� �ٸ���.
// �� ��忡�� X��� ������ �ִ� �Ÿ�(�� �� ��)�� ���ؾ� �ϰ�, X��� ��忡�� �� �������� �ִܰŸ�(�� �� ��)�� ���ؾ��Ѵ�.
// �� ��忡�� X������ �ִ� �Ÿ��� ���Ϸ��� ���ͽ�Ʈ�� ��帶��(1000��) �������Ѵ�.�̴� ��ȿ�����̴� �ٸ� ����� �����ؾ��Ѵ�.
// 
// (�� �� ��)�� (�� �� ��) �� �ٲ㺸��.
// �׷����� �Է� ���� �� ������ �׷����� �Է� ������ �� ��忡�� X������ �ִ� �Ÿ��� ���ͽ�Ʈ�� �� �� ���� �� �� �ִ�. 
// 
// X��� ��忡�� �� �������� �ִܰŸ��� �⺻ ���ͽ�Ʈ��ó�� �� ���� ������ �ȴ�.

int N, M, X;
struct Node {
	int vertex;
	int cost;
};

vector<Node> v[MAX_N]; // ������
int dijk[MAX_N];

vector<Node> v_r[MAX_N]; // ������
int dijk_r[MAX_N];


void input()
{
	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v_r[b].push_back({ a,c });
	}

	fill(dijk, dijk + MAX_N, INF);
	fill(dijk_r, dijk_r + MAX_N, INF);

}

bool operator<(Node v, Node t) {
	if (v.cost == t.cost) return v.vertex > t.vertex;
	return v.cost > t.cost;
}


void go_dijk()
{
	dijk[X] = 0;
	priority_queue<Node> pq;
	pq.push({ X,0 });

	while (!pq.empty())
	{
		int now_vertex = pq.top().vertex;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v[now_vertex].size(); i++)
		{
			int next_vertex = v[now_vertex][i].vertex;
			int next_cost = v[now_vertex][i].cost;

			if (dijk[next_vertex] > now_cost + next_cost)
			{
				dijk[next_vertex] = now_cost + next_cost;
				pq.push({ next_vertex, now_cost + next_cost });
			}

		}
	}
}

void go_dijk_r()
{
	dijk_r[X] = 0;

	priority_queue<Node> pq;
	pq.push({ X,0 });

	while (!pq.empty())
	{
		int now_vertex = pq.top().vertex;
		int now_cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < v_r[now_vertex].size(); i++)
		{
			int next_vertex = v_r[now_vertex][i].vertex;
			int next_cost = v_r[now_vertex][i].cost;

			if (dijk_r[next_vertex] > now_cost + next_cost)
			{
				dijk_r[next_vertex] = now_cost + next_cost;
				pq.push({ next_vertex, now_cost + next_cost });
			}
		}
	}

}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();


	go_dijk(); 	// X���� �� ������ �ִܰŸ�
	go_dijk_r(); // �� ��忡�� X���� �ִܰŸ�(������ �׷����� �Ἥ �������� �Ȱ��� X�� ���δ�)

	int ans = -1;

	for (int i = 1; i <= N; i++) {
		ans = max(ans, dijk[i] + dijk_r[i]);
	}
	cout << ans;

	return 0;
}