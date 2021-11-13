#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[100001];

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for(int i = 6; i <= 100000; i++){
        if(dp[i - 5] == -1 && dp[i - 2] == -1) continue;
        else if(dp[i - 5] == -1) dp[i] = dp[i - 2] + 1;
        else if(dp[i - 2] == -1) dp[i] == dp[i - 5] + 1;
        else dp[i] = min(dp[i - 5], dp[i - 2]) + 1;
    }

    int n;
    cin >> n;
    cout << dp[n] << "\n";
    return 0;
}