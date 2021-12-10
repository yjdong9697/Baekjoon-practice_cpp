#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
// 0 : red, 1 : blue, 2 : green

int r[101][101];
int visited[101][101];
int n;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

void dfs_normal(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
        if(!visited[dx][dy] && r[x][y] == r[dx][dy]) dfs_normal(dx, dy); 
    }
    return;
}

void dfs_disease(int x, int y)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if (dx < 0 || dx >= n || dy < 0 || dy >= n)
            continue;
        if (!visited[dx][dy] && ((r[x][y] % 2) == (r[dx][dy] % 2)))
            dfs_disease(dx, dy);
    }
    return;
}

int main(void){
    fastio;
    memset(visited, 0, sizeof(r));

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char cmp;
            cin >> cmp;
            if(cmp == 'R') r[i][j] = 0;
            else if(cmp == 'B') r[i][j] = 1;
            else r[i][j] = 2;
        }
    }

    int normal_component = 0;
    int disease_component = 0;

    // Normal component calculation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs_normal(i, j);
                normal_component++;
            }
        }
    }

    // Disease component calculation
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs_disease(i, j);
                disease_component++;
            }
        }
    }
    cout << normal_component << " " << disease_component << "\n";
    return 0;
}