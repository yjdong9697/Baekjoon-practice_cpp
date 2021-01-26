#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;

using namespace std;

int dp[1516];
int N;

int main(void){
    memset(dp, 0, sizeof(dp)); // 0 으로 초기화
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    cin >> N;
    if(N <= 3){
        cout << dp[N] << "\n";
        return 0;
    }

    int count = 4;

    while(count <= N){
        ll temp = 0;
        for(int i = 2; i <= count -2; i++){
            temp += 2 * dp[i];
            temp = temp % 1000000007;
        }
        dp[count] = temp + 1;
        count++;
    }

    cout << dp[N] << "\n";

    return 0;
}