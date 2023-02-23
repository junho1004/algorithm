#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;
	int tar = 1 + pow(2, N);
	cout << tar * tar;
	return 0;
}