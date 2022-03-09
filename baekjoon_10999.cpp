#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

ll seg[4000000];
ll lazy[4000000];

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
    propagate(node, start, end); // 일단 propagate
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        lazy[node] += value;
        propagate(node, start, end);
        return;
    }
    // 일부만 포함된 경우에는 다시 update를 진행해주어야 함(자식 중 일부가 갱신된 것이므로)
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
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        update(1, 1, 1000000, i, i, t);
    }

    for(int i = 0; i < m + k; i++){
        int a, b, c, d;
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update(1, 1, 1000000, b, c, d);
        }
        else{
            cin >> b >> c;
            cout << query(1, 1, 1000000, b, c) << "\n";
        }
    }
    return 0;
}