#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int n, m;
int r[1000][1000];
int visited[1000][1000];
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int result[1000][1000];
vector<int> comp_store;
vector<pii> wall_store;
int comp_val;

int dfs(int x, int y){
    visited[x][y] = comp_val;
    int comp_count = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        if(visited[dx][dy] == -1 && r[dx][dy] == 0){
            comp_count += dfs(dx, dy);
        }
    }
    return comp_count + 1;
}

int main(void){
    fastio;
    memset(result, 0, sizeof(result));
    memset(visited, -1, sizeof(visited));
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char t;
            cin >> t;
            r[i][j] = t - '0';
            if(r[i][j] == 1){
                wall_store.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == -1 && r[i][j] == 0){
                comp_store.push_back(dfs(i, j));
                comp_val++;
            }
        }
    }

    for(int i = 0; i < wall_store.size(); i++){
        int x = wall_store[i].first;
        int y = wall_store[i].second;
        vector<int> comp_merge;
        int comp_merge_num = 0;
        for(int j = 0; j < 4; j++){
            int dx = x + move_x[j];
            int dy = y + move_y[j];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(r[dx][dy] == 0){
                comp_merge.push_back(visited[dx][dy]);
            }
        }
        sort(comp_merge.begin(), comp_merge.end());
        comp_merge.erase(unique(comp_merge.begin(), comp_merge.end()), comp_merge.end());

        for(int j = 0; j < comp_merge.size(); j++){
            comp_merge_num += comp_store[comp_merge[j]];
        }
        result[x][y] = (comp_merge_num + 1) % 10;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}