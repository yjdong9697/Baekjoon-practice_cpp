#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int MAP[501][501];
int dist[501][501];
const int INF = 300000;

int main() {
    fastio;
    memset(MAP, 0, sizeof(MAP));
    int n, m, x_1, y_1, x_2, y_2;
    cin >> n;
    for(int t = 0; t < n; t++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int i = min(x_1, x_2); i <= max(x_1, x_2); i++)
        {
            for (int j = min(y_1, y_2); j <= max(y_1, y_2); j++)
            {
                MAP[i][j] = 1;
            }
        }
    }
    
    cin >> m;
    for(int t = 0; t < m; t++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int i = min(x_1, x_2); i <= max(x_1, x_2); i++)
        {
            for (int j = min(y_1, y_2); j <= max(y_1, y_2); j++)
            {
                MAP[i][j] = -1;
            }
        }
    }

    fill(&dist[0][0], &dist[500][501], INF);
    dist[0][0] = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        int cur_cost, cur_x, cur_y;
        tie(cur_cost, cur_x, cur_y) = pq.top();
        pq.pop();
        if(dist[cur_x][cur_y] < cur_cost) continue;

        for(int i = 0; i < 4; i++){
            int dx = cur_x + move_x[i];
            int dy = cur_y + move_y[i];
            if(dx < 0 || dx > 500 || dy < 0 || dy > 500) continue;
            if(MAP[dx][dy] == -1) continue; // 갈 수 없는 경우
            if(cur_cost + MAP[dx][dy] < dist[dx][dy]){
                dist[dx][dy] = cur_cost + MAP[dx][dy];
                pq.push({dist[dx][dy], dx, dy});
            }
        }
    }

    if(dist[500][500] == INF){
        cout << -1 << "\n";
    }
    else cout << dist[500][500] << "\n";
    return 0;
}