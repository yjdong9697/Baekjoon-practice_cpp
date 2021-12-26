#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        double a;
        cin >> a;
        a *= 0.8;

        cout << fixed;
        cout.precision(2);
        cout << "$" << a << "\n";
    }
    return 0;
}