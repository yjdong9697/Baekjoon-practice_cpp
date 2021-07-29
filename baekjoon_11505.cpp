#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
ll seg[4000000];

ll update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return seg[node_index]; // Out of bound
    if(node_left == node_right){
        return seg[node_index] = (value % 1000000007);
    }
    else{
        int mid = (node_left + node_right) / 2;
        return seg[node_index] = (update(node_index * 2, node_left, mid, index, value) *
        update(node_index * 2 + 1, mid + 1, node_right, index, value)) % 1000000007;
    }
}

ll query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 1;
    else if(query_left <= node_left && node_right <= query_right) return seg[node_index];

    int mid = (node_left + node_right) / 2;
    return (query(node_index * 2, node_left, mid, query_left, query_right) *
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right)) % 1000000007;
}

int main(void){
    fastio;
    fill_n(seg, 4000000, 1);
    ll N, M, K;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        ll t;
        cin >> t;
        update(1, 1, N, i, t); 
    }

    for(int i = 0; i < M + K; i++){
        ll t, b, c;
        cin >> t >> b >> c;
        if(t == 1){
            update(1, 1, N, b, c);
        }
        else{
            cout << query(1, 1, N, b, c) << "\n";
        }
    }
    return 0;
}