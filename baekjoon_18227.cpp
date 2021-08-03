#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int dfs_in[200001];
int dfs_out[200001];
int tree_depth[200001];
int visited[200001];
vector<int> edge[200001];
ll seg[800004];

int EulerTour(int index, int count, int depth){
    visited[index] = 1;
    dfs_in[index] = count;
    tree_depth[index] = depth;
    for(int i = 0; i < edge[index].size(); i++){
        int v = edge[index][i];
        if(visited[v] == 0) count = EulerTour(v, ++count, depth + 1);
    }
    dfs_out[index] = count;
    return count;
}

void update(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;
    seg[node_index] += 1;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index);
    update(node_index * 2 + 1, mid + 1, node_right, index);
    return;
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(seg, 0, sizeof(seg));
    memset(tree_depth, 0, sizeof(tree_depth));
    int n, c;
    cin >> n >> c;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    EulerTour(c, 1, 1);
    
    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            update(1, 1, n, dfs_in[b]);
        }
        else{
            cout << query(1, 1, n, dfs_in[b], dfs_out[b]) * tree_depth[b] << "\n";
        }
    }
    return 0;
}