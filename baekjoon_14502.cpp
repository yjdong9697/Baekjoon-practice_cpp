#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int data_store[8][8];
int check_array[8][8];
vector <pair<int, int> > zero_store;
int n, m;
int max_result_store = -1;

void dfs(int i, int j, int (&visited)[8][8]){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return;
    }
    if(check_array[i][j] == 1) return;
    else{
        if(check_array[i][j] == 2){
            if(visited[i][j]) return;
            else{
                visited[i][j] = true;
                if(i + 1 < n){
                    if(check_array[i + 1][j] != 1){
                        check_array[i + 1][j] = 2;
                        dfs(i + 1, j, visited);
                    }         
                }
                if(i - 1 >= 0){
                    if(check_array[i - 1][j] != 1){
                        check_array[i - 1][j] = 2;
                        dfs(i - 1, j, visited);
                    }
                }
                if(j + 1 < m){
                    if(check_array[i][j + 1] != 1){
                        check_array[i][j + 1] = 2;
                        dfs(i, j + 1, visited);
                    }
                }
                if(j - 1 >= 0){
                    if(check_array[i][j - 1] != 1){
                        check_array[i][j - 1] = 2;
                        dfs(i, j - 1, visited);
                    }
                }
                return;
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    fill(&data_store[0][0], &data_store[7][8], -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            data_store[i][j] = temp;
            if(temp == 0){
                pair<int, int> zero_temp;
                zero_temp.first = i;
                zero_temp.second = j;
                zero_store.push_back(zero_temp);
            } // Store seperately if value is zero
        }
    } // data_store

    // Brute force (Search all condition)

    int zero_size = zero_store.size();

    for(int i = 0; i < zero_size; i++){
        for(int j = i + 1; j < zero_size; j++){
            for(int k = j + 1; k < zero_size; k++){
                copy(&data_store[0][0], &data_store[0][0] + 64, &check_array[0][0]); 
                check_array[zero_store[i].first][zero_store[i].second] = 1;
                check_array[zero_store[j].first][zero_store[j].second] = 1;
                check_array[zero_store[k].first][zero_store[k].second] = 1; // initializing array

                int visited[8][8] = {false};

                for(int i = 0; i < n; i++){  
                    for(int j = 0; j < m; j++){
                        dfs(i, j, visited);
                    }
                }
                
                // count 0 value and storing max value

                int current_value = count(&check_array[0][0], &check_array[0][0] + 64, 0);
                max_result_store = max(current_value, max_result_store);

            }
        }
    }

    cout << max_result_store << "\n";
    return 0;
}