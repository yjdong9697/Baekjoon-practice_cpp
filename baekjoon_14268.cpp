#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int idx = 1;
vector<int> adj[100001];
int dfs_in[100001];
int dfs_out[100001];
int seg[400004];
int lazy[400004];

void EulerTour(int node){
    dfs_in[node] = idx++;
    if(adj[node].empty()){
        dfs_out[node] = idx - 1;
        return;
    }
    for(int i = 0; i < adj[node].size(); i++){
        EulerTour(adj[node][i]);
    }
    dfs_out[node] = idx - 1;
}

void propagation(int node, int start, int end){
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
    propagation(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        lazy[node] += value;
        propagation(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right){
    propagation(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}


int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    memset(dfs_out, -1, sizeof(dfs_out));
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        int t;
        cin >> t;
        if(t == -1) continue;
        adj[t].push_back(i);
    }

    EulerTour(1);

    for(int i = 0; i < m ; i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            update(1, 1, 100001, dfs_in[b], dfs_out[b], c);
        }
        else{
            cin >> b;
            cout << query(1, 1, 100001, dfs_in[b], dfs_in[b]) << "\n";
        }
    }
    return 0;
}