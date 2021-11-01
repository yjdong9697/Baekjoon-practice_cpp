#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[1001];
int n;

int dp_value(int x)
{
    if (x < 1)
        return 987654321;
    if (dp[x] != -1)
        return dp[x];
    else
    {
        return dp[x] = min(dp_value(x - 1), dp_value(x - 3)) + 1;
    }
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[3] = 1;
    cin >> n;

    int check = dp_value(n);
    if (check % 2 == 1)
    {
        cout << "CY\n";
    }
    else
    {
        cout << "SK\n";
    }
    return 0;
}