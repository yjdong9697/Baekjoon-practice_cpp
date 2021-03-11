#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void){
    fastio;
    int n, k;
    cin >> n >> k;
    vector<pll> data;
    vector<ll> napsack;

    for(int i = 0; i < n; i++){
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        data.push_back(make_pair(temp1, temp2));
    }

    sort(data.begin(), data.end());

    for(int i = 0; i < k; i++){
        ll temp;
        cin >> temp;
        napsack.push_back(temp);
    }
    sort(napsack.begin(), napsack.end());

    ll result = 0;
    int current_index = 0;
    priority_queue<ll> pq;

    for(int i = 0; i < k; i++){
        for(int j = current_index; j < n; j++){
            if(data[j].first <= napsack[i]){
                pq.push(data[j].second);
                current_index++;
            }
            else{
                break;
            }
        }
        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << "\n";
    return 0;
}