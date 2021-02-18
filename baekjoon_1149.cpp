#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int dp[1001][3];

int main(void){
    fastio;
    memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

    for(int i = 1; i < n; i++){
        int r_cost, g_cost, b_cost;
        cin >> r_cost >> g_cost >> b_cost;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r_cost;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g_cost;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b_cost;
    }

    cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << "\n";

    return 0;
}