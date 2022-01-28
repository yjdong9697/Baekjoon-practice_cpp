#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int MAX = 18;
vector<int> adj[100001];
int parent[100001][18];
int depth[100001];
bool visited[100001];

void dfs(int cur, int cur_depth){
    visited[cur] = 1;
    depth[cur] = cur_depth;
    for(auto &p : adj[cur]){
        if(!visited[p]){
            parent[p][0] = cur;
            dfs(p, cur_depth + 1);
        }
    }
}

int main() {
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    for(int j = 1; j < MAX; j++){
        for(int i = 2; i <= n; i++){
            if(parent[i][j - 1] != -1){
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    // Query
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int j = 0; diff; j++){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }
        if(u != v){
            for(int j = MAX - 1; j >= 0; j--){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u << "\n";
    }
    return 0;
}