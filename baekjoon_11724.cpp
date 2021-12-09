#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int visited[1001];
vector<vector<int> > v(1001);

void dfs(int x){
    visited[x] = 1;
    for(int i = 0; i < v[x].size(); i++){
        int to = v[x][i];
        if(!visited[to]) dfs(to);
    }
    return;
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int component_num = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            component_num++;
        }
    }

    cout << component_num << "\n";
    return 0;
}