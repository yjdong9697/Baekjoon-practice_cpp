#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
ll seg_num[900000];
ll seg_sum[900000];


void update_num(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;
    seg_num[node_index]++;
    if(node_left == node_right) return;
    int mid = (node_left + node_right) / 2;
    update_num(node_index * 2, node_left, mid, index);
    update_num(node_index * 2 + 1, mid + 1, node_right, index);
    return;
}

ll query_num(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg_num[node_index];
    else{
        int mid = (node_left + node_right) / 2;
        return query_num(node_index * 2, node_left, mid, query_left, query_right) + 
               query_num(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
    }
}

ll update_sum(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return seg_sum[node_index];
    else if(node_left == node_right) return seg_sum[node_index] += value;
    int mid = (node_left + node_right) / 2;
    return seg_sum[node_index] = update_sum(node_index * 2, node_left, mid, index, value) +
                                 update_sum(node_index * 2 + 1, mid + 1, node_right, index, value);
}

ll query_sum(int node_index, int node_left, int node_right, int query_left, int query_right){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg_sum[node_index];
    int mid = (node_left + node_right) / 2;
    
    return query_sum(node_index * 2, node_left, mid, query_left, query_right) +
           query_sum(node_index * 2 + 1, mid + 1, node_right, query_left, query_right);
}

int main(void){
    fastio;
    memset(seg_num, 0, sizeof(seg_num));
    memset(seg_sum, 0, sizeof(seg_sum));

    int N;
    cin >> N;

    ll total_cost = 1;
    
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        ll front = 0;
        ll back = 0;

        if(t != 0) front = (((query_num(1, 0, 200000, 0, t - 1) % 1000000007) * t) - query_sum(1, 0, 200000, 0, t - 1)) % 1000000007 ;
        if(t != 200000) back = (query_sum(1, 0, 200000, t + 1, 200000)- ((query_num(1, 0, 200000, t + 1, 200000) % 1000000007) * t)) % 1000000007;
        ll cost = (front + back) % 1000000007;
        if(i != 0) total_cost *= cost;
        total_cost %= 1000000007;
        update_sum(1, 0, 200000, t, t);
        update_num(1, 0, 200000, t);
    }

    cout << total_cost << "\n";
    return 0;
}