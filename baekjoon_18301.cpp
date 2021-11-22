#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a + 1) * (b + 1)) / (c + 1) - 1 << "\n";
    return 0;
}