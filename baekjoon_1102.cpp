#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
const int MAX = 987654321;
// 무엇이 켜져있는지 판단하는 것이 가장 중요
int dp[1 << 16];
int n;
int p;
int cost[16][16];

int dp_cal(int visited){
    int& ret = dp[visited];
    if(ret != -1) return ret;
    int t = __builtin_popcount(visited);
    if(__builtin_popcount(visited) == p) return 0;

    ret = MAX;

    for(int i = 0; i < n; i++){
        if(!(visited & (1 << i))) continue;
        for(int j = 0; j < n; j++){
            if(visited & (1 << j)) continue;
            int to = visited | (1 << j);
            ret = min(ret, dp_cal(to) + cost[i][j]);
        }
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

    int vis = 0;
    
    for(int i = 0; i < n; i++){
        char t;
        cin >> t;
        if(t == 'Y') vis |= (1 << i);
    }

    cin >> p;

    // Exception handling
    if(__builtin_popcount(vis) >= p){
        cout << 0 << "\n";
        return 0;
    }
    else if(__builtin_popcount(vis) == 0){
        cout << -1 << "\n";
        return 0;
    }

    cout << dp_cal(vis) << "\n";
    return 0;
}