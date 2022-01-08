#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
const int INF = 987654321;

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

    int start, end;
    cin >> start >> end;
    start--;
    end--;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int dist[1000];
    bool visited[1000];
    memset(visited, 0, sizeof(visited));
    fill(dist, dist + 1000, INF);
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int cur = -1;
        while(!pq.empty()){
            if(!visited[pq.top().second]){
                cur = pq.top().second;
                pq.pop();
                break;
            }
            pq.pop();
        }

        if(cur == -1) break;
        visited[cur] = 1;

        for(auto p : edge[cur]){
            int to = p.first, cost = p.second;
            if(dist[cur] + cost < dist[to]){
                dist[to] = dist[cur] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    cout << dist[end] << "\n";
    return 0;
}