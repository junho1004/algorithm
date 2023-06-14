#include<iostream>
#include<stack>
using namespace std;

string str;
stack<char> op;

void input() {
	cin >> str;
}

// ���ĺ��� ������ ����ϰ�, �����ڴ� if���� ��ġ�� stack�� �ױ�� ����� �ݺ��Ѵ�.
// �켱������ �����ؾ��Ѵ�. �켱������ ���ϱ⳪ �����Ⱑ ���� ��ȣ�� ����.
// �����ڸ� ���ÿ� �ױ����� �̹� ���ÿ� �׿��ִ� �����ڸ� ����ϸ� ���� �������� �����ؾ���.

void solve() {
	for (int i = 0; i < str.size(); i++)
	{
		char tar = str[i];
		if ('A' <= tar && tar <= 'Z')
		{
			cout << tar;
		}
		else
		{
			if (tar == '(') {
				op.push(tar);
			}
			else if (tar == '*' || tar == '/')
			{
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(tar);
			}
			else if (tar == '+' || tar == '-')
			{
				// �켱������ ���ų� ������ ��� ����Ѵ�.
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(tar);
			}
			else if (tar == ')')
			{
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop(); // '('����
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();

	return 0;
}