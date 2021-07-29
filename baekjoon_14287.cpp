#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> edge[100001];
int seg[400004];
int dfs_in[100001];
int dfs_out[100001];

int EulerTour(int node, int count){
    dfs_in[node] = count;
    if(edge[node].size() == 0){
        dfs_out[node] = count;
        return count; // 자식이 없는 경우
    }
    
    for(int i = 0; i < edge[node].size(); i++){
        count = EulerTour(edge[node][i], ++count);
    }
    dfs_out[node] = count;
    return count;
}

void update(int node_index, int node_left, int node_right, int update_index, int value){
    if(update_index < node_left || update_index > node_right) return;

    seg[node_index] += value;
    if(node_left == node_right) return;
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, update_index, value);
        update(node_index * 2 + 1, mid + 1, node_right, update_index, value);
        return;
    }
}

int query(int node_index, int node_left, int node_right, int update_index){
    int dfs_in_index = dfs_in[update_index];
    int dfs_out_index = dfs_out[update_index];
    
    if(dfs_out_index < node_left || dfs_in_index > node_right) return 0; // Out of bound
    else if(dfs_in_index <= node_left && node_right <= dfs_out_index) return seg[node_index];
    else{
        int mid = (node_left + node_right) / 2;
        return query(node_index * 2, node_left, mid, update_index) +
               query(node_index * 2 + 1, mid + 1, node_right, update_index);
    }
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(dfs_in, 0, sizeof(dfs_in));
    memset(dfs_out, 0, sizeof(dfs_out));

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int e;
        cin >> e;
        if(e == -1) continue;
        else{
            edge[e].push_back(i);
        }
    }

    EulerTour(1, 1);

    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        // update
        if(t == 1){
            int index, value;
            cin >> index >> value;
            update(1, 1, n, dfs_in[index], value);
        }
        else{
            int index;
            cin >> index;
            cout << query(1, 1, n, index) << "\n";
        }
    }
    return 0;
}