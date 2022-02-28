#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int MAP[300][300];
int visited[300][300];
int n, m;

priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
int ret = 0;
void dfs(int x, int y, int height){
    for(int i = 0; i < 4; i++){
        int dx = x + move_x[i];
        int dy = y + move_y[i];
        if(dx < 0 || dx >= n || dy < 0 || dy >= m || visited[dx][dy]) continue;
        visited[dx][dy] = 1;
        if(height < MAP[dx][dy]) pq.push({MAP[dx][dy], dx, dy});
        else{
            ret += height - MAP[dx][dy];
            dfs(dx, dy, height);
        }
    }
}
int main() {
    fastio;
    memset(visited, 0, sizeof(visited));
    // 만약 모서리에 해당하는 높이가 안쪽의 최소높이보다 작다면 흘러내림
    
    cin >> m >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> MAP[i][j];
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                pq.push({MAP[i][j], i, j});
                visited[i][j] = 1;
            }
        }
    }

    while(!pq.empty()){
        int cur_height, cur_x, cur_y;
        tie(cur_height, cur_x, cur_y) = pq.top();
        pq.pop();
        dfs(cur_x, cur_y, cur_height);
    }
    cout << ret << "\n";
    return 0;
}