#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll M, N;
    cin >> M >> N;

    vector<ll> data_store;

    for(int i = 0; i < N; i++){
        ll temp;
        cin >> temp;
        data_store.push_back(temp);
    }

    sort(data_store.begin(), data_store.end(), greater<ll>());

    ll start = 0;
    ll end = 10000000000000008LL;

    while(start < end){
        ll mid = (start + end) / 2;
        ll check_num = 0;

        if(mid == 0) break;

        for(int i = 0; i < N; i++){
            check_num += data_store[i] / mid;
        }

        // 덜 짤린 것(길이를 줄여야함)
        if(check_num < M){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }

    if(start != end) cout << 0 << "\n";
    else cout << end - 1 << "\n";
    return 0;
}