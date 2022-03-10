#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

ll seg[2000000];
ll lazy[2000000];

void init(int node, int start, int end, int index, ll value){
    if(index < start || end < index) return;
    seg[node] ^= value;
    if(start == end){
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid, index, value);
    init(node * 2 + 1, mid + 1, end, index, value);
}

void propagate(int node, int start, int end){
    if(lazy[node]){
        if(start != end){
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        seg[node] ^= lazy[node] * ((end - start + 1) % 2);
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, ll value){
    propagate(node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right){
        lazy[node] ^= value;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
    seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        init(1, 0, 500000, i, t);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update(1, 0, 500000, b, c, d);
        }
        else{
            cin >> b >> c;
            cout << query(1, 0, 500000, b, c) << "\n";
        }
    }
    return 0;
}