#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[32][32];

int main(void)
{
    fastio;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    for (int i = 2; i <= 30; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int r, c, w;
    cin >> r >> c >> w;
    long long count = 0;
    int index = 0;
    for (int i = r; i < r + w; i++)
    {
        for (int j = c; j <= c + index; j++)
        {
            count += dp[i][j];
        }
        index++;
    }

    cout << count << "\n";
    return 0;
}