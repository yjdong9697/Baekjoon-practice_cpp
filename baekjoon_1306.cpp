#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int seg[4000000];

int update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return seg[node_index];

    if(node_left == node_right) return seg[node_index] = value;
    else{
        int mid = (node_left + node_right) / 2;
        return seg[node_index] = max(update(node_index * 2, node_left, mid, index, value), update(node_index * 2 + 1, mid + 1, node_right, index, value));
    }
}

int query(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    else{
        int mid = (node_left + node_right) / 2;
        return max(query(node_index * 2, node_left, mid, query_left, query_right), query(node_index * 2 + 1, mid + 1 , node_right, query_left, query_right));
    }
}

// M : 쿼리 영역

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        update(1, 1, N, i, t);
    }

    for(int i = M; i <= N - M + 1; i++){
        cout << query(1, 1, N, i - (M - 1), i + (M - 1)) << " ";
    }
    cout << "\n";

    return 0;
}