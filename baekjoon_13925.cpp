#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
pii lazy[400000]; // value, type (type 0 : add, type 1 : multiplication)
ll seg[400000];
const ll MOD = 1000000007LL;
// 근본적으로 일반적인 세그트리로 안되는 이유가 뭘까
// 만약 lazy를 1개가 아니라 스택 형태로 주면?

void propagate(int node, int start, int end){
    if(lazy[node].first != 1 || lazy[node].second != 0){
        if(start != end){
            lazy[node * 2].first = (lazy[node * 2].first * lazy[node].first) % MOD;
            lazy[node * 2].second = (lazy[node].first * lazy[node * 2].second + lazy[node].second) % MOD;
            lazy[node * 2 + 1].first = (lazy[node * 2 + 1].first * lazy[node].first) % MOD;
            lazy[node * 2 + 1].second = (lazy[node].first * lazy[node * 2 + 1].second + lazy[node].second) % MOD;
        }
        seg[node] = ((seg[node] * lazy[node].first) % MOD + ((end - start + 1) * lazy[node].second) % MOD) % MOD;
        lazy[node] = {1, 0};
    }
}

void update(int node, int start, int end, int left, int right, ll value, ll type){
    propagate(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        // 단순 더하기
        if(type == 0){
            lazy[node] = {lazy[node].first, (lazy[node].second + value) % MOD};
            propagate(node, start, end);
            return;
        }
        else if(type == 1){
            lazy[node] = {(lazy[node].first * value) % MOD, (lazy[node].second * value) % MOD};
            propagate(node, start, end);
            return;
        }
        else{
            lazy[node] = {0, value};
            propagate(node, start, end);
            return;
        }
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, value, type);
    update(node * 2 + 1, mid + 1, end, left, right, value, type);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
    return;
}

ll query(int node, int start, int end, int left, int right){
    propagate(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return (seg[node]) % MOD;
    int mid = (start + end) >> 1;
    return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

int main() {
    fastio;
    memset(seg, 0, sizeof(seg));
    for(int i = 0; i < 400000; i++){
        lazy[i] = {1, 0};
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ll t;
        cin >> t;
        t %= MOD;
        update(1, 1, 100000, i, i, t, 2);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if(t == 1){
            ll a, b, c;
            cin >> a >> b >> c;
            c %= MOD;
            update(1, 1, 100000, a, b, c, 0);
        }
        else if(t == 2){
            ll a, b, c;
            cin >> a >> b >> c;
            c %= MOD;
            update(1, 1, 100000, a, b, c, 1);
        }
        else if(t == 3){
            ll a, b, c;
            cin >> a >> b >> c;
            c %= MOD;
            update(1, 1, 100000, a, b, c, 2);
        }
        else{
            ll a, b;
            cin >> a >> b;
            cout << query(1, 1, 100000, a, b) << "\n";
        }
    }
    return 0;
}