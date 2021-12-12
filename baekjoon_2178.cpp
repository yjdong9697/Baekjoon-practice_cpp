#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);

using namespace std;
typedef pair<int, int> pii;

char r[100][100];
int visited[100][100];

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main(void){
    fastio;
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> r[i][j];
        }
    }

    queue<pii> q;
    int result = 1;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while(true){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            pii cur = q.front();
            if(cur == make_pair(n - 1, m - 1)){
                cout << result << "\n";
                return 0;
            }
            visited[cur.first][cur.second] = 1;
            q.pop();
            for(int j = 0; j < 4; j++){
                int x = cur.first + move_x[j];
                int y = cur.second + move_y[j];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                if(!visited[x][y] && r[x][y] == '1'){
                    q.push(make_pair(x, y));
                    visited[x][y] = 1;
                }
            }
        }
        result++;
    }
}