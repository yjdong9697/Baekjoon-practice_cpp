#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<ll, ll> pll;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const ll INF = 1e18;

int main() {
    fastio;
    bool visited[50000][2];
    memset(visited, 0, sizeof(visited));
    ll n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    
    vector<pii> adj[50000][2];

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][0].push_back({b, c});
        adj[b][0].push_back({a, c});
        adj[a][1].push_back({b + 50000, c});
        adj[b][1].push_back({a + 50000, c});
    }

    for(int i = 0; i < f; i++){
        ll a, b;
        cin >> a >> b;
        adj[a][0].push_back({b + 50000, 0});
    }

    ll dist[50000][2];
    fill(dist[0], dist[0] + 100000, INF);
    priority_queue<plli, vector<plli>, greater<> > pq;
    dist[s][0] = 0;
    pq.push({0, s});
    
    while(!pq.empty()){
        int cur = -1;
        while(!pq.empty()){
            if(!visited[pq.top().second % 50000][pq.top().second / 50000]){
                cur = pq.top().second;
                pq.pop();
                break;
            }
            pq.pop();
        }
        if(cur == -1) break; // pq is empty
        int cur_status = cur / 50000;
        cur %= 50000;
        visited[cur][cur_status] = 1;

        for(auto &p : adj[cur][cur_status]){
            int next = p.first % 50000, next_status = p.first / 50000;
            ll d = p.second;       
            if(dist[cur][cur_status] + d < dist[next][next_status]){
                dist[next][next_status] = dist[cur][cur_status] + d;
                pq.push({dist[next][next_status], p.first});
            }
        }
    }
    cout << min(dist[t][0], dist[t][1]) << "\n";
    return 0;
}