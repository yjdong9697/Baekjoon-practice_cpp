#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
const int INF = 1000000000;

//ElogV * V
int main() {
    fastio;
    int n, m, r;
    cin >> n >> m >> r;

    vector<pii> edge[n];
    vector<int> item(n);

    for(int i = 0; i < n; i++){
        cin >> item[i];
    }

    for(int i = 0; i < r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a - 1].push_back({b - 1, c});
        edge[b - 1].push_back({a - 1, c});
    }

    int max_item_num = 0;
    for(int i = 0; i < n; i++){
        int s = i;
        vector<int> dist(n, INF);
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
                    pq.push({dist[to], to});
                }
            }
        }

        int total_item_num = 0;

        for(int j = 0; j < n; j++){
            if(dist[j] <= m){
                total_item_num += item[j];
            }
        }
        max_item_num = max(max_item_num, total_item_num);
    }

    cout << max_item_num << "\n";
    return 0;  
}