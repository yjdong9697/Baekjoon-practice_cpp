#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            ll temp;
            cin >> temp;
            pq.push(temp);
        }

        ll cost = 0;
        
        while(!pq.empty()){
            ll c1 = pq.top(); pq.pop();
            if(!pq.empty()){
                ll c2 = pq.top(); pq.pop();
                cost += c1 + c2;
                pq.push(c1 + c2);
            }
            else{
                break;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}