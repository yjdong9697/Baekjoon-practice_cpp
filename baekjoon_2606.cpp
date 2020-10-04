#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void dfs(int start, int (&dfs_visited)[101], int(&data_store)[101][101]){
    if(dfs_visited[start] != 0){
        return;
    }
    else{
        dfs_visited[start] = 1;
        for(int i = 0; i < 101; i++){
            if(data_store[start][i] != 0){
                if(dfs_visited[i] == 0){
                    dfs(i, dfs_visited, data_store);
                }
            }

        }
    }
}

int main(void){
    int n;
    cin >> n;
    
    int node_num;
    cin >> node_num;

    int data_store[101][101] = {0};
    int dfs_visited[101] = {0};

    for(int i = 0; i < node_num; i++){
        int check1, check2;
        cin >> check1 >> check2;

        data_store[check1][check2] = 1;
        data_store[check2][check1] = 1;
    } // data_store;

    dfs(1, dfs_visited, data_store);

    int result_sum = 0;

    for(int i = 0; i < 101; i++){
        if(dfs_visited[i] != 0){
            result_sum += 1;
        }
    }

    cout << result_sum - 1 << "\n";

    return 0;
}