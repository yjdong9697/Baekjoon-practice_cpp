#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int INF = 200000000;

int main() {
    fastio;
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        int s, e;
        cin >> s >> e;

        vector<pii> edge[n];
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
        }

        vector<int> dist(n, INF);
        dist[s] = 0;
        vector<int> parent[n];
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({0, s});
        while(!pq.empty()){
            int cur_cost = pq.top().first, cur = pq.top().second;
            pq.pop();
            if(dist[cur] < cur_cost) continue;
            for(auto p : edge[cur]){
                int to = p.first, cost = p.second;
                if(cur_cost + cost < dist[to]){
                    dist[to] = cur_cost + cost;
                    pq.push({dist[to], to});
                    parent[to].clear();
                    parent[to].push_back(cur);
                }
                else if(cur_cost + cost == dist[to]){
                    parent[to].push_back(cur);
                }
            }
        }
        if(dist[e] == INF){
            cout << -1 << "\n";
            continue;
        }

        queue<int> q;
        q.push(e);
        vector<bool> visited(n, 0);
        visited[e] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto p : parent[cur]){
                for(int i = 0; i < edge[p].size(); i++){
                    if(edge[p][i].first == cur){
                        edge[p].erase(edge[p].begin() + i);
                        break;
                    }   
                }
                if(!visited[p]) q.push(p);
                visited[p] = 1;
            }
        }
        
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        pq.push({0, s});
        while(!pq.empty()){
            int cur_cost = pq.top().first, cur = pq.top().second;
            pq.pop();
            if(dist[cur] < cur_cost) continue;
            for(auto p : edge[cur]){
                int to = p.first, cost = p.second;
                if(cur_cost + cost < dist[to]){
                    dist[to] = cur_cost + cost;
                    pq.push({dist[to], to});
                }
            }
        }

        if(dist[e] == INF){
            cout << -1 << "\n";
        }
        else{
            cout << dist[e] << "\n";
        }
    }
    return 0;
}