#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    vector<ll> data_store(N, 0);

    for(int i = 0; i < N; i++){
        cin >> data_store[i];
    }
    sort(data_store.begin(), data_store.end());

    ll start = 0;
    ll end = M * data_store.back() + 1;
    while(start < end){
        ll mid = (start + end) / 2;
        ll count = 0;
        for(int i = 0; i < N; i++){
            count += mid / data_store[i];
        }

        if(count < M) start = mid + 1;
        else end = mid;
    }

    cout << end << "\n";
    return 0;
}