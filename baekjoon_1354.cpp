#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

unordered_map<ll, ll> s;

ll n, p, q, x, y;

ll s_value(ll v){
    if(v <= 0) return 1;
    if(s[v]) return s[v];
    else return s[v] = s_value(v / p - x) + s_value(v / q - y);
}

int main(void){
    fastio;
    cin >> n >> p >> q >> x >> y;
    cout << s_value(n) << "\n";

    return 0;
}