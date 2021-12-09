#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int m, n;

int edge[51][51];
int visited[51][51];
vector<pii> node;

void dfs(int x_val, int y_val){
    visited[x_val][y_val] = 1;
    for(int i = 0; i < 4; i++){
        int x = x_val + dx[i];
        int y = y_val + dy[i];
        if(x < 0 || x > m || y < 0 || y > n) continue;
        if(!visited[x][y] && edge[x][y] == 1) dfs(x, y);
    }
    return;
}

int main(void){
    fastio;
    int t;
    cin >> t;

    while(t--){
        memset(edge, 0, sizeof(edge));
        memset(visited, 0, sizeof(visited));
        node.clear();
        int k;
        cin >> m >> n >> k;

        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            edge[x][y] = 1;
            node.push_back(make_pair(x, y));
        }

        int component = 0;
        for(int i = 0; i < node.size(); i++){
            int cur_x = node[i].first;
            int cur_y = node[i].second;
            if(!visited[cur_x][cur_y]){
                dfs(cur_x, cur_y);
                component++;
            }
            
        }
        cout << component << "\n";
    }
    return 0;
}