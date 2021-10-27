#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll dp[81];

int main(void){
    fastio;
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= 80; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << 4 * dp[n] + 2 * dp[n - 1] << "\n";
    return 0;
}