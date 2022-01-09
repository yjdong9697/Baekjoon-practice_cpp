#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, int> plli;
typedef tuple<ll, int, int> T;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const ll INF = 50000000001;


int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pill> edge[n];

    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1 , c});
        edge[b - 1].push_back({a - 1 , c});
    }

    ll dist[10000][21];
    bool visited[10000][21];
    fill(&dist[0][0], &dist[9999][21], INF);
    memset(visited, 0, sizeof(visited));
    priority_queue<T, vector<T>, greater<T> > pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()){
        int city = -1;
        int step = -1;
        while(!pq.empty()){
            if(!visited[get<1>(pq.top())][get<2>(pq.top())]){
                city = get<1>(pq.top());
                step = get<2>(pq.top());
                pq.pop();
                break;
            }
            pq.pop();
        }
        if(city == -1 && step == -1) break;
        visited[city][step] = 1;

        for(auto p : edge[city]){
            int to = p.first;
            ll cost = p.second;
            if(dist[city][step] + cost < dist[to][step]){
                dist[to][step] = dist[city][step] + cost;
                pq.push({dist[to][step], to, step});
            }
            if(step < k){
                if(dist[city][step] < dist[to][step + 1]){
                    dist[to][step + 1] = dist[city][step];
                    pq.push({dist[to][step + 1], to, step + 1});
                }
            }
        }
    }

    ll min_num = INF;

    for(int i = 0; i <= k; i++){
        min_num = min(dist[n - 1][i], min_num);
    }

    cout << min_num << "\n";
    return 0;
}