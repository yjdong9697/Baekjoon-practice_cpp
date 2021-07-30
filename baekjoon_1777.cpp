#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

// i 뒤에 존재하는 것 중, 1 ~ i - 1의 개수
// 즉, 가장 큰 수부터 작은 수 방향으로 진행
// 앞에 몇 개의 빈 자리가 있는지를 관리(구간합)
// 해당하는 자리에 계속 반복해서 넣음(Find by binary search)
// O(n(lgn)^2)이므로 시간 복잡도 측면에서도 충분

int seg[400000];
int N;

void update(int node_index, int node_left, int node_right, int index){
    if(index < node_left || node_right < index) return;
    
    if(node_left == node_right){
        seg[node_index] = 1;
        return;
    }
    else{
        int mid = (node_left + node_right) / 2;
        update(node_index * 2, node_left, mid, index);
        update(node_index * 2 + 1, mid + 1, node_right, index);
        seg[node_index] += 1;
        return;
    }
}

int query(int node_index, int node_left, int node_right, int query_left){
    int query_right = N;

    if(node_right < query_left || query_right < node_left) return 0;
    if(query_left <= node_left && node_right <= query_right) return seg[node_index];
    else{
        int mid = (node_left + node_right) / 2;
        return query(node_index * 2, node_left, mid, query_left) +
               query(node_index * 2 + 1, mid + 1, node_right, query_left);
    }
}

int main(void){
    fastio;
    memset(seg, 0, sizeof(seg));
    vector<int> d;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        d.push_back(t);
    }

    int position[N + 1];

    for(int i = N - 1; i >= 0; i--){
        int val = d[i];
        int start = 1;
        int end = N + 1;
        while(start < end){
            int mid = (start + end) / 2;
            if(N - mid - query(1, 1, N, mid) >= val){
                start = mid + 1;
            }
            else end = mid;
        }
        position[start - 1] = i + 1;
        update(1, 1, N, start - 1);
    }

    for(int i = 1; i <= N; i++){
        cout << position[i] << " ";
    }
    cout << "\n";
    return 0;
}