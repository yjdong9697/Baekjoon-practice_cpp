#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    ll dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;

    for(int i = 8; i <= 100; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int t;
        cin >> t;
        cout << dp[t] << "\n";
    }

    return 0;
}