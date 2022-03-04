#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int seg[70000 * 4];

void update(int node, int start, int end, int idx, int value){
    if(idx < start || end < idx) return;
    if(start == end){
        seg[node] += value;
        return;
    }
    seg[node] += value;
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
}

ll query(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}


int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(i < m) update(1, 0, 70000, v[i], 1);
    }

    ll ret = 0;

    for(int i = m; i <= n; i++){
        update(1, 0, 70000, v[i], 1);
        int start = -1;
        int end = 70000;
        while(start + 1 < end){
            int mid = (start + end) >> 1;
            if(query(1, 0, 70000, 0, mid) < (m + 1) / 2) start = mid;
            else end = mid;
        }
        ret += end;
        update(1, 0, 70000, v[i - m + 1], -1);
    }
    cout << ret << "\n";
    return 0;
}