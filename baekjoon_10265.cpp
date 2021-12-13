#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int n, k;
int dp[1001][1001];
int visited[1001];
int finished[1001];
bool in_cycle[1001];
int r[1001];
int comp_cnt;

vector<pii> comp_store;

int dfs(int x){
    visited[x] = 1;
    int to = r[x];
    if(!visited[to]) dfs(to);
    else{
        if(finished[to] == -1){
            for(int i = to; i != x; i = r[i]){
                in_cycle[i] = true;
            }
            in_cycle[x] = true;
            return finished[x] = comp_cnt++;
        }
    }
    return finished[x] = finished[to];
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(finished, -1, sizeof(finished));
    memset(in_cycle, 0, sizeof(in_cycle));
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        r[i] = t;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    comp_store = vector<pii> (comp_cnt, make_pair(0, 0));

    for(int i = 1; i <= n; i++){
        if(in_cycle[i]){
            comp_store[finished[i]].first++;
            comp_store[finished[i]].second++;
        }
        else comp_store[finished[i]].second++;
    }

    if(comp_store[0].first <= k){
        dp[0][comp_store[0].first] = min(k, comp_store[0].second);
    }
    
    for(int i = 1; i < comp_store.size(); i++){
        for(int j = 0; j < comp_store[i].first; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = comp_store[i].first; j <= k; j++){
            dp[i][j] = min(k, max(dp[i - 1][j], dp[i - 1][j - comp_store[i].first] + comp_store[i].second));
        }
    }

    int result = -1;

    for(int i = 0; i <= k; i++){
        result = max(result, dp[comp_store.size() - 1][i]);
    }
    cout << result << "\n";
    return 0;
}