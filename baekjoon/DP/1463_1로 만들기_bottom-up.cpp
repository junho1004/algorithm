#include <iostream>
using namespace std;

int dp[1000000] = { 0 };

int main()
{
    int N;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
        {
            dp[i] = (dp[i / 3] + 1) > dp[i] ? dp[i] : (dp[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            dp[i] = (dp[i / 2] + 1) > dp[i] ? dp[i] : (dp[i / 2] + 1);
        }
    }
    cout << dp[N] << endl;
}