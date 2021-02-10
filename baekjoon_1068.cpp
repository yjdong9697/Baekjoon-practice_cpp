#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int arr[51][51];
int N;

int dfs(int start){
    bool check = true;
    int count = 0;
    for(int i = 0; i < N; i ++){
        if(arr[start][i] == 1){
            check = false;
            count += dfs(i);
        }
    }
    if(check == true) return 1;
    return count;
}

int main(void){
    fastio;
    memset(arr, 0, sizeof(arr));

    cin >> N;
    int start_node;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if(temp == -1){
            start_node = i;
            continue;
        }
        arr[temp][i] = 1;
    }

    int erase;
    cin >> erase;

    if(erase == start_node){
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < N; i++){
        arr[i][erase] = 0;
    }

    cout << dfs(start_node) << "\n";

    return 0;
}