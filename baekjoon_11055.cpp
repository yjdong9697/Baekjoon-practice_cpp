#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
vector<int> v;
int n;
int dp[1001];

int memoi(int k){
    int& ret = dp[k];
    if(ret != -1) return ret;
    int cmp = v[k];
    for(int i = k + 1; i < n; i++){
        if(v[k] < v[i]){
            cmp = max(cmp, memoi(i) + v[k]);
        }
    }
    return ret = cmp;
}


int main(void){
    fastio;
    memset(dp, -1, sizeof(dp));
    
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    int result = -1;
    for(int i = 0; i < n; i++){
        result = max(result, memoi(i));
    }

    cout << result << "\n";
    return 0;
}