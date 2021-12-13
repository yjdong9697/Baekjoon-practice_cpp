#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class point{
    public:
    int z;
    int x;
    int y;
    point(){}
    point(int a, int b, int c){
        z = a;
        x = b;
        y = c;
    }
};

bool r[30][30][30];
bool visited[30][30][30];
int n, m, l;
int move_z[6] = {0, 0, 0, 0, 1, -1};
int move_x[6] = {-1, 1, 0, 0, 0, 0};
int move_y[6] = {0, 0, -1, 1, 0, 0};
point start_p, end_p;

int main(void){
    fastio;
    while(true){
        memset(visited, 0, sizeof(visited));
        cin >> n >> m >> l;
        if(n == 0 && m == 0 && l == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < l; k++){
                    char t;
                    cin >> t;
                    if(t == 'S'){
                        start_p = point(i, j, k);
                        r[i][j][k] = true;
                    }
                    else if(t == 'E'){
                        end_p = point(i, j, k);
                        r[i][j][k] = true;

                    }
                    else if(t == '.') r[i][j][k] = true;
                    else r[i][j][k] = false;
                }
            }
        }

        queue<point> q;
        q.push(start_p);
        visited[start_p.z][start_p.x][start_p.y] = 1;
        int move_num = 0;
        int flag = false;

        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                point cur = q.front();
                if(cur.x== end_p.x && cur.y == end_p.y && cur.z == end_p.z){
                    flag = true;
                    break;
                }
                q.pop();
                int z = cur.z;
                int x = cur.x;
                int y = cur.y;
                for(int j = 0; j < 6; j++){
                    int dz = z + move_z[j];
                    int dx = x + move_x[j];
                    int dy = y + move_y[j];
                    if(dz < 0 || dz >= n || dx < 0 || dx >= m | dy < 0 || dy >= l) continue;
                    else{
                        if(!visited[dz][dx][dy] && r[dz][dx][dy]){
                            q.push(point(dz, dx, dy));
                            visited[dz][dx][dy] = 1;
                        }
                    }
                }

            }
            if(flag) break;
            move_num++;
        }

        if(!flag){
            cout << "Trapped!\n";
        }
        else cout << "Escaped in " << move_num  << " minute(s)."<< "\n";
    }
}