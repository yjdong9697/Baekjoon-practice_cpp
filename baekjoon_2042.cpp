#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

ll arr[1000000];
ll tree[1000000 * 4];

ll init(ll start, ll end, ll node){
    if(start == end) return tree[node] = arr[start];
    else{
        ll mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }
}

ll sum(ll start, ll end, ll left, ll right, ll node){
    if(right < start || left > end) return 0; // 구하는 구갼을 넘은 경우
    if(left <= start && end <= right) return tree[node]; // 영역 안에 전부 속한 경우 해당 tree값 리턴
    else{
        ll mid = (start + end) / 2;
        return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
    }
}

void update(ll start, ll end, ll node, ll index, ll diff){
    if(index < start || end < index) return; // 영역 밖에 있는 경우;
    tree[node] += diff;
    // 1칸 짜리인 경우는 그냥 이대로 끝남
    if(start != end){
        ll mid = (start + end) / 2;
        update(start, mid, node * 2, index, diff);
        update(mid + 1, end, node * 2 + 1, index, diff);
    }
    return;
}

int main(void){
    fastio; // input/ output fasteer
    memset(arr, 0, sizeof(arr));
    memset(tree, 0, sizeof(tree));

    ll N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    } // Data set 저장

    init(0, N - 1, 1);

    for(int i = 0; i < M + K; i++){
        ll check_num;
        cin >> check_num;
        // 숫자 변경 타임
        if(check_num == 1ll){
            ll change_index, change_value;
            cin >> change_index >> change_value;
            change_index--;

            update(0, N - 1, 1, change_index, change_value - arr[change_index]);
            arr[change_index] = change_value;
        }
        // 부분합 구하기 타임
        else{
            ll start, end;
            cin >> start >> end;
            start--; end--;
            cout << sum(0, N - 1, start, end, 1) << "\n";
        }
    }
    return 0;
}