#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int a, b, c, d;
    cin >> a >> b >> c;
    cin >> d;
    
    b = (c + d) / 60 + b;
    c = (c + d) % 60;
    a = (a + b / 60) % 24;
    b = b % 60;

    cout << a << " " << b << " " << c;
    return 0;    
}