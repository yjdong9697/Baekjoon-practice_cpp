#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n;
int dp[1000001][2][2];

void memoi(int x){
    if(x == n) return;
    dp[x][0][0] = (dp[x - 1][0][1]) % 15746;
    dp[x][0][1] = (dp[x - 1][0][0] + dp[x - 1][1][0]) % 15746;
    dp[x][1][0] = (dp[x - 1][0][0] + dp[x - 1][1][0]) % 15746;
    memoi(x + 1);
}

int main(void){
    fastio;
    // 0이 처음 사용되고 1이 등장할 수 없음
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;
    memoi(1);
    cout << (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][1][0]) % 15746 << "\n";
    return 0;
}