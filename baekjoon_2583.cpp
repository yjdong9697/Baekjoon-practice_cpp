#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int m, n, k; // m : y, n; x
int r[101][101];
int visited[101][101];
vector<pii> v;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int dfs(int x, int y){
    visited[x][y] = 1;
    int component_num = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        if(!visited[dx][dy] && r[dx][dy] == 0) component_num += dfs(dx, dy);
    }
    return component_num + 1;
}

int main(void){
    fastio;
    memset(r, 0, sizeof(r));
    memset(visited, 0, sizeof(visited));
    cin >> m >> n >> k;

    for(int i = 0; i < k; i++){
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;
        for(int j = s_x; j < e_x; j++){
            for(int k = s_y; k < e_y; k++){
                r[j][k] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!r[i][j]) v.push_back(make_pair(i, j));
        }
    }

    vector<int> component_store;

    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        if(!visited[x][y]) component_store.push_back(dfs(x, y));
    }
    
    sort(component_store.begin(), component_store.end());

    cout << component_store.size() << "\n";

    for(int i = 0; i < component_store.size(); i++){
        cout << component_store[i] << " ";
    }
    cout << "\n";
    return 0;
}