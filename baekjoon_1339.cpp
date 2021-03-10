#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int n;
    cin >> n;
    vector<int> dp(26, 0);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            int current_value = s[i] - 'A';
            dp[current_value] += pow(10, s.size() - i - 1);
        }
    }
    sort(dp.begin(), dp.end(), greater<int>());
    int result = 0;
    int index = 9;
    for(int i = 0; i < 10; i++){
        result += dp[i] * index;
        if(index > 0) index--;
    }

    cout << result << "\n";
    return 0;
}