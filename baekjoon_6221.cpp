#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[21]; // i번째 블럭까지 고려하였을 때, i번째 블럭을 사용하는 경우의 수 (LIS 느낌)

int main(void){
    fastio;
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    vector<pair<int, int> > v;

    for(int i = 0; i < n; i++){
        int width, breadth;
        cin >> width >> breadth;
        v.push_back(make_pair(width, breadth));
    }
    sort(v.begin(), v.end(), greater<pair<int, int> > ());

    dp[0] = 1;

    for(int i = 1; i < n; i++){
        int max_value = 1;
        for(int j = 0; j < i; j++){
            if(v[i].second < v[j].second){
                max_value = max(max_value, dp[j] + 1);
            }
        }
        dp[i] = max_value;
    }

    int result = -1;

    for(int i = 0; i < n; i++){
        result = max(result, dp[i]);
    }

    cout << result << "\n";
    return 0;
}