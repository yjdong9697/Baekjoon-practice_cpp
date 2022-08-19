#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<pii> edge[100000];
bool check[100000];
const ll INF = 20000000000;
ll dist[1000000];

int main() {
    fastio;
    memset(check, 0, sizeof(check));
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> check[i];
    }
    check[n - 1] = 0;

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(check[a] == 0 && check[b] == 0){
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }
    }

    fill(&dist[0], &dist[100000], INF);

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll cur_cost, cur;
        tie(cur_cost, cur) = pq.top();
        pq.pop();

        if(dist[cur] < cur_cost) continue;
        for(auto &p : edge[cur]){
            ll to, cost;
            tie(to, cost) = p;
            if(cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                pq.push({cur_cost + cost, to});
            }
        }
    }

    if(dist[n - 1] == INF) cout << -1 << "\n";
    else cout << dist[n - 1] << "\n";

    return 0;
}