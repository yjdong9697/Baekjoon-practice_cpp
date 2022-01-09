#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, int> plli;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const ll INF = 2000000000;

int main() {
    fastio;
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<pill> edge[1000];

    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        edge[a - 1].push_back({b - 1, c});
    }

    priority_queue<ll, vector<ll> > dist[1000];
    priority_queue<plli, vector<plli>, greater<plli> > pq;


    pq.push({0, 0});
    dist[0].push(0);
    
    while(!pq.empty()){
        ll cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(auto p : edge[cur]){
            int to = p.first;
            ll cost = p.second;
            if(dist[to].size() < k){
                dist[to].push(cur_cost + cost);
                pq.push({cur_cost + cost, to});
            }
            else if(dist[to].top() > cur_cost + cost){
                dist[to].pop();
                dist[to].push(cur_cost + cost);
                pq.push({cur_cost + cost, to});
            }   
        }
    }

    for(int i = 0; i < n; i++){
        if(dist[i].size() != k){
            cout << -1 << "\n";
        }
        else cout << dist[i].top() << "\n";
    }
    return 0;
}