#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, M, K;

int visited[1001];
int arr[1001][2];
int cycle[501];
int count_value = 0;
int cycle_num = 1;
vector<int>  cycle_store;

void dfs(int start_node, int status){
    if(cycle_store.size() == K) return; // Early Exit

    int next_node = arr[start_node][cycle[status]];

    if(status == M - 1){
        status = -1;
        // Already visited
        if(visited[next_node] != 0){
            if(next_node == 1) cycle_store.push_back(next_node); // 예외처리
            cycle_num = cycle_store.size() - visited[next_node] + 1;        
            return;
        }
        visited[next_node] = ++count_value; // 방문처리
        cycle_store.push_back(next_node);
    }

    dfs(next_node, status + 1);
    return;
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(arr, 0, sizeof(arr));
    memset(cycle, 0, sizeof(cycle));
    visited[1] = 1;

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < M; i++){
        char check;
        cin >> check;
        cycle[i] = (check == 'L') ? 0 : 1;
    } 

    dfs(1, 0);
    K -=  (cycle_store.size() - cycle_num);
    int print_check = K % cycle_num;
    if(print_check == 0){
        cout << cycle_store.back() << "\n";
    }
    else cout << cycle_store[print_check - 1 + cycle_store.size() - cycle_num] << "\n";

    return 0;
}