#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    double dp[10001];

    int n;
    cin >> n;

    double f;
    cin >> f;
    dp[0] = f;

    for(int i = 1; i < n; i++){
        double a;
        cin >> a;
        dp[i] = max(dp[i - 1] * a, a);
    }

    double result = -1;

    for(int i = 0; i < n; i++){
        result = max(result, dp[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << result << "\n";

    return 0;
}