#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main() {
    fastio;
    ll n, d;
    cin >> n >> d;

    vector<ll> v;
    for(int i = 0; i < d; i++){
        v.push_back(i);
    }

    vector<ll> result;

    do{
        ll value = 0;
        ll idx = 0;
        if(*prev(v.end()) == 0) continue;
        for(auto it = v.begin(); it != v.end(); ++it){
            value += *it * pow(d, idx++);
        }
        result.push_back(value);
    }while(next_permutation(v.begin(), v.end()));

    sort(result.begin(), result.end());

    if(upper_bound(result.begin(), result.end(), n) != result.end()){
        cout << *upper_bound(result.begin(), result.end(), n) << "\n";
    }
    else cout << -1 << "\n";

    return 0;
}