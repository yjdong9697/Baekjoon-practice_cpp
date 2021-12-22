#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int a, b, c, d;
    int e, f, g, h;

    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;

    cout << max (a + b  + c + d, e + f + g + h) << "\n";
    return 0;
}