#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, int> plli;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const ll INF = 1e13;

int main() {
    fastio;
    int n, m;
    ll d, e;
    cin >> n >> m >> d >> e;
    vector<ll> result(n);
    vector<ll> height(n);

    // Exception handling
    if(n == 2){
        cout << "Impossible\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        cin >> result[i];
        height[i] = result[i];
        result[i] *= e;
    }

    vector<pill> edge[n];
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
        edge[b - 1].push_back({a - 1, c});
    }

    // Dijkstra first
    vector<ll> dist(n, INF);
    dist[0] = 0LL;
    priority_queue<plli, vector<plli>, greater<plli> > pq;
    pq.push({0LL, 0});

    while(!pq.empty()){
        ll cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(auto p : edge[cur]){
            int to = p.first;
            ll cost = p.second;
            if(height[cur] < height[to] && cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                pq.push({dist[to], to});
            }
        }
    }

    vector<bool> flag(n, true);
    bool total_flag = false;
    for(int i = 1; i < n - 1; i++){
        if(flag[i] && dist[i] != INF){
            result[i] -= dist[i] * d;
            total_flag = true;
        }
        else flag[i] = false;
    }
    if(!total_flag){
        cout << "Impossible\n";
        return 0;
    }

    // Dijkstra second
    fill(dist.begin(), dist.end(), INF);
    dist[n - 1] = 0;
    pq.push({0LL, n - 1});
    while(!pq.empty()){
        ll cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cur_cost) continue;
        for(auto p : edge[cur]){
            int to = p.first;
            ll cost = p.second;
            if(height[cur] < height[to] && cur_cost + cost < dist[to]){
                dist[to] = cur_cost + cost;
                pq.push({dist[to], to});
            }
        }
    }

    total_flag = false;
    for(int i = 1; i < n - 1; i++){
        if(flag[i] && dist[i] != INF){
            result[i] -= dist[i] * d;
            total_flag = true;
        }
        else flag[i] = false;
    }
    if(!total_flag){
        cout << "Impossible\n";
        return 0;
    }

    ll max_num = -(1e13);
    for(int i = 1; i < n - 1; i++){
        if(flag[i]){
            max_num = max(max_num, result[i]);
        }
    }
    cout << max_num << "\n";
    return 0;
}