#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int state[33][33];
int n;
long long dp[33][33][3];

int state_value(int x, int y){
    if(x < 1 || y < 1 || x > n || y > n) return 1;
    else return state[x][y];
}

long long solve(int x, int y, int index){
    if(x < 1 || y < 1 || x > n || y > n) return 0;
    
    if(dp[x][y][index] != -1) return dp[x][y][index];
    if(state_value(x, y)) return dp[x][y][index] = 0;

    //First check (대각)
    if(index == 0){
        if(state_value(x - 1, y) == 0 && state_value(x, y - 1) == 0){
            return dp[x][y][index] = solve(x - 1, y - 1, 0) + solve(x - 1, y - 1, 1) + solve(x - 1, y - 1, 2);
        }    
        else return dp[x][y][index] = 0; 
    }
    // Second check (vertical)
    else if(index == 1){
        return dp[x][y][index] = solve(x - 1, y, 0) + solve(x - 1, y, 1);
    }
    // Third check (horizontal)
    else{
        return dp[x][y][index] = solve(x, y - 1, 0) + solve(x, y - 1, 2);
    }
}

int main(void){
    fastio;
    fill(&dp[0][0][0], &dp[32][33][3], -1);
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> state[i][j];
        }
    }
    dp[1][1][0] = 0;
    dp[1][1][1] = 0;
    dp[1][1][2] = 0;
    dp[1][2][2] = 1;
    
    cout << solve(n, n, 0) + solve(n , n, 1) + solve(n, n, 2) << "\n";
    return 0;
}