#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    
    if(e <= c){
        cout << min(b, a * e) << "\n";
    }
    else{
        cout << min(a * e , b + (e - c) * d) << "\n";
    }
    return 0;
}