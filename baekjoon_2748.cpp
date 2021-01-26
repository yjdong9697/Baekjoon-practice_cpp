#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

ll dp[91];
int N;

ll fib(int n){
    if(n == 0 || n == 1) return dp[n];
    if(dp[n - 1] == 0){
        fib(n - 1);
    }
    return dp[n] = dp[n - 1] + dp[n - 2];
}

int main(void){
    memset(dp, 0, sizeof(dp)); // Initial setting
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cout << fib(N) << "\n";

    return 0;
}