#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int dist[50001];
vector<pii> edge[50001];
const int INF = 2000000000;

int main() {
    fastio;
    fill(dist, dist + 50001, INF);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int cur_cost, cur;
        tie(cur_cost, cur) = pq.top();
        pq.pop();
        if(cur_cost > dist[cur]) continue;
        for(auto& t : edge[cur]){
            int to, cost;
            tie(to, cost) = t;
            if(cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                pq.push({dist[to], to});
            }
        }
    }
    cout << dist[n] << "\n";
    return 0;
}