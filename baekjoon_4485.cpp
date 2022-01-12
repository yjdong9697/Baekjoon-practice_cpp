#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
typedef tuple<int, int, int> tiii;
const int INF = INT_MAX;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    int t = 1;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        int dist[125][125];
        fill(&dist[0][0], &dist[125][125], INF);
        int charge[125][125];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> charge[i][j];
            }
        }
        dist[0][0] = charge[0][0];
        priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
        pq.push({dist[0][0], 0, 0});
        while(!pq.empty()){
            int cur_cost, cur_x, cur_y;
            tie(cur_cost, cur_x, cur_y) = pq.top();
            pq.pop();
            if(dist[cur_x][cur_y] < cur_cost) continue;

            for(int i = 0; i < 4; i++){
                int dx = cur_x + move_x[i];
                int dy = cur_y + move_y[i];
                if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                if(cur_cost + charge[dx][dy] < dist[dx][dy]){
                    dist[dx][dy] = cur_cost + charge[dx][dy];
                    pq.push({dist[dx][dy], dx, dy});
                }
            }
        } 
        cout << "Problem " << t++ << ": " << dist[n - 1][n - 1] << "\n";
    }
    return 0;  
}