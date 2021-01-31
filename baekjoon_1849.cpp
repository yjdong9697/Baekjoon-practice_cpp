#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int tree[400004];
int data[100001];

int index_value;

int init(int start, int end, int node){
    if(start == end) return tree[node] = 1;
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void checker(int start, int end, int node, int check_num){
    if(tree[node] < check_num){
        return;
    }
    if(start == end){
        index_value = end;
        return;
    }
    int mid = (start + end) / 2;
    if(tree[node * 2] >= check_num ){
        checker(start, mid, node * 2, check_num);
    }
    else{
        checker(mid + 1, end, node * 2 + 1, check_num - tree[node * 2]);
    }
    return;
}

void update(int start, int end, int node, int index, int change_value){
    if(index < start || end < index) return; // 범위를 넘은 경우
    tree[node] += change_value;
    // 1칸짜리는 그냥 바로 리턴
    if(start != end){
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index, change_value);
        update(mid + 1, end, node * 2 + 1, index, change_value);
    }
    return;
}

int main(void){
    fastio;
    int n;
    cin >> n;

    init(0, n - 1, 1);

    int data_store[100001];
    memset(data_store, 0, sizeof(data_store));

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        checker(0, n - 1, 1, temp + 1);
        update(0, n - 1, 1, index_value, -1);
        data_store[index_value] = i + 1;
    }

    for(int i = 0; i < n; i++){
        cout << data_store[i] << " ";
    }
    cout << "\n";
    return 0;
}