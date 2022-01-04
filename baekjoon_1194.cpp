#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, m;
pii start_point;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
char r[50][50];
bool visited[50][50][1 << 6];

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    set<pii> end_point;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> r[i][j];
            if(r[i][j] == '0'){
                start_point = make_pair(i, j);
            }
            else if(r[i][j] == '1'){
                end_point.insert(make_pair(i, j));
            }
        }
    }

    queue<piii> q;
    q.push(make_pair(start_point, 0));
    visited[start_point.first][start_point.second][0] = 1;
    int move_num = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int key = q.front().second;
            if(end_point.find(q.front().first) != end_point.end()){
                cout << move_num << "\n";
                return 0;
            }
            q.pop();
            for(int j = 0; j < 4; j++){
                int dx = x + move_x[j];
                int dy = y + move_y[j];
                if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                else{
                    if(!visited[dx][dy][key]){
                        if(r[dx][dy] == '.' || r[dx][dy] == '1' || r[dx][dy] == '0'){
                            q.push(make_pair(make_pair(dx, dy), key));
                            visited[dx][dy][key] = 1;
                        }
                        else if(r[dx][dy] == '#') continue;
                        else if (r[dx][dy] >= 'a' && r[dx][dy] <= 'f'){
                            int to = key | (1 << (r[dx][dy] - 'a'));
                            q.push(make_pair(make_pair(dx, dy), to));
                            visited[dx][dy][to] = 1;
                        }
                        else if(r[dx][dy] >= 'A' && r[dx][dy] <= 'F'){
                            if(key & (1 << (r[dx][dy] - 'A'))){
                                q.push(make_pair(make_pair(dx, dy), key));
                                visited[dx][dy][key] = 1;
                            }
                        }

                    }
                }
            }
        }
        move_num++;
    }

    cout << -1 << "\n";
    return 0;
}