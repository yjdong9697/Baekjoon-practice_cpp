#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, int (&dfs_visited)[1001], const int (&data_store)[1001][1001]){
    if (dfs_visited[start] != 0) return;
    else{
        dfs_visited[start] = 1;
        cout << start << " ";
        for(int i = 0; i < 1001; i++){
            if(data_store[start][i] != 0){
                if(dfs_visited[i] == 0){
                    dfs(i, dfs_visited, data_store); 
                }
            }
        }
    }


}

int main(void){
    int n, m, v;
    cin >> n >> m >> v;

    int dfs_visited[1001] = {0};

    int data_store[1001][1001] = {0};
    
    for(int i = 0; i < m; i++){
        int input_checker1, input_checker2;
        cin >> input_checker1 >> input_checker2;

        data_store[input_checker1][input_checker2] += 1;
        data_store[input_checker2][input_checker1] += 1;
    }

    // dfs

    dfs(v, dfs_visited, data_store);

    cout << "\n";

    // bfs

    queue <int> bfs;
    int bfs_visited[1001] = {0};
    bfs.push(v);
    vector<int> bfs_result_store;

    while(bfs.size() != 0){
        int checker = bfs.front();
        bfs.pop();
        bfs_result_store.push_back(checker);
        bfs_visited[checker] = 1;

        vector<int> temp_bfs;

        for(int i = 0; i < n + 1; i++){
            if(data_store[checker][i] != 0){
                if(bfs_visited[i] == 0){
                    temp_bfs.push_back(i);
                    bfs_visited[i] = 1;
                }
            }
        }

        if(temp_bfs.size() != 0){
            sort(temp_bfs.begin(), temp_bfs.end());

            for(int i = 0; i < temp_bfs.size(); i++){
                bfs.push(temp_bfs[i]);
            }
        }
    }

    for(int i = 0; i < bfs_result_store.size(); i++){
        cout << bfs_result_store[i] << " ";
    }

    cout << "\n";
}