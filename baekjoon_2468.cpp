#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n;
int r[100][100];
int visited[100][100];
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cmp){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
        if(!visited[dx][dy] && r[dx][dy] > cmp) dfs(dx, dy, cmp);
    }
    return;
}

int main(void){
    fastio;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> r[i][j];
        }
    }

    int result = 0;

    for(int i = 0; i <= 100; i++){
        memset(visited, 0, sizeof(visited));
        int cur_result = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(!visited[j][k] && r[j][k] > i){
                    dfs(j, k, i);
                    cur_result++;
                }
            }
        }
        result = max(result, cur_result);
    }

    cout << result << "\n";
    return 0;
}