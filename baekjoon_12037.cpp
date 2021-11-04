#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

long long dp[16][2]; // regard of x + 0 : consonant, 1 : vowel
int c, v, l;

int main(void){
    //자음 뒤 무조건 모음
    int t;
    cin >> t;
    int count = 1;
    while(count <= t){
        memset(dp, 0, sizeof(dp));
        cin >> c >> v >> l;
        dp[1][0] = c;
        dp[1][1] = v;
        for(int i = 1; i < l; i++){
            dp[i + 1][1] = ((dp[i][0] + dp[i][1]) * v) % 1000000007;
            dp[i + 1][0] = (dp[i][1] * c) % 1000000007;
        }
        cout << "Case " << "#" << count << ": " << dp[l][1]  << "\n";
        count++;
        
    }
    return 0;
}