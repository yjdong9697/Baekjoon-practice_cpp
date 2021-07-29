#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int seg_odd[400000];
int seg_even[400000];

int update_even(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return seg_even[node_index];
  
    if(node_left == node_right){
        if(value % 2 == 0) return seg_even[node_index] = 1;
        else return seg_even[node_index] = 0;
    }
    else{
        int mid = (node_left + node_right) / 2;
        return seg_even[node_index] = update_even(node_index * 2, node_left, mid, index, value) +
        update_even(node_index * 2 + 1, mid + 1, node_right, index, value);
    }
}

int update_odd(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return seg_odd[node_index];
  
    if(node_left == node_right){
        if(value % 2 == 1) return seg_odd[node_index] = 1;
        else return seg_odd[node_index] = 0;
    }
    else{
        int mid = (node_left + node_right) / 2;
        return seg_odd[node_index] = update_odd(node_index * 2, node_left, mid, index, value) +
        update_odd(node_index * 2 + 1, mid + 1, node_right, index, value);
    }
}

int query(int node_index, int node_left, int node_right, int query_left, int query_right, int check){
    if(query_right < node_left || node_right < query_left) return 0;
    if(query_left <= node_left && node_right <= query_right){
        if(check == 0) return seg_even[node_index];
        else return seg_odd[node_index];
    }
    
    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_left, query_right, check) +
            query(node_index * 2 + 1, mid + 1, node_right, query_left, query_right, check);
}

int main(void){
    fastio;
    memset(seg_odd, 0, sizeof(seg_odd));
    memset(seg_even, 0, sizeof(seg_even));

    int N, M;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int val;
        cin >> val;
        update_odd(1, 1, N, i, val);
        update_even(1, 1, N, i, val);
    }

    cin >> M;

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update_odd(1, 1, N, b, c);
            update_even(1, 1, N, b, c);
        }
        else if(a == 2){
            cout << query(1, 1, N, b, c, 0) << "\n";
        }
        else{
            cout << query(1, 1, N, b, c, 1) << "\n";
        }
    }

    return 0;
}