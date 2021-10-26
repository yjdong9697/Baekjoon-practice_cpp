#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n, k;
long long dp[201][201];

int main(void){
    fastio;
    fill(&dp[0][0], &dp[200][201], 0);
    
    cin >> n >> k;
    dp[0][0] = 1;

    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            if (i == 1){
                dp[i][j] = 1;
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            long long result = 0;
            for(int p = 0; p <= j; p++){
                result += dp[i - 1][j - p];
            }
            dp[i][j] += result % 1000000000;
            
            
        }
    }

    cout << dp[k][n] << "\n";
    return 0;
}