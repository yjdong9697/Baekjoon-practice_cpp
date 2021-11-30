#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
long long dp[91][2];

int main(void){
    fastio;
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    dp[0][0] = 1; // 첫번째 자리가 1인 경우
    dp[0][1] = 1; // 첫번째 자리가 0인 경우

    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }

    cout << dp[n - 1][0] << "\n";
    return 0;
}