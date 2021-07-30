#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int seg[2000000];

void update(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;

    seg[node_index]++;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update(node_index * 2, node_left, mid, index);
    update(node_index * 2 + 1, mid + 1, node_right, index);
    return;
}

int query(int node_index, int node_left, int node_right, int query_right){
    int query_left = 1;
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];

    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_right);    
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    vector<int> data_input;
    vector<int> sorted;
    data_input.push_back(-1); // 잉여 데이터(1 base)
    sorted.push_back(1000000001);
    map<int, int> index_set;
    
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        data_input.push_back(t);
        sorted.push_back(t);
        index_set.insert(make_pair(t, i));
    }

    sort(sorted.begin(), sorted.end(), greater<int>());
    vector<int> result(N + 1);

    for(int i = 1; i <= N; i++){
        int rank = index_set[sorted[i]];
        result[rank] = query(1, 1, N, rank - 1) + 1;
        update(1, 1, N, rank);
    }

    for(int i = 1; i <= N; i++){
        cout << result[i] << "\n";
    }

    return 0;
}