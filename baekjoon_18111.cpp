#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    int n, m, b;
    cin >> n >> m >> b;

    int r[500][500];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> r[i][j];
        }
    }
    int min_cost = INT_MAX;
    int min_height;

    for(int i = 256; i >= 0; --i){
        int height = i;
        int cur_cost = 0;
        int cur_block = b;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                int diff = r[j][k] - height;
                cur_cost += (diff > 0) ? diff * 2 : -diff;
                cur_block += diff;
            }
        }
        if(cur_block < 0) cur_cost = INT_MAX;
        if(cur_cost < min_cost){
            min_cost = cur_cost;
            min_height = height;
        }
    }
    cout << min_cost << " " << min_height << "\n";
    return 0;
}