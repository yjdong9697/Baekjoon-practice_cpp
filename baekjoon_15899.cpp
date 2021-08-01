#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> edge[200001];
int visited[200001];
int dfs_in[200001];
int dfs_out[200001];
vector<int> seg[800004];

int EulerTour(int node, int count){
    visited[node] = 1;
    dfs_in[node] = count;
    for(int i = 0; i < edge[node].size(); i++){
        int check = edge[node][i];
        if(visited[check] == 0) count = EulerTour(edge[node][i], ++count);      
    }
    dfs_out[node] = count;
    return count;
}

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return;
    seg[node_index].push_back(value);
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index, value);
    update(node_index * 2 + 1, mid + 1, node_right, index, value);
}

int query(int node_index, int node_left, int node_right, int value, int cmp){
    int query_left = dfs_in[value];
    int query_right = dfs_out[value];
    
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right){
        int up_c_count = seg[node_index].end() - upper_bound(seg[node_index].begin(), seg[node_index].end(), cmp);
        return seg[node_index].size() - up_c_count;
    }
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, value, cmp) +
           query(node_index * 2 + 1, mid + 1, node_right, value, cmp);
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(dfs_in, 0, sizeof(dfs_in));
    memset(dfs_out, 0, sizeof(dfs_out));

    int n, m, c;
    cin >> n >> m >> c;

    vector<int> data(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> data[i];
    }

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    EulerTour(1, 1);

    for(int i = 1; i <= n; i++){
        update(1, 1, n, dfs_in[i], data[i]);
    }

    for(int i = 1; i < 800004; i++){
        sort(seg[i].begin(), seg[i].end());
    }

    int result = 0;

    for(int i = 0; i < m; i++){
        int v, c;
        cin >> v >> c;
        result += (query(1, 1, n, v, c));
        result %= 1000000007;
    }

    cout << result << "\n";
    return 0;
}