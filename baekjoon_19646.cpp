#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int seg[800000];
int data_value[200001];

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || index > node_right) return; // Out of bound

    if(node_left == node_right){
        seg[node_index] += value;
        return;
    }
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, index, value);
        update(node_index * 2 + 1, mid + 1, node_right, index, value);
        seg[node_index] += value;
        return;
    }
}

int query(int node_index, int node_left, int node_right, int end_index){
    int start_index = 1;
    if(end_index < node_left || node_right < start_index) return 0;
    else if(start_index <= node_left && node_right <= end_index) return seg[node_index]; // 전부 다 포함

    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, end_index) +
           query(node_index * 2 + 1, mid + 1, node_right, end_index);
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    memset(data_value, 0, sizeof(data_value));

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        update(1, 1, N, i, t);
        data_value[i] = t;
    }

    for(int i = 0; i < N; i++){
        int cmp;
        cin >> cmp;

        int start = 1;
        int end = N + 1;
        while(start < end){
            int mid = (start + end) / 2;
            if(query(1, 1, N, mid) >= cmp){
                end = mid;
            }
            else start = mid + 1;
        }
        
        cout << start << " ";
        update(1, 1, N, start, -data_value[start]);
    }
    cout << "\n";
    return 0;
}