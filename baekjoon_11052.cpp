#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[1001];
int n;
int v[1001];

int main(void){
    fastio;
    memset(dp, 0, sizeof(dp));
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i - j]+ v[j], dp[i]);
        }
    }

    cout << dp[n] << "\n";
    return 0;  
}