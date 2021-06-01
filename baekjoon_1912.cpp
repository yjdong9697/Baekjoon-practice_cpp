#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

//i번째까지 고려했을 떄의 max값
int dp[100001];

int main(void){
    fastio;
    int n;
    cin >> n;

    int v_1;
    cin >> v_1;
    dp[1] = v_1;

    for(int i = 2; i <= n; i++){
        int v;
        cin >> v;

        if(dp[i - 1] > 0){
            dp[i] = dp[i - 1] + v;
        }
        else{
            dp[i] = v;
        }
    }
    int max_value = -987654321;

    for(int i = 1; i <= n; i++){
        if(dp[i] > max_value){
            max_value = dp[i];
        }
    }

    cout << max_value << "\n";
    return 0;
}