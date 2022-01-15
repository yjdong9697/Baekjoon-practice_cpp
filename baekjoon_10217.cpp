#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

const int INF = 100000000;


int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<tiii> edge[100];
        for(int i = 0; i < k; i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            edge[a - 1].push_back({b - 1, c, d});
        }

        int dist[100][10001]; // 간선 넘버, 지원 비용
        fill(&dist[0][0], &dist[99][10001], INF);
        dist[0][0] = 0;
        priority_queue<tiii, vector<tiii>, greater<tiii> > pq; // 소요 시간, 간선 넘버, 지원비용
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int cur_cost, cur, cur_supply;
            tie(cur_cost, cur, cur_supply) = pq.top();
            pq.pop();
            if(dist[cur][cur_supply] < cur_cost) continue;
            for(auto &p : edge[cur]){
                int to, supply, cost;
                tie(to, supply, cost) = p;
                if(cur_supply + supply <= m && cur_cost + cost < dist[to][cur_supply + supply]){
                    dist[to][cur_supply + supply] = cur_cost + cost;
                    pq.push({dist[to][cur_supply + supply], to, cur_supply + supply});
                }
            }
        }

        int min_time = INF;

        for(int i = 0; i <= m; i++){
            min_time = min(min_time, dist[n - 1][i]);
        }
        if(min_time == INF){
            cout << "Poor KCM\n";
        }
        else cout << min_time << "\n";
    }
    return 0;
}