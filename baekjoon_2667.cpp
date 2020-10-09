#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

int data_store[25][25];

int dfs(int i, int j, int n){
    if(i < 0 || i >= n || j < 0 || j >= n){
        return 0;
    }
    if(data_store[i][j] == 0) return 0; // already visited
    else{
        data_store[i][j] = 0;
        int count = 1;
        count += dfs(i - 1, j, n);
        count += dfs(i + 1, j, n);
        count += dfs(i, j - 1, n);
        count += dfs(i, j + 1, n);
        return count;
    }
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &data_store[i][j]);
        }
    } // storing data

    int group_check = 0;
    vector <int> group_num_store;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int check_temp = dfs(i, j, n);
            if(check_temp != 0){
                group_check += 1;
                group_num_store.push_back(check_temp);
            }
        }
    }
    sort(group_num_store.begin(),group_num_store.end());
    
    cout << group_check << "\n";
    for(int i = 0; i < group_num_store.size(); i++){
        cout << group_num_store[i] << "\n";
    }

    return 0;
}