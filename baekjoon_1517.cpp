#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<int> v;

int seg[2000000];
void update(int node, int start, int end, int index){
    if(index < start || end < index) return;
    if(start == end){
        seg[node] += 1;
        return;
    }
    seg[node] += 1;
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
}

int query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int compress_cor(int num){
    // 1부터 시작
    return (lower_bound(v.begin(), v.end(), num) - v.begin()) + 1;
}


int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    int n;
    cin >> n;
    vector<int> tmp;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        tmp.push_back(t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    ll ret = 0;

    for(int i = 0; i < n; i++){
        ret += query(1, 1, n, compress_cor(tmp[i]) + 1, n);
        update(1, 1, n, compress_cor(tmp[i]));
    }
    cout << ret << "\n";
    return 0;
}