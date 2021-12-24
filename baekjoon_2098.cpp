#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[16][1 << 16];
int n;
int cost[16][16];
const int MAX = 987654321;

int dfs(int x, int visited){
    int &ret = dp[x][visited];
    if(ret != -1) return ret;

    if(visited == (1 << n) - 1){
        if(cost[x][0] == 0) return MAX;
        else return cost[x][0];
    }

    ret = MAX;
    for(int i = 0; i < n; i++){
        if((visited & (1 << i)) && (cost[x][i] == 0)) continue;
        ret = min(ret, dfs(i, (visited | (1 << i))) + cost[x][i]);
    }
    return ret;
}


int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }

    }
    cout << dfs(0, 1) << "\n";
    return 0;
}