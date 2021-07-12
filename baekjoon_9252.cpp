#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[1000][1000];

int dp_return(int x, int y){
    if(x < 0 || y < 0) return 0;
    else return dp[x][y];
}

int lcs(int x, int y, int t){
    if(t == 0){
        if(x - 1 < 0 || y - 1 < 0) return 1;
        else return dp[x - 1][y - 1] + 1;
    }
    else{
        return max(dp_return(x - 1, y), dp_return(x, y - 1));
    }
}

int main(void){
    string v1, v2;
    cin >> v1 >> v2;

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            if(v1[i] == v2[j]){
                dp[i][j] = lcs(i, j, 0);
            }
            else{
                dp[i][j] = lcs(i, j, 1);                
            }
        }
    }

    cout << dp[v1.size() - 1][v2.size() - 1] << "\n";

    if(dp[v1.size() - 1][v2.size() - 1] == 0) return 0;

    int x = v1.size() - 1;
    int y = v2.size() - 1;

    string result = "";

    while(x >= 0 && y >= 0){
        if(v1[x] == v2[y]){
            result = v1[x] + result;
            x--;
            y--;
        }
        else{
            if(dp_return(x - 1, y) > dp_return(x, y - 1)){
                x--;
            }
            else y--;
        }
    }

    cout << result << "\n";
    return 0;
}