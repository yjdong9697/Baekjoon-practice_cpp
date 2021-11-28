#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int h, m, t;
    cin >> h >> m >> t;
    if(m + t % 60 != 0){
        cout << (h + (m + t) / 60) % 24 << " " << (m + t) % 60 << "\n";
    }
    else{
        cout << (h + (m + t) / 60 + 1) % 24 << " " << (m + t) % 60 << "\n";
    }
    return 0;
}