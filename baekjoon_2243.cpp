#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int seg[5000000];

void update(int node_index, int node_left, int node_right, int index, int value){
    if(index < node_left || node_right < index) return; // OUt of bound
    seg[node_index] += value;

    if(node_left == node_right) return; // Base case
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, index, value);
        update(node_index * 2 + 1, mid + 1, node_right, index, value);
    }
}

int query(int node_index, int node_left, int node_right, int query_right){
    int query_left = 1;
    if(node_right < query_left || query_right < node_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];

    int mid = (node_left + node_right) / 2;
    return query(node_index * 2, node_left, mid, query_right) +
           query(node_index * 2 + 1, mid + 1, node_right, query_right);
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        // 사탕 꺼내기
        if(t == 1){
            int cmp;
            cin >> cmp;

            int start = 1;
            int end = 1000001;
            while(start < end){
                int mid = (start + end) / 2;
                if(query(1, 1, 1000000, mid) < cmp) start = mid + 1;
                else end = mid;
            }
            cout << start << "\n";
            update(1, 1, 1000000, start, -1);
        }
        else{
            int b, c;
            cin >> b >> c;
            update(1, 1, 1000000, b, c);
        }
    }
    return 0;
}