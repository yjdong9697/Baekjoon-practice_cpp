#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, Q, U, V;

struct node_data{
    int left;
    int right;
    int max;
    int sum;
    node_data() : left(-123456789), right(-123456789), max(-123456789), sum(0)
    {}
    node_data(int temp1, int temp2, int temp3, int temp4) : left(temp1), right(temp2), max(temp3), sum(temp4)
    {}
};

node_data tree[400001];
int arr[100001];

node_data init(int start, int end, int node){
    if(start == end){
        return tree[node] = node_data(U * arr[start] + V , U * arr[start] + V, U * arr[start] + V, U * arr[start] + V);
    }
    else{
        int mid = (start + end) / 2;
        node_data front = init(start, mid, node * 2);
        node_data back = init(mid + 1, end, node * 2 + 1);
        return tree[node] = node_data(max(front.left, front.sum + back.left), max(front.right + back.sum, back.right), max(max(front.max, back.max), front.right + back.left), front.sum + back.sum);
    }
}

node_data max_query(int start, int end, int left, int right, int node){
    if(right < start || end < left) return node_data(-123456789, -123456789, -123456789, 0);
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    
    node_data front = max_query(start, mid, left, right, node * 2);
    node_data back = max_query(mid + 1, end, left, right, node * 2 + 1);
    return node_data(max(front.left, front.sum + back.left), max(front.right + back.sum, back.right), max(max(front.max, back.max), front.right + back.left), front.sum + back.sum);
}

node_data change(int start, int end, int index, int node){
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node] = node_data(U * arr[start] + V , U * arr[start] + V, U * arr[start] + V, U * arr[start] + V);
    int mid = (start + end) / 2;

    node_data front = change(start, mid, index, node * 2);
    node_data back = change(mid + 1, end, index, node * 2 + 1);
    return tree[node] = node_data(max(front.left, front.sum + back.left), max(front.right + back.sum, back.right), max(max(front.max, back.max), front.right + back.left), front.sum + back.sum);
}

int main(void){
    fastio;
    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));

    cin >> N >> Q >> U >> V;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    init(0, N - 1, 1);
    
    for(int i = 0; i < Q; i++){
        int check_num;
        cin >> check_num;
        if(check_num == 0){
            int query_start, query_end;
            cin >> query_start >> query_end;
            cout << max_query(0, N - 1, query_start - 1, query_end - 1, 1).max - V << "\n";
        }
        else{
            int change_index, change_num;
            cin >> change_index >> change_num;
            arr[change_index - 1] = change_num;
            change(0, N - 1, change_index - 1, 1);
        }
        
    }

    return 0;
}