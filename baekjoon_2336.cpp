#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

class ptr{
    public:
    int x, y, z;
};

bool cmp(ptr &v1, ptr &v2){
    return v1.x < v2.x;
}

const int sz = 500010;
ptr arr[sz];
int tree[4 * sz];
const int INF = 2000000000;

int update(int node, int start, int end, int idx, int value){
    if(idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] = value;
    int mid = (start + end) >> 1;
    return tree[node] = min(
        update(node * 2, start, mid, idx, value),
        update(node * 2 + 1, mid + 1, end, idx, value)
    );
}

int query(int node, int start, int end, int left, int right){
    if(right < start || end < left) return INF;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return min(
        query(node * 2, start, mid, left, right),
        query(node * 2 + 1, mid + 1, end, left, right)
    );
}

int main() {
    fastio;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        arr[t].x = i;
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        arr[t].y = i;
    }

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        arr[t].z = i;
    }

    sort(arr + 1, arr + n + 1, cmp);
    fill(&tree[0], &tree[4 * sz], INF);
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(query(1, 1, n, 1, arr[i].y) > arr[i].z) ret++;
        update(1, 1, n, arr[i].y, arr[i].z);
    }

    cout << ret << "\n";
}