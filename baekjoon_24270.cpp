#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

const ll MOD = 1000000007;

int main() {
    fastio;
    ll n, k;
    cin >> n >> k;
    
    ll total_sum = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        total_sum += t;
    }

    ll remain = k - total_sum;

    ll result = 1;

    for(ll i = 1LL; i <= n; i++){
        result *= (remain + i);
        result %= MOD;
    }
    cout << result << "\n";
    return 0;
}