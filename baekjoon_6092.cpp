#include <bits/stdc++.h>
#define fastio ios_base::sync_With_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int hanoi[13];
int dp[13];

int hanoi_cal(int n){
    if(n == 1) return 1;
    return hanoi[n] =  2 * hanoi_cal(n - 1) + 1;
}

int main(void){
    hanoi[0] = 0;
    hanoi[1] = 1;
    hanoi_cal(12);
    dp[0] = 0;
    dp[1] = 1;
    
    cout << dp[1] << "\n";

    for(int i = 2; i <= 12; i++){
        int min_value = 987654321;
        for(int j = 1; j <= i; j++){
            if(min_value > hanoi[j] + 2 * dp[i - j]){
                min_value = hanoi[j] + 2 * dp[i - j];
            }
        }
        dp[i] = min_value;
        cout << min_value << "\n";
    }
    return 0;
}