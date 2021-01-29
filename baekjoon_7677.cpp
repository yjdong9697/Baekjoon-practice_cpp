#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
typedef long long ll;

using namespace std;

void fib_set(int n, vector<ll> &dp){
    if(n == 1) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        return;
    }

    if(n % 2 == 0){
        vector<ll> data(4, 0);
        fib_set(n / 2, data);
        dp[0] = (data[0] * data[0] + data[1] * data[2]) % 10000;
        dp[1] = (data[0]* data[1] + data[1] * data[3]) % 10000;
        dp[2] = (data[0] * data[2] + data[2] * data[3]) % 10000;
        dp[3] = (data[1] * data[2] + data[3] * data[3]) % 10000;
        return;
    }
    else{
        vector<ll> data(4, 0);
        fib_set(n / 2, data);
        dp[0] = (data[0] * data[0] + data[1] * (data[0] + data[2] + data[3])) % 10000;
        dp[1] = (data[0] * data[0] + data[1] * data[2]) % 10000;
        dp[2] = (data[3] * data[3] + data[2] * (data[0] + data[1] + data[3])) % 10000;
        dp[3] = (data[2] * (data[0] + data[3])) % 10000;
        return;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int temp;
        cin >> temp;
        if(temp == -1) return 0;
        // 예외처리
        if(temp == 0){
            cout << 0 << "\n";
            continue;
        }
        vector<ll> dp(4, 0);
        fib_set(temp, dp);
        cout << dp[1] << "\n";
    }
}