#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    int h_1, h_2, h_3;
    cin >> h_3 >> h_2 >> h_1;

    int v_3 = 4 * h_1 + 2 * h_2;
    int v_2 = 2 * h_1 + 2 * h_3;
    int v_1 = 4 * h_3 + 2 * h_2;

    cout << min({v_1, v_2, v_3}) << "\n";
    return 0;
}