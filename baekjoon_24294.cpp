#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int w1, h1, w2, h2;

int main(){
    fastio;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << 4 + 2 * max(w1, w2) + 2 * (h1 + h2);
}