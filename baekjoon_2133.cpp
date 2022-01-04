#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n;
int dp[31];

int solution(int k){
    int& ret = dp[k];
    if(ret != -1) return ret;
    // Base case
    if(k == n) return ret = 1;
    else if(k > n) return ret = 0;

    int result = 0;
    result += solution(k + 2) * 3;

    for(int i = k + 4; i <= n; i += 2){
        result += solution(i) * 2;
    }

    return ret = result;
}

int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    if(n % 2 != 0){
        cout << 0 << "\n";
    }
    else{
        cout << solution(0) << "\n";
    }
    return 0;
}