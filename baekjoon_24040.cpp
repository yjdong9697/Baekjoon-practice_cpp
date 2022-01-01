#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        if(a % 3 == 0){
            if((a / 3) % 3 == 0){
                cout << "TAK\n";
            }
            else cout << "NIE\n";
        }
        else{
            if(a % 3 == 2){
                cout << "TAK\n";
            }
            else cout << "NIE\n";
        }
    }
    return 0;
}