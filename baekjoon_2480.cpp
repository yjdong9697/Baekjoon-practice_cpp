#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << 10000 + a * 1000 << "\n";

    }
    else if(a == b || b == c || a == c){
        if(a == b){
            cout << 1000 + a * 100 << "\n";
        }
        else if(b == c){
            cout << 1000 + b * 100 << "\n";
        }
        else{
            cout << 1000 + a * 100 << "\n";
        }
    }
    else{
        cout << max(a, max(b, c)) * 100 << "\n";
    }
    return 0;
}