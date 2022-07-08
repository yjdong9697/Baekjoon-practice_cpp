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
    ll n, k;
    cin >> n >> k;

    ll start = 0;
    ll end = 20000000000;

    while(start + 1 < end){
        ll mid = (start + end) >> 1;
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += min(mid / i, n);
        }
        if(cnt < k) start = mid;
        else end = mid;
    }

    cout << end << "\n";
    return 0;
}