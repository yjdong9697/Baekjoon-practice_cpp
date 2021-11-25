#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    double a, b, c;
    cin >> a >> b >> c;

    double k = (a * a) / (b * b + c * c);
    cout << (int) (sqrt(k) * b) << " " << (int) (sqrt(k) * c) << "\n";
    return 0;
}