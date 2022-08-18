#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int INF = 1000000000;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int dist[5001];
vector<pii> edge[5001];

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    for(int i = 0; i < 5001; i++){
        sort(edge[i].begin(), edge[i].end());
    }

    int s, e;
    cin >> s >> e;
    fill(&dist[0], &dist[5001], INF);
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int cur_cost, cur;
        tie(cur_cost, cur) = pq.top();
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(auto &p : edge[cur]){
            int to, cost;
            tie(to, cost) = p;
            if(cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                pq.push({dist[to], to});
            }
        }
    }

    cout << dist[e] << "\n";
    return 0;
}