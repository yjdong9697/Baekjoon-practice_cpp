#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    vector<int> v(4);
    for(int i = 0; i < 4; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int val1 = v[0] + v[3];
    int val2 = v[1] + v[2];

    cout << abs(val1 - val2) << "\n";
    return 0;
}