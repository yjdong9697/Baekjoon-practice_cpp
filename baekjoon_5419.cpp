#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int seg[400000];
vector<int> y_compress;

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
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int find_y_cor(int val){
    // 시작 인덱스를 1로 잡음
    return (lower_bound(y_compress.begin(), y_compress.end(), val) - y_compress.begin()) + 1;
}

bool cmp(pii &v1, pii &v2){
    if(v1.first == v2.first){
        return v1.second > v2.second;
    }
    else return v1.first < v2.first;
}

int main() {
    fastio;
    int t;
    cin >> t;
    for(int test_num = 1; test_num <= t; ++test_num){
        memset(seg, 0, sizeof(seg));
        vector<pii> v;
        y_compress = {}; // clearing
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
            y_compress.push_back(b);
        }
        sort(v.begin(), v.end(), cmp);
        sort(y_compress.begin(), y_compress.end());
        y_compress.erase(unique(y_compress.begin(), y_compress.end()), y_compress.end());

        ll ret = 0;
        for(int i = 0; i < n; i++){
            int cur_y_compress = find_y_cor(v[i].second);
            ret += query(1, 1, n, cur_y_compress, n);
            update(1, 1, n, cur_y_compress);
        }
        cout << ret << "\n";
    }
    return 0;
}