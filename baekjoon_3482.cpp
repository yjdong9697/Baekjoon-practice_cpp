#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> ii;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
bool r[1000][1000];
bool visited[1000][1000];
int n, m;

int max_depth;
ii end_point;

int dfs(int x, int y, int result){
    visited[x][y] = 1;
    int move_num = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
        else{
            if(!visited[dx][dy] && r[dx][dy]) move_num = max(move_num, dfs(dx, dy, result + 1) + 1);
        }
    }
    if(result > max_depth){
        end_point = make_pair(x, y);
        max_depth = result;
    }
    return move_num;
}


int main(void){
    fastio;
    int t;
    cin >> t;

    while(t--){
        memset(r, 0, sizeof(r));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n;

        ii start;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char t;
                cin >> t;
                if(t == '.'){
                    r[i][j] = true;
                    start = make_pair(i, j);
                }
            }
        }
        max_depth = 0;
        dfs(start.first, start.second, 0);
        memset(visited, 0, sizeof(visited));
        cout << "Maximum rope length is " << dfs(end_point.first, end_point.second, 0) << ".\n";
    }
    return 0;
}