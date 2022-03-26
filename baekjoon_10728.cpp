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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int ret = 0;
        if(n >= 2) ret += 2;
        else{
            cout << 1 << "\n";
            cout << 1 << "\n";
            continue;
        }
        ret += (n / 4);
        cout << ret << "\n";
        cout << 1 << " " << 2 << " ";
        for(int i = 1; i <= n / 4; i++){
            cout << i * 4 << " ";
        }
        cout << "\n";
    }
    return 0;
}