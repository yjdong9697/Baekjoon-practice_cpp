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
    ll t;
    cin >> t;
    double a = sqrt(t);
    cout << fixed;
    cout.precision(6);
    cout << 4 * a << "\n";
    return 0;
}