#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
ll seg[4000000];

void update(int node_index, int node_left, int node_right, int index, ll value){
    if(index < node_left || node_right < index) return; // Out of Bound

    seg[node_index] += value;
    if(node_left == node_right) return;
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, index, value);
        update(node_index * 2 + 1, mid + 1, node_right, index, value);
        return;
    }
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    else if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    else{
        int mid = (node_left + node_right) / 2;
        return query(node_index * 2, node_left, mid, query_left, query_right) +
               query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
    }
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));

    int N, Q;
    cin >> N >> Q;

    for(int i = 0; i < Q; i++){
        int t;
        cin >> t;
        if(t == 1){
            ll p, x;
            cin >> p >> x;
            update(1, 1, N, p, x);
        }
        else{
            int p, q;
            cin >> p >> q;
            cout << query(1, 1, N, p, q) << "\n";
        }
    }
    return 0;
}