#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define NUMBER 100000
#define MAX 1000000001

using namespace std;

int num_store[NUMBER];

// min_value, 해당 index
pair<int, int> tree[NUMBER * 4];

pair<int, int> make_segment_tree(int start, int end, int node){
    if(start == end) return tree[node] = make_pair(num_store[start], start);
    else{
        int mid = (start + end) / 2;
        pair<int, int> left = make_segment_tree(start, mid, node * 2);
        pair<int, int> right = make_segment_tree(mid + 1, end, node * 2 + 1);

        // 왼쪽이 작은 경우
        if(left.first < right.first){
            return tree[node] = make_pair(left.first, left.second);

        }
        // 오른쪽이 작은 경우
        else if(left.first > right.first){
            return tree[node] = make_pair(right.first, right.second);

        }
        // 최솟값이 같은 경우
        else{
            return tree[node] = make_pair(left.first, min(left.second, right.second));
        }
    }
}

pair<int, int> change_segment_tree(int start, int end, int node, int index, int change_value){
    // 범위 밖에 있는 경우
    if(index < start || index > end) return tree[node];
    // 범위 안에 있는 경우
    else{
        // 정확히 해당 index
        if(start == end){
            return tree[node] = make_pair(change_value, index);
        }
        // 찢기 가능한 경우(더 찢어서 관련된 것이 있으면 반영함)
        else{
            int mid = (start + end) / 2;
            pair<int, int> left = change_segment_tree(start, mid, node * 2, index, change_value);
            pair<int, int> right = change_segment_tree(mid + 1, end, node * 2 + 1, index, change_value);
            
            if(left.first < right.first) return tree[node] = make_pair(left.first, left.second);
            else if(left.first > right.first) return tree[node] = make_pair(right.first, right.second);
            else return tree[node] = make_pair(right.first, min(left.second, right.second));
        }
    }
}

pair<int, int> partial_minimum(int start, int end, int node, int left, int right){
    // 범위가 아얘 안겹치는 경우
    if(right < start || left > end) return make_pair(MAX, 100001);

    // 완전히 겹치는 경우
    if(left <= start && end <= right){
        return tree[node];
    }

    // 일부만 겹치는 경우
    else{
        int mid = (start + end) / 2;
        pair<int, int> left_value = partial_minimum(start, mid, node * 2, left, right);
        pair<int, int> right_value = partial_minimum(mid + 1, end, node * 2 + 1, left, right);
        
        if(left_value.first < right_value.first){
            return make_pair(left_value.first, left_value.second);
        }
        else if(left_value.first == right_value.first){
            return make_pair(left_value.first, min(left_value.second, right_value.second));
        }
        else{
            return make_pair(right_value.first, right_value.second);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        num_store[i] = temp;
    }

    make_segment_tree(0, n - 1, 1);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int check_num;
        cin >> check_num;
        // 내용물 체인지
        if(check_num == 1){
            int index_value, change_num;
            cin >> index_value >> change_num;
            change_segment_tree(0, n - 1, 1, index_value -1 , change_num);
        }
        // 출력
        else if(check_num == 2){
            int index_start, index_end;
            cin >> index_start >> index_end;

            pair<int, int> result = partial_minimum(0, n - 1, 1, index_start - 1, index_end - 1);
            cout << result.second + 1 << "\n";
        }
        
        
    }
    return 0;
}
