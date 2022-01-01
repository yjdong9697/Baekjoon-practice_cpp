#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b;
    cin >> a >> b;
    if(a < 2){
        cout << "Before\n";
    }
    else if(a > 2){
        cout << "After\n";
    }
    else{
        if(b < 18){
            cout << "Before\n";
        }
        else if(b == 18) cout << "Special\n";
        else cout << "After\n";
    }
    return 0;
}