#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int cross_product(int x1, int y1, int x2, int y2){
    return x1 * y2 - y1 * x2;
}

int main() {
    fastio;
    int x[3];
    int y[3];
    int x_1, y_1, x_2, y_2;
    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }

    x_1 = x[1] - x[0];
    x_2 = x[2] - x[1];
    y_1 = y[1] - y[0];
    y_2 = y[2] - y[1];

    int ret = cross_product(x_1, y_1, x_2, y_2);
    if(ret > 0) cout << 1 << "\n";
    else if(ret < 0) cout << -1 << "\n";
    else cout << 0 << "\n";

    return 0;
}