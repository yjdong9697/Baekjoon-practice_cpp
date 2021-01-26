#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1000001];

int recursion(int n){
    if(n == 1 || n == 2 || n == 3) return dp[n];
    if(dp[n - 1] == 0){
        recursion(n - 1);
    }
    if(n % 2 == 0 && dp[n / 2] == 0) recursion(n/2);
    if(n % 3 == 0 && dp[n / 3] == 0) recursion(n/2);
    if(n % 2 == 0 && n % 3 == 0){
        return dp[n] = min(min(dp[n - 1],dp[n / 2]), dp[n / 3]) + 1;
    }
    else if(n % 2 == 0){
        return dp[n] = min(dp[n - 1], dp[n / 2]) + 1;
    }
    else if(n % 3 == 0){
        return dp[n] = min(dp[n - 1], dp[n / 3]) + 1;
    }
    else{
        return dp[n] = dp[n - 1] + 1;
    }
}

int main(void){
    memset(dp, 0, sizeof(dp)); // 0으로 초기화
    int N;
    cin >> N;

    // Base case Setting
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    cout << recursion(N) << "\n";

    return 0;
}