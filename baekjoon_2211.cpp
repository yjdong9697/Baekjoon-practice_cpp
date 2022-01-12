#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int INF = 20000;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<pii> edge[n];

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
        edge[b - 1].push_back({a - 1, c});
    }

    int parent[1000];
    int dist[1000];
    fill(dist, dist + 1000, INF);
    dist[0] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int cur_cost = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(auto p : edge[cur]){
            int to = p.first, cost = p.second;
            if(cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                parent[to] = cur;
                pq.push({dist[to], to});
            }
        } 
    }

    vector<pii> create_edge;
    for(int i = 1; i < n; i++){
        int cur = i;
        while(cur != 0){
            int to = parent[cur];
            create_edge.push_back({max(cur, to), min(cur, to)});
            cur = to;
        }
    }

    sort(create_edge.begin(), create_edge.end());

    create_edge.erase(unique(create_edge.begin(), create_edge.end()), create_edge.end());
    
    cout << create_edge.size() << "\n";
    for(auto p : create_edge){
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}