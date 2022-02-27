#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int INF = 300000;

int dist[100001];

int main() {
    fastio;
    fill(&dist[0], &dist[100001], INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    int s, e;
    cin >> s >> e;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int cur_cost, cur;
        tie(cur_cost, cur) = pq.top();
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        // teleport
        int to;
        to = cur * 2;
        if(to <= 100000){
            if(cur_cost < dist[to]){
                dist[to] = cur_cost;
                pq.push({cur_cost, to});
            }
        }
        to = cur - 1;
        if(to >= 0){
            if(cur_cost + 1 < dist[to]){
                dist[to] = cur_cost + 1;
                pq.push({cur_cost + 1, to});
            }
        }
        to = cur + 1;
        if(to <= 100000){
            if(cur_cost + 1 < dist[to]){
                dist[to] = cur_cost + 1;
                pq.push({cur_cost + 1, to});
            }
        } 
    }

    cout << dist[e] << "\n";
    return 0;  
}