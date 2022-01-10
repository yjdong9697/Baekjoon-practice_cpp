#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef tuple<int, int, int> tiii;
typedef long long ll;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const int INF = 500000000;


int main() {
    fastio;
    int n, m, k, s, d;
    cin >> n >> m >> k >> s >> d;
    s--;
    d--;

    vector<pii> edge[n];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
        edge[b - 1].push_back({a - 1, c});
    }

    int dist[1000][1000];
    fill(&dist[0][0], &dist[999][1000], INF);
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq; // cost, point, length
    
    pq.push({0, s, 0});
    dist[s][0] = 0;

    while(!pq.empty()){
        int cur_cost, cur, length;
        tie(cur_cost, cur, length) = pq.top();
        pq.pop();

        if(dist[cur][length] < cur_cost || length >= n) continue; // 제거
        
        for(auto p : edge[cur]){
            int to = p.first, cost = p.second;
            if(cur_cost + cost < dist[to][length + 1]){
                dist[to][length + 1] = cur_cost + cost;
                pq.push({dist[to][length + 1], to, length + 1});
            }  
        }
    }

    int min_num = INF;

    for(int i = 1; i < n; i++){
        min_num = min(min_num, dist[d][i]);
    }
    cout << min_num << "\n";

    int mul = 0;

    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        mul += t;
        min_num = INF;
        for(int j = 1; j < n; j ++){
            min_num = min(min_num, dist[d][j] + mul * j);
        }
        cout << min_num << "\n";
    }
    return 0;
}