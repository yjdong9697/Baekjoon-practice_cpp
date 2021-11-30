#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[100001][3];
int value[100001][2];
int n;

int memoi(int x, int cur){
    if(x == n) return 0;
    int& ret = dp[x][cur];
    if(ret != -1) return ret;
    if(cur == 0) return ret = max(memoi(x + 1, 1) + value[x][0], memoi(x + 1, 2) + value[x][1]);
    else if(cur == 1) return ret = max(memoi(x + 1, 2) + value[x][1], memoi(x + 1, 0));
    else return ret = max(memoi(x + 1, 1) + value[x][0], memoi(x + 1, 0));
}

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        memset(value, 0, sizeof(value));
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> value[i][0];
        }

        for(int i = 0; i < n; i++){
            cin >> value[i][1];
        }
        cout << memoi(0, 0) << "\n";
    }
    return 0;
}