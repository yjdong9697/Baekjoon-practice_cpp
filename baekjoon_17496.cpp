#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int n, t, c, p;
    cin >> n >> t >> c >> p;
    cout << ((n - 1) / t) * c * p << "\n";
    return 0;
}