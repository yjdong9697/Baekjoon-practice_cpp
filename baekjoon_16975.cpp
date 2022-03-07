#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

ll seg[400000];

void init(int node, int start, int end, int index, ll value){
    if(index < start || end < index) return;
    if(start == end){
        seg[node] += value;
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid, index, value);
    init(node * 2 + 1, mid + 1, end, index, value);
}
void update(int node, int start, int end, int left, int right, ll value){
    if(right < start || end < left) return;
    if(left <= start && end <= right){
        seg[node] += value;
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);
}

ll query(int node, int start, int end, int index){
    if(index < start || end < index) return 0;
    if(start == end) return seg[node];
    int mid = (start + end) >> 1;
    return seg[node] + query(node * 2, start, mid, index) + query(node * 2 + 1, mid + 1, end, index);
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        init(1, 1, 100000, i, t);
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if(t == 1){
            ll a, b, c;
            cin >> a >> b >> c;
            update(1, 1, 100000, a, b, c);
        }
        else{
            ll a;
            cin >> a;
            cout << query(1, 1, 100000, a) << "\n";
        }
    }
    return 0;
}