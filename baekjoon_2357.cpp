#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define Number 100000
#define MAX 1000000001
#define MIN 0

using namespace std;

pair<int, int> tree[Number * 4];
int num_store[Number];

pair<int, int> make_segment_tree(int start, int end, int node){
    // 부분적으로 최대/최소를 저장
    if(start == end) return tree[node] = make_pair(num_store[start], num_store[start]);
    else{
        int mid = (start + end) / 2;
        pair<int, int> left = make_segment_tree(start, mid, node * 2);
        pair<int, int> right = make_segment_tree(mid + 1, end, node * 2 + 1);
        return tree[node] = make_pair(max(left.first, right.first), min(left.second, right.second));
    }
}

pair<int, int> partial_check_value(int start, int end, int node, int left, int right){
    // 범위 내에 겹치는 것이 없는 경우
    if(end < left || right < start) return make_pair(MIN, MAX);
    // 완전히 겹치는 경우
    if(left <= start && end <= right){
        return tree[node];
    }
    // 일부만 겹치는 경우
    else{
        int mid = (start + end) / 2;
        pair<int, int> left_num = partial_check_value(start, mid, node * 2, left, right);
        pair<int, int> right_num = partial_check_value(mid + 1, end, node * 2 + 1, left, right);
        return make_pair(max(left_num.first, right_num.first), min(left_num.second, right_num.second));        
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        num_store[i] = temp;
    } // Num store

    make_segment_tree(0, n - 1, 1);

    for(int i = 0; i < m; i++){
        int index_start, index_end;
        cin >> index_start >> index_end;
        index_start -= 1;
        index_end -= 1;

        pair<int, int> output = partial_check_value(0, n - 1, 1, index_start, index_end);
        cout << output.second << " " << output.first << "\n";
    }

    return 0;
}