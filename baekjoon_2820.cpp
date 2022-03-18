#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int dfs_in[500001];
int dfs_out[500001];
vector<int> adj[500001];
ll seg[2000000];
ll lazy[2000000];
int idx = 1;
void dfs(int node){
    dfs_in[node] = idx++;
    for(auto &p : adj[node]){
        dfs(p);
    }
    dfs_out[node] = idx - 1;
}

void init(int node, int start, int end, int idx, int value){
    if(idx < start || end < idx) return;
    seg[node] += value;
    if(start == end) return;
    int mid = (start + end) >> 1;
    init(node * 2, start, mid, idx, value);
    init(node * 2 + 1, mid + 1, end, idx, value);
}

void propagate(int node, int start, int end){
    if(lazy[node]){
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node] * (end - start + 1);
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int value){
    propagate(node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right){
        lazy[node] += value;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int init_cost[500001];
    for(int i = 1; i <= n; i++){
        if(i == 1){
            int a;
            cin >> a;
            init_cost[i] = a;
        }
        else{
            int a, b;
            cin >> a >> b;
            init_cost[i] = a;
            adj[b].push_back(i);
        }
    }
    dfs(1);

    for(int i = 1; i <= n; i++){
        init(1, 1, 500000, dfs_in[i], init_cost[i]);
    }

    for(int i = 0; i < m; i++){
        char t;
        cin >> t;
        if(t == 'p'){
            int a, b;
            cin >> a >> b;
            update(1, 1, 500000, dfs_in[a], dfs_out[a], b);
            update(1, 1, 500000, dfs_in[a], dfs_in[a], -b);
        }
        else{
            int a;
            cin >> a;
            cout << query(1, 1, 500000, dfs_in[a], dfs_in[a]) << "\n";
        }
    }
    return 0;   
}