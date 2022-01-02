#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll to_10(string a){
    ll val = 0;
    for(int i = 0; i < a.size(); i++){
        int cur = a.size() - i - 1;
        if(a[i] == '1'){
            val += (1 << cur);
        }
    }
    return val;
}

string to_2(ll a){
    string temp;
    cin >> temp;
    while(a){
        temp = to_string(a % 2) + temp;
        a /= 2;
    }
    return temp;
}

int main(void){
    fastio;
    string a, b;
    cin >> a >> b;

    ll v_1 = to_10(a);
    ll v_2 = to_10(b);
    cout << to_2(v_1 * v_2) << "\n";
    return 0;
}