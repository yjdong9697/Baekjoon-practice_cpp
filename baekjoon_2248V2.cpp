#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll dp[32][32]; // dp[i][j] = i번째 자리까지 고려할 때 총 소모된 1의 개수가 j인 개수

int main(void){
    memset(dp, 0, sizeof(dp));

    ll n, l, i;
    cin >> n >> l >> i;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    while(n > 0){
        ll check = 0;
        for(int i = 0; i <= l; i++){
            check += dp[n - 1][i];
        }
        if(check >= i) cout << 0;
        else{
            i -= check;
            l--;
            cout << 1;
        }
        n--;
    }
    cout << "\n";

    return 0;
}