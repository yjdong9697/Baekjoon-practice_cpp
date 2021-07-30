#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
ll seg_odd[1200000];
ll seg_even[1200000];

ll update(int node_index, int node_left, int node_right, int index, ll value){
    if(index < node_left || node_right < index){
        if(index % 2 == 0) return seg_even[node_index];
        else return seg_odd[node_index];
    }
    if(node_left == node_right){
        if(index % 2 == 0) return seg_even[node_index] += value;
        else return seg_odd[node_index] += value;
    }
    int mid = (node_left + node_right) / 2;
    ll return_value = update(node_index * 2, node_left, mid, index, value) +
                       update(node_index * 2 + 1, mid + 1, node_right, index, value);
    if(index % 2 == 0) return seg_even[node_index] = return_value;
    else return seg_odd[node_index] = return_value;
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right, int val){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right){
        if(val == 0) return seg_even[node_index];
        else return seg_odd[node_index];
    }
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right, val) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right, val);
}

int main(void){
    fastio;
    memset(seg_odd, 0, sizeof(seg_odd));
    memset(seg_even, 0, sizeof(seg_even));

    int N, Q;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        ll t;
        cin >> t;
        update(1, 1, N, i, t);
    }

    for(int i = 0; i < Q; i++){
        int t, b, c;
        cin >> t >> b >> c;
        if(t == 1){
            ll val1 = query(1, 1, N, b, c, 0);
            ll val2 = query(1, 1, N, b, c, 1);
            cout << max(val1, val2) - min(val1, val2) << "\n";
        }
        else update(1, 1, N, b, c);
    }
    return 0;
}