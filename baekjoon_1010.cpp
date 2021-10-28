#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[30][30];

int dp_result(int x, int y){
    if(x < 0 || y < 0) return 0;
    else return dp[x][y];
}

int main(void){
    fastio;
    int t;
    cin >> t;
    dp[0][0] = 1;

    for(int i = 1; i < 30; i++){
        for(int j = 0; j < 30; j++){
            dp[i][j] = dp_result(i - 1, j) + dp_result(i - 1, j - 1);
        }
    }
    
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << dp[max(a, b)][min(a, b)] << "\n";
    }
    return 0;
}
