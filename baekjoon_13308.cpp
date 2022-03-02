#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const ll INF = 2e15;

ll dist[2501][2501];
ll liter[2501];
vector<pii> adj[2501]; // to, 거리

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> liter[i];
    }

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    fill(&dist[0][0], &dist[2500][2501], INF);
    dist[1][liter[1]] = 0;
    pq.push({0, 1, liter[1]}); // cost, cur, min_liter
    while(!pq.empty()){
        ll cur_cost, cur, min_litter;
        tie(cur_cost, cur, min_litter) = pq.top();
        pq.pop();
        if(dist[cur][min_litter] < cur_cost) continue;
        for(auto& p : adj[cur]){
            if(cur_cost + min_litter * p.second < dist[p.first][min_litter]){
                dist[p.first][min_litter] = cur_cost + min_litter * p.second;
                pq.push({dist[p.first][min_litter], p.first, min(min_litter, liter[p.first])});
            }
        }
    }
    ll min_value = INF;
    for(int i = 0; i <= 2500; i++){
        min_value = min(min_value, dist[n][i]);
    }
    cout << min_value << "\n";
    return 0; 
}