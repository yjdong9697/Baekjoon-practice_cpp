#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int seg[400000];
int lazy[400000];

void propagate(int node, int start, int end){
    if(lazy[node] % 2 == 1){
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] = (end - start + 1) - seg[node];
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        lazy[node] += 1;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right);
    update(node * 2 + 1, mid + 1, end, left, right);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
\
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            update(1, 1, 100000, b, c);
        }
        else{
            cout << query(1, 1, 100000, b, c) << "\n";
        }
    }
    return 0;
}