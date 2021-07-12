#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;
    vector<int> v;
    int dp[1000]; // dp[i] i'th index를 포함하였을 때의 length of LIS

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    for(int i = 0; i < n; i++){
        int max_value = 0;
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                max_value = max(max_value, dp[j]); 
            }
        }
        dp[i] = max_value + 1;
    }

    int last_index;
    int length = -1;
    for(int i = 0; i < n; i++){
        if(dp[i] > length){
            length = dp[i];
            last_index = i;
        }   
    }
    cout << length << "\n";

    vector<int> result;
    result.push_back(v[last_index]);
    length--;
    int cmp = last_index - 1;

    while(length > 0){
        if(v[cmp] < v[last_index] && dp[cmp] == length){
            result.push_back(v[cmp]);
            length--;
        }
        cmp--;
    }
    
    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}