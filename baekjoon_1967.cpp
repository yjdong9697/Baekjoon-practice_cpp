#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct node{
    vector<pair<int, int> > path_store;
};

//방문체크
int visited[10001] = {0};
//끝점체크
int end_point = 0;
//지름길이
int answer = 0;

void dfs(node *data_store, int start, int length){
    if(visited[start] != 0) return;
    else{
        visited[start] = 1;
        //거리보다 크다면 저장(아래에 노드가 없는 경우도 커버가능)
        if(answer < length){
            end_point = start;
            answer = length;
        }
        for(int i = 0; i < data_store[start].path_store.size(); i++){
            dfs(data_store, data_store[start].path_store[i].first, length + data_store[start].path_store[i].second);
        }
        return;
    }
}

int main(void){
    int n;
    cin >> n;

    node data_store[n + 1];

    for(int i = 0; i < n - 1; i++){
        int parent, child, length;
        cin >> parent >> child >> length;
        data_store[parent].path_store.push_back(make_pair(child, length));
        data_store[child].path_store.push_back(make_pair(parent, length));
    }// data_store

    // 끝점 찾기
    dfs(data_store, 1, 0);

    //방문기록 초기화
    fill_n(visited, 10001, 0);

    // 최종 거리 찾기
    dfs(data_store, end_point, 0);

    cout << answer << "\n";

    return 0;
}