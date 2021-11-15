#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[10000001][2]; // 0 : front non connected, 1: front connected

int main(void){
    fastio;
    dp[2][0] = 1;
    dp[2][1] = 1;
    int n;
    cin >> n;

    for(int i = 3; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 10;
        dp[i][1] = (dp[i - 1][0]) % 10;
    }

    cout << (dp[n][0] + dp[n][1]) % 10 << "\n";
    return 0;
}