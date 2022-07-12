#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int arr[1001][1001];

int main() {
    fastio;
    int n, m;
    queue<pii> ape;
    cin >> m >> n;
    bool zero_check = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int t;
            cin >> t;
            arr[i][j] = t;
            if(arr[i][j] == 1){
                ape.push({i, j});
            }
            else if(arr[i][j] == 0) zero_check = true;
        }
    }
    // Exception handling
    if(!zero_check){
        cout << 0 << "\n";
        return 0;
    }

    int cnt = 0;

    while(!ape.empty()){
        int num = ape.size();
        bool up_flag = false;
        for(int k = 0; k < num; k++){
            int cur_x, cur_y;
            tie(cur_x, cur_y) = ape.front();
            ape.pop();
            for(int i = 0; i < 4; i++){
                int dx = cur_x + move_x[i];
                int dy = cur_y + move_y[i];
                if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                else{
                    if(arr[dx][dy] == 1 || arr[dx][dy] == -1) continue;
                    else{
                        up_flag = true;
                        arr[dx][dy] = 1;
                        ape.push({dx, dy});
                    }
                }
            }
            
        }
        if(up_flag) cnt++;
        
    }
    bool flag = true;

    for(int i = 0; i < n; i++){
        if(!flag) break;
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                flag = false;
                break;
            }
        }
    }

    if(!flag){
        cout << -1 << "\n";
    }
    else{
        cout << cnt << "\n";
    }
    return 0;
}