#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int n;
    cin >> n;

    cout << n * 78 / 100 << " " << n * 80 / 100 + n * 20 / 100 * 78 / 100 << "\n";
    return 0;
}