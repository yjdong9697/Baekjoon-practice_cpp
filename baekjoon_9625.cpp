#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

pair<int, int> dp[46];

int main(void){
    fastio;
    int k;
    cin >> k;

    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);

    for(int i = 2; i <= 45; i++){
        int first = dp[i - 1].first + dp[i - 2].first;
        int second = dp[i - 1].second + dp[i - 2].second;
        dp[i] = make_pair(first, second);
    }

    cout << dp[k].first << " " << dp[k].second << "\n";
    return 0;
}