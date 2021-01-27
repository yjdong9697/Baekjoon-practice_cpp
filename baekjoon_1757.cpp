#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
typedef long long ll;

using namespace std;

int dp[10001][501][2];
int d[10001];

int N, M;

int dp_check(int i, int j, int k){
    if(i == 0) return dp[i][j][k];
    if(k == 1){
        if(j == 1){
            if(dp[i - 1][0][0] == -1){
                dp_check(i - 1, 0, 0);
            }
            return dp[i][j][k] = dp[i - 1][0][0] + d[i];
        }
        if(dp[i - 1][j - 1][1] == -1){
            dp_check(i - 1, j - 1, 1);
        }
        return dp[i][j][k] = dp[i - 1][j - 1][k] + d[i];
    }
    else{
        if(j == M - 1){
            if(dp[i - 1][M][1] == -1){
                dp_check(i - 1, M, 1);
            }
            if(j == 0){
                if(dp[i - 1][j][0] == -1){
                    dp_check(i - 1, j, 0);
                }
            }
            return dp[i][j][0] = max(dp[i - 1][M][1], dp[i - 1][j][0]);
        }
        if(dp[i - 1][j + 1][0] == -1){
            dp_check(i - 1, j + 1, 0);
        }
        if(dp[i - 1][j + 1][1] == -1){
            dp_check(i - 1, j + 1, 1);
        }
        if(j == 0){
            if(dp[i - 1][j][0] == -1){
                dp_check(i - 1, j, 0);
            }
            return dp[i][j][k] = max(max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]), dp[i - 1][j][k]);
        }
        return dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
    }
}

int main(void){
    memset(dp, -1, sizeof(dp));
    memset(d, -1, sizeof(d));

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        int temp;
        cin >> temp;
        d[i] = temp;
    }
    dp[1][1][1] = d[1];
    dp[1][0][0] = 0;

    cout << dp_check(N, 0, 0) << "\n";
    int n;

    return 0;
}