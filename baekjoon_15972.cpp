#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<tiii> adj[1001][1001];
int dist[1001][1001];
const int INF = 2000000000;

int main() {
    fastio;
    int N, M, H;
    cin >> N >> M >> H;

    // 가로 방향으로 adj 연결
    for(int i = 0; i < N + 1; i++){
        int t;
        if(i == 0){
            for(int j = 1; j <= M; j++){ 
                cin >> t;
                if(t == -1) continue;
                adj[1][j].push_back({0, 0, t});
                adj[0][0].push_back({1, j, t});
            }
        }
        else if(i == N){
            for(int j = 1; j <= M; j++){
                cin >> t;
                if(t == -1) continue;
                adj[N][j].push_back({0, 0, t});
                adj[0][0].push_back({N, j, t});
            }
        }
        else{
            for(int j = 1; j <= M; j++){
                cin >> t;
                if(t == -1) continue;
                adj[i][j].push_back({i + 1, j, t});
                adj[i + 1][j].push_back({i, j, t});
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M + 1; j++){
            int t;
            cin >> t;
            if(t == -1) continue;
            if(j == 0){
                adj[i][1].push_back({0, 0, t});
                adj[0][0].push_back({i, 1, t});
            }
            else if(j == M){
                adj[i][M].push_back({0, 0, t});
                adj[0][0].push_back({i, M, t});

            }
            else{
                adj[i][j].push_back({i, j + 1, t});
                adj[i][j + 1].push_back({i, j, t});
            }
        }
    }

    fill(&dist[0][0], &dist[1000][1001], INF);
    dist[0][0] = 0;
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        int cur_cost, cur_x, cur_y;
        tie(cur_cost, cur_x, cur_y) = pq.top();
        pq.pop();
        if(dist[cur_x][cur_y] < cur_cost) continue;
        for(auto& p : adj[cur_x][cur_y]){
            int to_x, to_y, cost;
            tie(to_x, to_y, cost) = p;
            if(max(cur_cost, cost) < dist[to_x][to_y]){
                dist[to_x][to_y] = max(cur_cost, cost);
                pq.push({dist[to_x][to_y], to_x, to_y});
            }
        }
        if(cur_x == 0 && cur_y == 0){
            dist[0][0] = INF;
        }
    }

    int total = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(dist[i][j] == INF) total += H;
            else total += dist[i][j];
        }
    }

    cout << total << "\n";
    return 0;   
}