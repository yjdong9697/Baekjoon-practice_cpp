#include <bits/stdc++.h>
using namespace std;

int main(){
    double x;
    cin >> x;
    cout << fixed;
    cout.precision(6);
    double ans = 100.0 / ((1.609344 / 3.785411784) * x);
    cout << ans << "\n";
}