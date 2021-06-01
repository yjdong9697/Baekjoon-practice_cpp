#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[1001][3];

int main(void){
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 1;

    int n;
    cin >> n;

    for(int i = 3; i <= 1000; i++){
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 10007;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) % 10007;
        dp[i][3] = (dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) % 10007;
    }

    int result = (dp[n][1] + dp[n][2] + dp[n][3]) % 10007;
    cout << result << "\n";

    return 0;
}