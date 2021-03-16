#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<ll> data;
    
    for(int i = 0; i < m; i++){
        ll temp;
        cin >> temp;
        data.push_back(temp);
    }

    ll start = 1;
    ll end = 1000000000;

    while(start < end){
        ll mid = (start + end) / 2;
        ll count = 0;
        for(int i = 0; i < m; i++){
            if(data[i] % mid == 0){
                count += data[i] / mid;
            }
            else count += (data[i] / mid) + 1;
        }
        if(count > n){
            start = mid + 1;
        }
        else end = mid;
    }

    cout << start << "\n";
    return 0;
}