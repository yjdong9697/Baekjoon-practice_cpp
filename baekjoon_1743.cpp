#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

int n, m, k;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int visited[101][101];
int v[101][101];
vector<pii> store;



int dfs(int x, int y){
    visited[x][y] = 1;
    int member = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx > n || dy < 0 || dy > m) continue;
        else{
            if(!visited[dx][dy] && v[dx][dy] == 1){
                member += dfs(dx, dy);
            }
        }
    }
    return member + 1;
    

}

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    memset(v, 0, sizeof(v));
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        store.push_back(make_pair(a, b));
    }

    int result = 0;
    for(int i = 0; i < k; i++){
        int x = store[i].first;
        int y = store[i].second;
        if(!visited[x][y]){
            result = max(result, dfs(x, y));
        }
    }
    cout << result << "\n";
    return 0;
}