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
    int n;
    cin >> n;
    int cnt = 0;
    while(n >= 1){
        if((n & 1) == 1) cnt++;
        n = n >> 1;
    }

    cout << cnt << "\n";
    return 0;
}