#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node{
    vector<pair<int, int > > len_store;
};

int visited[100001] = {0};
int end_point;
int result;

void tree_checker(node *data_store, int start, int length){
    if(visited[start] != 0) return;
    visited[start] = 1;
    if(result < length){
        end_point = start;
        result = length;
    }
    for(int i = 0; i < data_store[start].len_store.size(); i++){
        tree_checker(data_store, data_store[start].len_store[i].first, length + data_store[start].len_store[i].second);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //간선의 갯수
    int n;
    cin >> n;

    node data_store[n + 1];
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        int node;
        while(true){
            cin >> node;
            if(node == -1) break;
            else{
                int length;
                cin >> length;
                data_store[num].len_store.push_back(make_pair(node,length));
                data_store[node].len_store.push_back(make_pair(num, length));
            }
        }
    }// data store

    // Find end_point
    tree_checker(data_store, 1, 0);
    
    // Reinitialize visited array
    fill(visited, visited + 100001, 0);

    // Find result
    tree_checker(data_store, end_point, 0);

    cout << result << "\n";
    return 0;
}