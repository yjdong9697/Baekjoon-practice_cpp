#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int main(void){
    ll a, b;
    cin >> a >> b;
    cout << max(a, b) - min(a, b) << "\n";
    return 0;
}