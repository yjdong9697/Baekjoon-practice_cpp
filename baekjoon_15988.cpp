#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;

using namespace std;
ll dp[1000001];

ll sum(int n){
    if(n == 1 || n == 2 || n == 3) return dp[n];
    if(dp[n - 1] == 0) sum(n - 1);
    return dp[n] = (dp[n - 1] + dp[n - 2] + dp[n - 3]) % 1000000009;
}

int main(void){
    memset(dp, 0, sizeof(dp));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        cout << sum(temp) << "\n";
    }

    return 0;
}