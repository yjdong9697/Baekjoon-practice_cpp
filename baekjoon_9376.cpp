#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
char MAP[105][105];
int dist[3][105][105];
pii pt[3];
const int INF = 2000000000;

int main() {
    fastio;
    int t;
    cin >> t;
    for(int test_num = 1; test_num <= t; ++test_num){
        fill(&MAP[0][0], &MAP[104][105], '.');
        pt[0] = {0, 0};
        int h, w;
        cin >> h >> w;
        h++, w++; // 강제적으로 1칸씩 밀음
        bool chk = false;
        for(int i = 1; i <= h - 1; i++){
            for(int j = 1; j <= w - 1; j++){
                cin >> MAP[i][j];
                if(MAP[i][j] == '$'){
                    if(!chk){
                        pt[1] = {i, j};
                        chk = true;
                    }
                    else pt[2] = {i, j};
                }
            }
        }
        fill(&dist[0][0][0], &dist[2][104][105], INF);

        for(int l = 0; l < 3; l++){
            int x, y;
            tie(x, y) = pt[l];
            priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
            pq.push({0, x, y});
            dist[l][x][y] = 0;
            while(!pq.empty()){
                int cur_cost, cur_x, cur_y;
                tie(cur_cost, cur_x, cur_y) = pq.top();
                pq.pop();
                if(dist[l][cur_x][cur_y] < cur_cost) continue;
                for(int i = 0; i < 4; i++){
                    int dx = cur_x + move_x[i];
                    int dy = cur_y + move_y[i];
                    if(dx < 0 || dx > h || dy < 0 || dy > w || MAP[dx][dy] == '*') continue;
                    if(cur_cost + ((MAP[dx][dy] == '.') ? 0 : 1) < dist[l][dx][dy]){
                        dist[l][dx][dy] = cur_cost + ((MAP[dx][dy] == '.' || MAP[dx][dy] == '$') ? 0 : 1);
                        pq.push({dist[l][dx][dy], dx, dy});
                    }    
                }
            }
        }
        int ret = INF;
        for(int i = 0; i <= h; i++){
            for(int j = 0; j <= w; j++){
                int val = 0;
                for(int t = 0; t < 3; t++){
                    val += dist[t][i][j];
                }
                if(MAP[i][j] == '#') val -= 2;
                ret = min(ret, val);
            }
        }
        cout << ret << "\n";       
    }
    return 0;
}