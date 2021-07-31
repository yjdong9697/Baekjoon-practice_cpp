#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int seg[800000];

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return;
    
    seg[node_index] += value;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index, value);
    update(node_index * 2 + 1, mid + 1, node_right, index, value); 
}

int query(int node_index, int node_left, int node_right, int query_right){
    int query_left = 1;
    if(node_right < query_left || query_right < node_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    
    int mid = (node_left + node_right) / 2 ;
    return query(node_index * 2, node_left, mid, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_right);
}

int main(void){
    fastio;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(seg, 0, sizeof(seg));
        map<int, int> index;
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            index.insert(make_pair(i, m + i));
            update(1, 1, n + m, m + i, 1);
        }

        for(int i = 0; i < m; i++){
            int t;
            cin >> t;
            int cur_index = index[t];
            int mov_index = m - i;
            cout << query(1, 1, n + m, cur_index) - 1 << " ";
            update(1, 1, n + m, cur_index, -1);
            update(1, 1, n + m, mov_index, 1);
            index[t] = mov_index;
        }
        cout << "\n";
    }
    return 0;
}