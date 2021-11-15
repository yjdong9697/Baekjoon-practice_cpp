#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[46][2]; // 0 : 해당 i에 1이 사용되지 않음, 1 : 사용 됨

int main(void){
    fastio;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        memset(dp, 0, sizeof(dp));
        int v;
        cin >> v;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int j = 1; j < v; j++){
            dp[j][0] = dp[j - 1][0] + dp[j - 1][1];
            dp[j][1] = dp[j - 1][0];
        }

        cout << "Scenario #" << i << ":\n";
        cout << dp[v - 1][0] + dp[v - 1][1] << "\n";
        cout << "\n";
    }
}