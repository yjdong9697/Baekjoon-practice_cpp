#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
vector<pii> edge[11];
int dist[11];
const int INF = 2000000000;


int main() {
    fastio;
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    for(int i = 0; i < m; i++){
        int l, m, n;
        cin >> l >> m >> n;
        edge[l].push_back({m, n});
        edge[m].push_back({l, n});
    }

    fill(&dist[0], &dist[11], INF);
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, a, 0});
    dist[a] = 0;

    while(!pq.empty()){
        int max_cost, cur, cost;
        tie(max_cost, cur, cost) = pq.top();
        pq.pop();
        if(dist[cur] < max_cost) continue;
        for(auto &p : edge[cur]){
            int to, to_cost;
            tie(to, to_cost);
        }
    }



    
    
}