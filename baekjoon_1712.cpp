#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if(c - b <= 0) cout << "-1\n";
    else cout << a / (c - b) + 1 << "\n";
    return 0;
}