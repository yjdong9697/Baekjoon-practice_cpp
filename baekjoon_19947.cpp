#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    long long dp[11];
    memset(dp, 0, sizeof(dp));

    int h, y;
    cin >> h >> y;

    dp[0] = h;
    dp[1] = h * 1.05;
    dp[2] = dp[1] * 1.05;
    dp[3] = max(h * 1.2, dp[2] * 1.05);
    dp[4] = max(dp[3] * 1.05, dp[1] * 1.2);

    for(int i = 5; i <= 10; i++){
        dp[i] = max(max(dp[i - 1] * 1.05, dp[i - 3] * 1.2), dp[i - 5] * 1.35);
    }

    cout << dp[y] << "\n";
    return 0;
}