#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<int> adj[100001];
// Euler tour : 1 base
int dfs_in[100001];
int dfs_out[100001];
int idx = 1;

int seg[400004];
pii lazy[400004]; // 언제꺼 정보인지

void dfs(int node){
    dfs_in[node] = idx++;
    for(auto &p : adj[node]){
        dfs(p);
    }
    dfs_out[node] = idx - 1;
}

void propagate(int node, int start, int end){
    if(lazy[node].second != -1){
        if(start != end){
            if(lazy[node * 2].first < lazy[node].first){
                lazy[node * 2].second = lazy[node].second;
                lazy[node * 2].first = lazy[node].first;
            }
            if(lazy[node * 2 + 1].first < lazy[node].first){
                lazy[node * 2 + 1].second = lazy[node].second;
                lazy[node * 2 + 1].first = lazy[node].first;
            }
        }
        seg[node] = lazy[node].second * (end - start + 1);
        lazy[node].second = -1;
    }
}

void update(int node, int start, int end, int left, int right, int value, int time){
    propagate(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        if(lazy[node].first < time){
            lazy[node].first = time;
            lazy[node].second = value;
        }
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value, time);
    update(node * 2 + 1, mid + 1, end, left, right, value, time);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;
    memset(lazy, -1, sizeof(lazy));
    memset(seg, 0, sizeof(seg));
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        if(i == 1) continue;
        else{
            adj[t].push_back(i);
        }
    }
    dfs(1);
    update(1, 1, 100000, 1, n, 1, 0);
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            update(1, 1, 100000, dfs_in[b] + 1, dfs_out[b], 1, i);

        }
        else if(a == 2){
            update(1, 1, 100000, dfs_in[b] + 1, dfs_out[b], 0, i);
        }
        else{
            cout << query(1, 1, 100000, dfs_in[b] + 1, dfs_out[b]) << "\n";
        }
    }
    return 0;
}