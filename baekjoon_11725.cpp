#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int visited[100001] = {0};
int parent_store[100001] = {0};

void make_tree(const vector<vector<int> > &data_store, int start){
    int length = data_store[start].size();
    visited[start] = 1;
    
    for(int i = 0; i < length; i++){
        if(visited[data_store[start][i]] != 1){
            parent_store[data_store[start][i]] = start;
            make_tree(data_store, data_store[start][i]);
        }
    }
    return;
}

int main(void){
    int n;
    cin >> n;

    vector<vector<int> > data_store(n + 1);
    for(int i = 0; i < n; i++){
        vector<int> temp;
        data_store[i] = temp;
    } // initialize

    for(int i = 0; i < n - 1; i++){
        int first, second;
        cin >> first >> second;
        data_store[first].push_back(second);
        data_store[second].push_back(first);
    } // node_store

    make_tree(data_store, 1);

    for(int i = 2; i < n + 1; i++){
        cout << parent_store[i] << "\n";
    }

    return 0;
}