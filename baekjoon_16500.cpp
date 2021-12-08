#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int dp[101];
vector<string> v;
string s;
int n;

int memoi(int k){
    int& ret = dp[k];
    if(k == s.size()) return ret = 1;
    if(ret != -1) return ret;
    for(int i = 0; i < n; i++){
        if(k + v[i].size() > s.size()) continue;
        bool flag = true;
        for(int j = 0; j < v[i].size(); j++){
            if(s[k + j] != v[i][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            if(memoi(k + v[i].size())) return ret = 1;
        } 
    }
    return ret = 0;
}

int main(void){
    memset(dp, -1, sizeof(dp));
    cin >> s;
 
    cin >> n;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        v.push_back(t);
    }

    cout << memoi(0) << "\n";
    return 0;
}