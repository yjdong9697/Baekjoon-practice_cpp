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

    int n, e;
    cin >> n >> e;
    vector<pii> edge[800];

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        edge[a - 1].push_back({b - 1 , c});
        edge[b - 1].push_back({a - 1, c});
    }

    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;

    tuple<int, int, int> check[3] = {{0, v1, v2},
                       {v1, v2, n - 1},
                       {v2, v1, n - 1}};

    int result[3][2];
    
    for(int i = 0; i < 3; i++){
        int s, to_1, to_2;
        tie(s, to_1, to_2) = check[i];

        int dist[800];
        bool visited[800];
        memset(visited, 0, sizeof(visited));
        fill(dist, dist + 800, INF);
        dist[s] = 0;
        
        priority_queue<pii, vector<pii>, greater<pii> >pq;
        pq.push({0, s});
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

        result[i][0] = dist[to_1];
        result[i][1] = dist[to_2];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            if(result[i][j] == INF){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << min(result[0][0] + result[1][0] + result[2][1], result[0][1] + result[1][1] + result[2][0]) << "\n";
    return 0;    
}