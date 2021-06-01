#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[501][501];
int n;

int dp_return(int row, int index){
    if(index < 1 || index > n) return 0;
    else return dp[row][index];
}

int main(void){
    fastio;
    cin >> n;

    cin >> dp[1][1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int t;
            cin >> t;
            dp[i][j] = max(dp_return(i - 1, j - 1), dp_return(i - 1, j)) + t;
        }
    }

    int max_value = -1;

    for(int i = 1; i <= n; i++){
        max_value = max(max_value, dp[n][i]);
    }

    cout << max_value << "\n";
    return 0;
}