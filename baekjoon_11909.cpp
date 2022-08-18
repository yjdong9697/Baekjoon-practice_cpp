#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int, int, int, int>;

int move_x[2] = {1, 0};
int move_y[2] = {0, 1};
int w[2222][2222];
int dist[2222][2222];
int INF = 2000000000;

int main() {
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }
    
    fill(&dist[0][0], &dist[2221][2222], INF);
    dist[0][0] = 0;

    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        int cur_cost, x, y;
        tie(cur_cost, x, y) = pq.top();
        pq.pop();
        if(dist[x][y] < cur_cost) continue;
        for(int i = 0; i < 2; i++){
            int dx = x + move_x[i];
            int dy = y + move_y[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if(w[dx][dy] < w[x][y]){
                if(cur_cost < dist[dx][dy]){
                    pq.push({cur_cost, dx, dy});
                    dist[dx][dy] = cur_cost;
                }
            }
            else{
                if(cur_cost + w[dx][dy] - w[x][y] + 1 < dist[dx][dy]){
                    pq.push({cur_cost + w[dx][dy] - w[x][y] + 1, dx, dy});
                    dist[dx][dy] = cur_cost + w[dx][dy] - w[x][y] + 1;
                }
            }
        }
    }

    cout << dist[n - 1][n - 1] << "\n";
    
    return 0;
}