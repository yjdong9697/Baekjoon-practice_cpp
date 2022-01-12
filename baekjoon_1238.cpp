#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const int INF = 2000000000;

int main() {
    fastio;
    int n, m, x;
    cin >> n >> m >> x;
    x--;

    vector<pii> edge[1000];
    for(int i = 0; i < m ;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
    }
    
    vector<int> result(n);
    for(int i = 0; i < n; i++){
        int start = i;
        vector<int> dist(n, INF);
        dist[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({0, start});

        while(!pq.empty()){
            int cur_cost = pq.top().first, cur = pq.top().second;
            pq.pop();
            if(cur == x) continue;
            if(dist[cur] < cur_cost) continue;
            for(auto p : edge[cur]){
                int to = p.first, cost = p.second;
                if(cur_cost + cost < dist[to]){
                    dist[to] = cur_cost + cost;
                    pq.push({dist[to], to});
                }
            } 
        }

        result[start] += dist[x];
    }

    vector<int> dist(n, INF);
    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, x});

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

    for(int i = 0; i < n; i++){
        result[i] += dist[i];
    }

    sort(result.begin(), result.end());
    cout << result.back() << "\n";
    return 0;
}