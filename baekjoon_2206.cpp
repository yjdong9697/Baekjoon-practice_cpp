#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

class point{
    public:
    int z, x, y;
    point(){};
    point(int a, int b, int c) : z(a), x(b), y(c)
    {}
};

bool r[1000][1000];
int visited[1000][1000][2];
int n, m;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main(void){
    memset(visited, 0, sizeof(visited));
    fastio;

    cin >> n >> m;

    // Exception handling
    if(n == 1 && m == 1){
        cout << 1 << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char t;
            cin >> t;
            r[i][j] = t - '0';
        }
    }

    queue<point> q;
    q.push(point(0, 0, 0));
    visited[0][0][0] = 1;

    int move_val = 1;

    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            // Reach end point
            if (q.front().x == n - 1 && q.front().y == m - 1){
                cout << move_val << "\n";
                return 0;
            }
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();
            for(int j = 0; j < 4; j++){
                int dx = x + move_x[j];
                int dy = y + move_y[j];
                if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                if(!visited[dx][dy][z]){
                    if(r[dx][dy] == 1 && z == 0){
                        if(visited[dx][dy][1]) continue;
                        q.push(point(1, dx, dy));
                        visited[dx][dy][1] = 1;
                    }
                    else if(r[dx][dy] == 0){
                        q.push(point(z, dx, dy));
                        visited[dx][dy][z] = 1;
                    }
                }
            }

        }
        move_val++;
    }

    // No case exist
    cout << "-1\n";
    return 0;    
}