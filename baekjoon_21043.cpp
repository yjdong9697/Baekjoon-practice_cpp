#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
vector<int> visited(50001, -1);
vector<int> edge[50001];

int dfs(int edge_val){
    if(visited[edge_val]) return 0;
    else{
        visited[edge_val] = 1; 
        int odd_num = 0;
        if(edge[edge_val].size() % 2 == 1) odd_num++;
        for(int i = 0; i < edge[edge_val].size(); i++){
            odd_num += dfs(edge[edge_val][i]);
        }
        return odd_num;
    }
}

int main(void){
    fastio;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int t1, t2;
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
        visited[t1] = 0;
        visited[t2] = 0;
    }

    int min_paint = 0;
    for(int i = 1; i <= 50000; i++){
        if(visited[i] == 0){
            min_paint += max(dfs(i) / 2, 1);
        }
        else continue;
    }

    cout << min_paint << "\n";
    return 0;
}