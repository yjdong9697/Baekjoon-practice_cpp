#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
map<ll, ll> s;
ll n, p, q;

ll s_value(ll v){
    if(s.find(v) == s.end()) return s[v] = s_value(v / p) + s_value(v / q);
    else return s.find(v) -> second;
}

int main(void){
    fastio;
    cin >> n >> p >> q;
    s[0] = 1; // Default value
    cout << s_value(n) << "\n";
    return 0;
}