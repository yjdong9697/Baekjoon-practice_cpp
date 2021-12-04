#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[101][10];
int n;

int memoi(int x, int k){
    if(x == 0) return 0; // Base case
    if(k < 0 || k > 9) return 0;
    int& ret = dp[x][k];
    if(x == 1){
        if(k == 0) return ret = 0;
        else return ret = 1;
    }
    if(ret != -1) return ret;
    return ret = (memoi(x - 1, k - 1) + memoi(x - 1, k + 1)) % 1000000000;
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n;

    int result = 0;
    for(int i = 0; i < 10; i++){
        result = (memoi(n, i) + result) % 1000000000;
    }
    cout << result << "\n";
    return 0;
}