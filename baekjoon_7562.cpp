#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;
int r[300][300];
bool visited[300][300];

int move_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int move_y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        memset(r, 0, sizeof(r));
        memset(visited, 0, sizeof(visited));
        int move_num = 0;
        queue<pii> q;
        bool flag = false;
        int n;
        cin >> n;

        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y;
        cin >> e_x >> e_y;

        if(s_x == e_x && s_y == e_y){
            cout << 0 << "\n";
            continue;
        }

        q.push(make_pair(s_x, s_y));
        visited[s_x][s_y] = 1;

        while(true){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int x = q.front().first;
                int y = q.front().second;
                if(x == e_x && y == e_y){
                    flag = true;
                    break;
                }
                q.pop();
                for(int i = 0; i < 8; i++){
                    int dx = x + move_x[i];
                    int dy = y + move_y[i];
                    if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                    else{
                        if(!visited[dx][dy]){
                            q.push(make_pair(dx, dy));
                            visited[dx][dy] = 1;
                        }
                    }

                }
            }
            if(flag) break;
            else move_num++;
        }
        cout << move_num << "\n";
    }
    return 0;
}