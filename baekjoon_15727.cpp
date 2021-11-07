#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    int n;
    cin >> n;
    cout << n / 5 + (n % 5 > 0) << "\n";
    return 0;
}