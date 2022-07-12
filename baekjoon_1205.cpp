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
    int n, value, P;
    cin >> n >> value >> P;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    if(n < P){
        cout << lower_bound(v.begin(), v.end(), value, greater<int>()) - v.begin() + 1 << "\n";
    }
    else{
        if(upper_bound(v.begin(), v.end(), value, greater<int>()) - v.begin() >= P) cout << -1 << "\n";
        else{
            cout << lower_bound(v.begin(), v.end(), value, greater<int>()) - v.begin() + 1 << "\n";
        }
    }
    return 0;
}