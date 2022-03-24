#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c;
    int d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    int z = max(d - a, 0);
    int x = max(e - b, 0);
    int v = max(f - c, 0);
    cout << z + x + v << "\b";
    return 0;
}