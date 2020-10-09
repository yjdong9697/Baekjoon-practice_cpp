#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

bool dfs(int i, int j, int h, int w, int (&data_store)[51][51]){
    if(i < 0 || i >= h || j < 0 || j >= w){
        return false;
    }
    else{
        if(data_store[i][j] == 0) return false; // already visited
        else{
            data_store[i][j] = 0;
            dfs(i - 1, j, h, w, data_store);
            dfs(i + 1, j, h, w, data_store);
            dfs(i, j - 1, h, w, data_store);
            dfs(i, j + 1, h, w, data_store);
            dfs(i + 1, j + 1, h, w, data_store);
            dfs(i + 1, j - 1, h, w, data_store);
            dfs(i - 1, j + 1, h, w, data_store);
            dfs(i - 1, j - 1, h, w, data_store);
            return true;
        }
    }
    
}

int main(void){
    while(true){
        int w, h;
        cin >> w >> h;

        if(w == 0 && h == 0) break;
        else{
            int data_store[51][51] = {0};
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    int temp;
                    cin >> temp;
                    data_store[i][j] = temp;
                }
            }
            int group_check = 0;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(dfs(i, j, h, w, data_store)){
                        group_check += 1;
                    }
                }
            }
            cout << group_check << "\n";     
        }
    }

    return 0;
}