#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
ll seg[2000000];
int idx[1000001];

void update(int node, int start, int end, int index){
    if(index < start || end < index) return;
    seg[node]++;
    if(start == end) return;
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
}

int query(int node, int start, int end, int left, int right = 500000){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    vector<int> s;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        s.push_back(t);
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        idx[t] = i;
    }

    ll ret = 0;

    for(int i = 0; i < n; i++){
        ret += query(1, 1, 500000, idx[s[i]]);
        update(1, 1, 500000, idx[s[i]]);
    }
    cout << ret << "\n";
    return 0;
}