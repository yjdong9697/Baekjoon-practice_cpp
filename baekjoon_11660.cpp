#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[1025][1025];

int dp_value(int x, int y){
    if(x < 1 || y < 1) return 0;
    else return dp[x][y];
}
int sum(int x, int y){
    return dp_value(x, y - 1) + dp_value(x - 1, y) - dp_value(x - 1,y - 1);
}

int main(void){
    fastio;
    memset(dp, sizeof(dp), 0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int v;
            cin >> v;
            dp[i][j] = sum(i, j) + v;   
        }
    }

    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp_value(x2, y2) - dp_value(x1 - 1, y2) - dp_value(x2, y1 - 1) + dp_value(x1 - 1, y1 - 1) << "\n";
    }
    return 0;
}