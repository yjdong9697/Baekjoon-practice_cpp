#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void){
    fastio;
    queue<pll> data_store;
    int a, b;
    cin >> a >> b;
    data_store.push(make_pair(a, 0));

    while(data_store.size() != 0){
        pll check_value = data_store.front();
        data_store.pop();

        if(check_value.first == b){
            cout << check_value.second + 1 << "\n";
            return 0;
        }
        else if(check_value.first > b) continue;

        data_store.push(make_pair(check_value.first * 2, check_value.second + 1));
        data_store.push(make_pair(check_value.first * 10 + 1, check_value.second + 1));
    }

    cout << "-1\n";

    return 0;
}