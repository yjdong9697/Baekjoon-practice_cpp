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
    int n, m;
    cin >> n >> m;

    vector<pii> edge[n];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
    }
    
    int s, e;
    cin >> s >> e;
    s--, e--;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int cur_cost = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(auto &p : edge[cur]){
            int to = p.first, cost = p.second;
            if(cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                parent[to] = cur;
                pq.push({dist[to], to});
            }
        }
    }

    cout << dist[e] << "\n";

    stack<int> result;
    int cur = e;
    result.push(cur);
    while(cur != s){
        cur = parent[cur];
        result.push(cur);
    }

    cout << result.size() << "\n";

    while(!result.empty()){
        cout << result.top() + 1 << " ";
        result.pop();
    }
    cout << "\n";
    return 0;  
}