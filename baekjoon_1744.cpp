#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int n;
    cin >> n;
    priority_queue<ll> pq_plus;
    priority_queue<ll> pq_minus;
    ll result = 0;
    int zero_count = 0;

    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(temp > 0){
            pq_plus.push(temp);
        }
        else if(temp < 0){
            pq_minus.push(-temp);
        }
        else zero_count += 1;
    }

    while(!pq_plus.empty()){
        ll c1 = pq_plus.top(); pq_plus.pop();
        if(!pq_plus.empty()){
            ll c2 = pq_plus.top(); pq_plus.pop();
            if(c1 * c2 > c1 + c2){
                result += c1 * c2;
            }
            else result += (c1 + c2);
        }
        else{
            result += c1;
            break;
        }
    }
    while(!pq_minus.empty()){
        ll c1 = pq_minus.top(); pq_minus.pop();
        if(!pq_minus.empty()){
            ll c2 = pq_minus.top(); pq_minus.pop();
            result += c1 * c2;
        }
        else{
            if(zero_count <= 0){
                result -= c1;
            }
            else zero_count--;
        }
    }

    cout << result << "\n";
    return 0;
}