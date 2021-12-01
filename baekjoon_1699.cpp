#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[100001];
int sqrt_val;

int memoi(int x, int k){
    if(x >= sqrt_val) return 987654321;
    if(k < 0) return 987654321;
    if(k == 0) return 0;
    int& ret = dp[k];
    if(ret != -1) return ret;
    return dp[k] = min(memoi(x, k - x * x) + 1, memoi(x + 1, k));
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    sqrt_val = sqrt(n) + 1;
    cout << memoi(1, n) << "\n";
    return 0;
}