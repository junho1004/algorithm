#include<iostream>
#include<stack>
using namespace std;

string str;
stack<char> op;

void input() {
	cin >> str;
}

// 알파벳은 무조건 출력하고, 연산자는 if절을 거치며 stack에 쌓기와 출력을 반복한다.
// 우선순위를 생각해야한다. 우선순위는 곱하기나 나누기가 높고 괄호가 높다.
// 연산자를 스택에 쌓기전에 이미 스택에 쌓여있는 연산자를 출력하며 뺄지 놔둘지를 결정해야함.

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
				// 우선순위가 같거나 높으면 모두 출력한다.
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
				op.pop(); // '('삭제
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