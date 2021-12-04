#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[1001][1001];

int memoi(int n, int k){
    int& ret = dp[n][k];
    if(ret != -1) return ret;
    if(n == 0 || k == 0 || n == k) return ret = 1; // Base case
    return ret = (memoi(n - 1, k) + memoi(n - 1, k - 1)) % 10007;
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    cout << memoi(n, k) << "\n";
    return 0;
}