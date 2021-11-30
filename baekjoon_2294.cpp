#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[100][10001];
int n, k;
vector<int> coin;

int memoi(int x, int k){
    if(x == n) return (k == 0 ? 0 : 987654321);
    if(k < 0) return 987654321;
    int& ret = dp[x][k];
    if(ret != -1) return ret;
    int value = coin[x];
    return ret = min(memoi(x + 1, k), memoi(x, k - value) + 1);
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        coin.push_back(t);
    }
    sort(coin.begin(), coin.end());
    coin.erase(unique(coin.begin(), coin.end()), coin.end());

    int result = memoi(0, k);
    if(result == 987654321){
        cout << "-1\n";
    }
    else cout << result << "\n";
    return 0;
}