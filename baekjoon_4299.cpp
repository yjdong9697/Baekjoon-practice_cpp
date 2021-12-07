#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b;
    cin >> a >> b;

    if(a < b){
        cout << -1 << "\n";
        return 0;
    }

    int v1 = (a + b);
    int v2 = (a - b);
    if(v1 % 2 == 1 || v2 % 2 == 1){
        cout << -1 << "\n";
        return 0;
    }
    else{
        cout << max(v1 / 2, v2 / 2) << " " << min(v1 / 2, v2 / 2) << "\n";
        return 0;
    }
}