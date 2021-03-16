#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef unsigned long long ll;

int main(void){
    fastio;
    ll n;
    cin >> n;
    ll start = 0;
    ll end = 4294967296LL;

    while(start < end){
        ll mid = (start + end) / 2;
        ll compare = mid * mid;
        if(compare < n){
            start = mid + 1;
        }
        else end = mid;
    }

    cout << start << "\n";
    return 0;
}