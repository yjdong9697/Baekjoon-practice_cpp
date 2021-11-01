#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int value[7][7];
int dp[7][7];
int n;

int dp_value(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return 0;
    else return dp[x][y];
}

int main(void){
    fastio;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            string a;
            cin >> a;
            if(a[0] == 'A'){
                value[i][j] = 1;
            }
            else if(a[0] == 'T'){
                value[i][j] = 10;
            }
            else if(a[0] == 'J'){
                value[i][j] = 11;
            }
            else if(a[0] == 'Q'){
                value[i][j] = 12;
            }
            else if(a[0] == 'K'){
                value[i][j] = 13;
            }
            else{
                value[i][j] = a[0] - '0';
            }
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            dp[i][j] = max(dp_value(i + 1, j), dp_value(i, j - 1)) + value[i][j];
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}