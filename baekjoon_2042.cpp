#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define NUMBER 1000000

using namespace std;

long long num_store[NUMBER];
long long tree[NUMBER * 4];

long long make_segment_tree(int start, int end, int node){
    if (start == end) return tree[node] = num_store[start];
    else{
        int mid = (start + end) / 2;
        return tree[node] = make_segment_tree(start, mid, node * 2) + make_segment_tree(mid + 1, end, node * 2 + 1);
    }
}

void change_segment_tree(int start, int end, int node, int index, int change_value){
    /*
    start : 시작 인덱스
    end : 끝나는 인덱스
    node : 해당 노드 주소값
    index : 바꾸는 index
    change_value : 바뀌는 값
    */

   // Index가 범위 밖에 존재하는 경우
   if(start > index || end < index) return;
   // 범위 내에 존재하는 경우
   else{
       tree[node] += change_value;
       // 더이상 하부로 내려갈 수 없는 경우
       if(start == end) return;
       // 내려갈 수 있는 경우
       else{
           int mid = (start + end) / 2;
           change_segment_tree(start, mid, node * 2, index, change_value);
           change_segment_tree(mid + 1, end, node * 2 + 1, index, change_value);
           return;
       }
   }
}

long long partial_sum(int start, int end, int node, int left, int right){
    /*
    start : 시작 인덱스
    end : 끝나는 인덱스
    node : 해당 노드 주소값
    left : 더하고자하는 시작 인덱스
    right : 더하고자하는 끝 인덱스
    
    정확하게 범위가 구하고자 아는 index사이에 들어왔을때만 return하여 더함
    */
    
    // 범위 내에 겹치는 것이 없는 경우
    if(end < left || right < start) return 0;
    // 구하고자 하는 범위내에 모두 들어오는 경우
    if(left <= start && right >= end){
        return tree[node];
    }
    //일부만 들어오는 경우
    else{
        int mid = (start + end) / 2;
        return partial_sum(start, mid, node * 2, left, right) + partial_sum(mid + 1, end, node * 2 + 1, left, right);
    }


}

int main(void){
    // N : 수의 갯수, M : 수의 변경이 일어나는 횟수, K : 구간의 합을 구하는 횟수
    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        num_store[i] = temp;
    }
    
    make_segment_tree(0, N - 1, 1);

    for(int i = 0; i < M + K; i++){
        long long check_num;
        cin >> check_num;
        // 교체하는 경우
        if(check_num == 1){
            int change_index, change_num, difference;
            cin >> change_index >> change_num;
            change_index -= 1;
            difference = change_num - num_store[change_index];
            num_store[change_index] = change_num;

            change_segment_tree(0, N - 1, 1, change_index, difference);
        }
        // 부분합 출력하는 경우
        else{
            int start_index, end_index;
            cin >> start_index >> end_index;

            cout << partial_sum(0, N - 1, 1, start_index - 1, end_index - 1) << "\n";

        }
    }

    return 0;
}