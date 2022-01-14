#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};


int main() {
    fastio;
    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        vector<ll> result = {v[i]};
        set<ll> s(v.begin(), v.end());
        for(ll cur = v[i]; result.size() < n; result.push_back(cur)){
            s.erase(cur);
            if(s.count(cur * 2)) cur *= 2;
            else if(cur % 3 == 0 && s.count(cur / 3)) cur /= 3;
            else break; // Not found
        }
        if(result.size() == n){
            for(auto &p : result){
                cout << p << " ";
            }
            cout << "\n";
            return 0;
        }
    }   
}