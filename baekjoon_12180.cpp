#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    long long dp[26][26];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= 25; i++)
    {
        dp[1][i] = 1;
        dp[i][1] = 1;
    }

    for (int r = 2; r <= 25; r++)
    {
        for (int c = 2; c <= 25; c++)
        {
            dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
        }
    }

    for(int i = 1; i <= t; i++){
        int r, c;
        cin >> r >> c;
        cout << "Case #" << i << ": " << dp[r][c] << "\n";
    }

    return 0;
}