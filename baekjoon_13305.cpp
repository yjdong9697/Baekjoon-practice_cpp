#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int n;
    cin >> n;
    queue<ll> d;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 0; i < n - 1; i++){
        ll temp;
        cin >> temp;
        d.push(temp);
    }

    ll min_cost = 0;

    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(i == n - 1) continue;
        pq.push(temp);
        
        ll cur_d = d.front(); d.pop();

        min_cost += cur_d * pq.top();
    }

    cout << min_cost << "\n";
    return 0;
}