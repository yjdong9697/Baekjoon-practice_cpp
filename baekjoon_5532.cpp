#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int v1 = (a / c) + (a % c != 0);
    int v2 = (b / d) + (b % d != 0);
    
    cout << l - max(v1, v2) << "\n";
    return 0;
}