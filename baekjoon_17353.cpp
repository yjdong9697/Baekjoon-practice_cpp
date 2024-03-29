#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
ll seg[400004];
ll lazy[400004];

void propagate(int node, int left, int right){
    if(lazy[node]){
        if(left != right){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node] * (right - left + 1);
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
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right); 
}

int main() {
    fastio;
    int n;
    cin >> n;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        update(1, 1, 100000, i, i, t - tmp);
        tmp = t;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            update(1, 1, 100000, b, c, 1);
            update(1, 1, 100000, c + 1, c + 1, - (c - b + 1));
        }
        else{
            cin >> b;
            cout << query(1, 1, 100000, 1, b) << "\n";
        }
    }
    return 0;    
}