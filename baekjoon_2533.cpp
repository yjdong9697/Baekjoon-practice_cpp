#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1000001

using namespace std;

int n;
vector<int> adj[MAX_N]; // 연결 리스트
vector<int> adj_below[MAX_N];
int visited[MAX_N]; // 방문확인
int dp[MAX_N][2];

void dp_return(int node){
    visited[node] = 1;
    for(int i = 0; i < adj[node].size(); i++){
        int to = adj[node][i];
        if(visited[to] == 1) continue;
        else{
            adj_below[node].push_back(to);
            dp_return(to);
            int min_cost_zero = 0;
            int min_cost_one = 0;
            for(int i = 0; i < adj_below[node].size(); i++){
                int to = adj_below[node][i];
                min_cost_zero += min(dp[to][0] + 1, dp[to][1]);
                min_cost_one += dp[to][0] + 1;
            }
            dp[node][0] = min_cost_zero;
            dp[node][1] = min_cost_one;
        
        }
    }
}


int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    dp_return(1);
    cout << min(dp[1][0] + 1, dp[1][1]) << "\n";
    return 0;
}