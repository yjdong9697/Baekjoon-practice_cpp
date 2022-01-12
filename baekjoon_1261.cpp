#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int INF = 20000;


int main() {
    fastio;
    int n, m;
    cin >> m >> n;
    int r[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char t;
            cin >> t;
            r[i][j] = t - '0';
        }
    }

    int dist[100][100];
    fill(&dist[0][0], &dist[99][100], INF);
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
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(cur_cost + r[dx][dy] < dist[dx][dy]){
                dist[dx][dy] = cur_cost + r[dx][dy];
                pq.push({dist[dx][dy], dx, dy});
            }
        }
    }

    cout << dist[n - 1][m - 1] << "\n";
    return 0;
}