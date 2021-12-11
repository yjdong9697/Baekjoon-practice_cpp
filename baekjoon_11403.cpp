#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int r[100][100];
int result[100][100];
int visited[100];
int n;
vector<int> v;
int cur;
bool flag;

void dfs(int x){
    visited[x] = 1;
    v.push_back(x);
    for(int i = 0; i < n; i++){
        if(!visited[i] && r[x][i] == 1) dfs(i);
        if(r[x][i] == 1 && i == cur) flag = true;
    }

    return;
}

int main(void){
    fastio;
    memset(result, 0, sizeof(result));
    memset(visited, 0, sizeof(visited));

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> r[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        v.clear();
        memset(visited, 0, sizeof(visited));
        cur = i;
        flag = false;
        dfs(i);
        if(flag) result[i][i] = 1;
        for(int j = 1; j < v.size(); j++){
            result[i][v[j]] = 1;
        }       
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        } 
        cout << "\n";
    }
    
    return 0;
}