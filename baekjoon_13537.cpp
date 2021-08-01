#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> seg[400000];

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return;
    seg[node_index].push_back(value);
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index, value);
    update(node_index * 2 + 1, mid + 1, node_right, index, value);
    return;
}

int query(int node_index, int node_left, int node_right, int query_left, int query_right, int value){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right){
        return seg[node_index].end() - upper_bound(seg[node_index].begin(), seg[node_index].end(), value);
    }
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right, value) +
           query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right, value);
}

int main(void){
    fastio;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        update(1, 1, n, i, t);
    }

    // Sorting Merge sort tree
    for(int i = 0; i <= 400000; i++){
        sort(seg[i].begin(), seg[i].end());
    }

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cout << query(1, 1, n, a, b, c) << "\n";
    }
    return 0;
}