#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    fastio;
    int t;
    cin >> t;
    ll bitmask = 0LL;
    while(t--){
        string v;
        cin >> v;
        if(v == "add"){
            int t;
            cin >> t;
            bitmask |= 1 << (t - 1);
        }
        else if(v == "remove"){
            int t;
            cin >> t;
            bitmask &= ~(1 << (t - 1)); 
        }
        else if(v == "check"){
            int t;
            cin >> t;
            if(bitmask & (1 << (t - 1))){
                cout << 1 << "\n";
            }
            else cout << 0 << "\n";
        }
        else if(v == "toggle"){
            int t;
            cin >> t;
            bitmask ^= (1 << (t - 1));
        }
        else if(v == "all"){
            bitmask = (1 << 20) - 1;
        }
        else bitmask = 0;
    }
    return 0;
}