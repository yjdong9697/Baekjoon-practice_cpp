#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll N, M;

struct compare{
    bool operator()(pll &temp1, pll &temp2){
        return temp1.second > temp2.second;
    }
};

int main(void){
    fastio;
    cin >> N >> M;
    vector<pll> civil;
    vector<pll> market;
    for(int i = 0; i < N; i++){
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        civil.push_back(make_pair(temp1, temp2));
    }
    for(int i = 0; i < M; i++){
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        market.push_back(make_pair(temp1, temp2));
    }

    sort(civil.begin(), civil.end());
    sort(market.begin(), market.end());

    priority_queue<pll, vector<pll>, compare> pq;

    int current_pos = 0;
    int print_num = 0;

    for(int i = 0; i < M; i++){
        while(current_pos < N && civil[current_pos].first <= market[i].first){
            if(civil[current_pos].second >= market[i].first){
                pq.push(civil[current_pos]);
                current_pos++;
            }
            else current_pos++;
        }
        while(!pq.empty() && market[i].second != 0){
            pll check_value = pq.top();
            pq.pop();
            if(check_value.first <= market[i].first && check_value.second >= market[i].first){
                market[i].second -= 1;
                print_num++;
            }
        }
    }
    cout << print_num << "\n";
    return 0;
}